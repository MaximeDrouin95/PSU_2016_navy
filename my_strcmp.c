/*
** my_strcmp.c for navy in /home/alkoleek/PSU_2016_navy
** 
** Made by Maxime DROUIN
** Login   <maxime.drouin@epitech.eu>
** 
** Started on  Sat Feb 18 11:25:58 2017 Maxime DROUIN
** Last update Sat Feb 18 11:25:58 2017 Maxime DROUIN
*/

#include <signal.h>
#include <stdlib.h>
#include "my.h"

int	my_strcmp(char *s1, char *s2)
{
  int	count;

  count = 0;
  while (s1[count] != '\0' || s2[count] != '\0')
    {
      if (s1[count] != s2[count])
	{
	  if (s1[count] > s2[count])
	    return (1);
	  if (s2[count] > s1[count])
	    return (-1);
	}
      count = count + 1;
    }
  return (0);
}
