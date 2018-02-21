/*
** direction.c for navy in /home/alkoleek/PSU_2016_navy
** 
** Made by Maxime DROUIN
** Login   <maxime.drouin@epitech.eu>
** 
** Started on  Fri Feb 10 14:12:07 2017 Maxime DROUIN
** Last update Mon Feb 13 15:21:55 2017 Maxime DROUIN
*/

#include <signal.h>
#include <stdlib.h>
#include "my.h"

char	**swap(char **pos)
{
  char	*temp;

  if (my_strcmp(pos[1], pos[2]) > 0)
    {
      temp = pos[1];
      pos[1] = pos[2];
      pos[2] = temp;
    }
  return (pos);
}

int	direction(char **pos)
{
  if (pos[2] != NULL && (pos[1] = correct(pos[1])) != NULL
      && (pos[2] = correct(pos[2])) != NULL)
    {
      pos = swap(pos);
      if ((pos[0][0] < '2' || pos[0][0] > '5')
	|| (((pos[0][0] - 48) != ((pos[2][0] - 64) - (pos[1][0] - 64) + 1))
	  && ((pos[0][0] - 48) != ((pos[2][1] - 48) - (pos[1][1] - 48) + 1))))
	{
	  my_putstr("Error: incorrect ship length\n");
	  return (-1);
	}
      if (pos[1][0] == pos[2][0] || pos[1][0] == pos[2][1])
	return (1);
      else if (pos[1][1] == pos[2][0] || pos[1][1] == pos[2][1])
	return (2);
      else
	return (direction_error());
    }
  else
    return (direction_error());
}

int	direction_error()
{
  my_putstr("Error: invalid ship position\n");
  return (-1);
}
