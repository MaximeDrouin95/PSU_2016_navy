/*
** printer.c for printer in /home/alkoleek/INTHENAVY/PSU_2016_navy
** 
** Made by Maxime DROUIN
** Login   <alkoleek@epitech.net>
** 
** Started on  Mon Feb  6 14:30:08 2017 Maxime DROUIN
** Last update Mon Feb 13 21:31:17 2017 Maxime DROUIN
*/

#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"

void    print_tab(char **map, char **emap)
{
  my_putstr("my positions:\n");
  my_showtab(map);
  my_putstr("enemy's positions:\n");
  my_showtab(emap);
}

int    print_win()
{
  if (g_navy.turn == -1)
    {
      my_putstr("I won\n");
      return (0);
    }
  else
    {
      my_putstr("Enemy won\n");
      return (1);
    }
}

void	print_connexion()
{
  my_putstr("my_pid: ");
  my_putnbr(getpid());
  my_putstr("\nwaiting for enemy connexion...\n");
}
