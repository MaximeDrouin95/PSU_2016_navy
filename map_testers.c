/*
** map_testers.c for navy in /home/alkoleek/PSU_2016_navy
** 
** Made by Maxime DROUIN
** Login   <maxime.drouin@epitech.eu>
** 
** Started on  Tue Feb  7 22:40:16 2017 Maxime DROUIN
** Last update Tue Feb  7 22:40:17 2017 Maxime DROUIN
*/

#include <signal.h>
#include <stdlib.h>
#include "my.h"

int     is_hit(char **map)
{
  my_putstr(i_to_c(g_navy.loc));
  if ((map[i_to_c(g_navy.loc)[1] - 48 + 1]
       [(i_to_c(g_navy.loc)[0] - 64) * 2] >= '0'
       && map[i_to_c(g_navy.loc)[1] - 48 + 1]
       [(i_to_c(g_navy.loc)[0] - 64) * 2] <= '9'))
    {
      my_putstr(": hit\n\n");
      return (1);
    }
  else
    {
      my_putstr(": missed\n\n");
      return (0);
    }
}

int     is_lose(char **map)
{
  int   i;
  int   j;

  i = 2;
  while (map[i] != 0)
    {
      j = 2;
      while (map[i][j] != '\0')
	{
	  if (map[i][j] > 47 && map[i][j] < 58)
	    return (0);
	  j = j + 1;
	}
      i = i + 1;
    }
  return (1);
}
