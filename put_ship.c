/*
** put_ship.c for navy in /home/alkoleek/PSU_2016_navy
** 
** Made by Maxime DROUIN
** Login   <maxime.drouin@epitech.eu>
** 
** Started on  Fri Feb 17 16:59:11 2017 Maxime DROUIN
** Last update Fri Feb 17 16:59:11 2017 Maxime DROUIN
*/

#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "my.h"

char	**direction_1(char **map, char **pos)
{
  int	p;

  p = 0;
  while (p < (pos[0][0] - 48))
    {
      if (map[pos[1][1] - 48 + 1 + p][(pos[1][0] - 64) * 2] == '.')
	{
	  map[pos[1][1] - 48 + 1 + p][(pos[1][0] - 64) * 2] = pos[0][0];
	  p = p + 1;
	}
      else
	{
	  my_putstr("Error: invalid positions\n");
	  return (NULL);
	}
    }
  return (map);
}

char	**direction_2(char **map, char **pos)
{
  int	p;

  p = 0;
  while (p < (pos[0][0] - 48) * 2)
    {
      if (map[pos[1][1] - 48 + 1][(pos[1][0] - 64) * 2 + p] == '.')
	{
	  map[pos[1][1] - 48 + 1][(pos[1][0] - 64) * 2 + p] = pos[0][0];
	  p = p + 2;
	}
      else
	{
	  my_putstr("Error: invalid positions\n");
	  return (NULL);
	}
    }
  return (map);
}

char	**directioner(char **map, char **pos)
{
  int	d;

  d = 0;
  if ((d = direction(pos)) == -1)
    return (NULL);
  if (d == 1)
    map = direction_1(map, pos);
  else if (d == 2)
    map = direction_2(map, pos);
  return (map);
}

int	ship_check(char **pos)
{
  static int s_two = 0;
  static int s_three = 0;
  static int s_four = 0;
  static int s_five = 0;

  if (pos != NULL)
    {
      if (pos[0][0] == '2')
	s_two = s_two + 1;
      if (pos[0][0] == '3')
	s_three = s_three + 1;
      if (pos[0][0] == '4')
	s_four = s_four + 1;
      if (pos[0][0] == '5')
	s_five = s_five + 1;
      return (-1);
    }
  else
    if ((s_two & s_three & s_four & s_five) == 1)
      return (0);
    else
      return (1);
}

char	**put_ship(char **map, const int fd)
{
  char	**pos;
  char	*line;
  int	i;

  i = 0;
  pos = NULL;
  while (line = get_next_line(fd))
    {
      if (line[0] != '\0')
	{
	  if ((pos = parse_args(line, ':')) == NULL)
	    return (NULL);
	  if ((map = directioner(map, pos)) == NULL)
	    return (NULL);
	  ship_check(pos);
	  free(pos);
	  i = i + 1;
	}
      free(line);
    }
  if (i == 0)
    return (empty_error());
  if (ship_check(NULL) != 0)
    return (ship_error());
  return (map);
}
