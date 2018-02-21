/*
** correct.c for navy in /home/alkoleek/PSU_2016_navy
** 
** Made by Maxime DROUIN
** Login   <maxime.drouin@epitech.eu>
** 
** Started on  Tue Feb  7 22:38:51 2017 Maxime DROUIN
** Last update Tue Feb  7 22:38:53 2017 Maxime DROUIN
*/

#include <signal.h>
#include <stdlib.h>
#include "my.h"

int     check(char *pos)
{
  if (pos[0] >= 'A' && pos[0] <= 'H')
    {
      if (pos[1] >= '1' && pos[1] <= '8')
	return (0);
      else
	return (-1);
    }
  else if (pos[0] >= '1' && pos[0] <= '8')
    {
      if (pos[1] >= 'A' && pos[1] <= 'H')
	return (1);
      else
	return (-1);
    }
  else
    return (-1);
}

char	*correct(char *pos)
{
  if (pos == NULL)
    return (NULL);
  pos = my_strcapitalize(pos);
  if (check(pos) > -1)
    {
      if (check(pos) == 1)
	pos = my_revstr(pos);
      return (pos);
    }
  else
    return (NULL);
}
