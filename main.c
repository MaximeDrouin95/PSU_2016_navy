/*
** main.c for navy in /home/alkoleek/PSU_2016_navy
** 
** Made by Maxime DROUIN
** Login   <maxime.drouin@epitech.eu>
** 
** Started on  Tue Feb  7 03:13:23 2017 Maxime DROUIN
** Last update Mon Feb 13 21:47:34 2017 Maxime DROUIN
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include "my.h"

t_navy g_navy = {.pid = 0, .loc = 0, .turn = 0, .hit = 0, .connect = 0};

int     init(int ac, char **av)
{
  if (ac == 2)
    return (server_connect(ac, av));
  else if (ac == 3 && my_str_isnum(av[1]) == 1)
    return (client_connect(ac, av));
  else
    {
      help();
      return (84);
    }
}

int	navy_exec(char ***map, char ***emap, int ac, char **av)
{
  int	i;

  i = 0;
  if (g_navy.turn == 1)
    {
      i = attack(map, emap);
      if (ac == 3 && g_navy.turn == 0)
	print_tab((*map), (*emap));
    }
  else if (g_navy.turn == 0)
    {
      i = ennemy_attack(map, emap);
      if (ac == 2 && g_navy.turn == 1)
	print_tab((*map), (*emap));
    }
  g_navy.loc = 0;
  return (i);
}

int	initialization(int ac, char **av, const int fd)
{
  if (ac > 3)
    {
      my_putstr("Error: too much arguments\n");
      return (84);
    }
  if (fd == -1 && my_strcmp(av[1], "-h") != 0)
    {
      my_putstr("Error: file not found\n");
      return (84);
    }
  if ((ac == 2 && my_strcmp(av[1], "-h") == 0) || ac == 1)
    {
      help();
      return (84);
    }
  return (0);
}

int	navy_start(int ac, char **av, char ***map)
{
  int	fd;
  int	i;

  fd = open(av[ac - 1], O_RDONLY);
  if (initialization(ac, av, fd) != 0)
    return (84);
  if (((*map) = put_ship((*map), fd)) == NULL)
    return (84);
  if (init(ac, av) != 0)
    return (84);
  close(fd);
  return (0);
}

int	main(int ac, char **av)
{
  char	**map;
  char	**emap;
  int	i;

  if ((map = load_map("defaultmap")) == NULL)
    return (load_error());
  if ((emap = load_map("defaultmap")) == NULL)
    return (load_error());
  if (navy_start(ac, av, &map) != 0)
    return (84);
  print_tab(map, emap);
  while (42)
    {
      if ((i = navy_exec(&map, &emap, ac, av)) != 0)
	{
	  if (i == -1)
	    return (print_win());
	  else
	    return (i);
	}
    }
}
