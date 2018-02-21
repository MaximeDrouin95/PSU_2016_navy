/*
** my_str_isnum.c for navy in /home/alkoleek/PSU_2016_navy
** 
** Made by Maxime DROUIN
** Login   <maxime.drouin@epitech.eu>
** 
** Started on  Sat Feb 18 12:05:29 2017 Maxime DROUIN
** Last update Sat Feb 18 12:05:29 2017 Maxime DROUIN
*/

#include <signal.h>
#include <stdlib.h>
#include "my.h"

int	my_str_isnum(char *str)
{
  int   count;

  count = 0;
  while (str[count] != '\0')
    {
      if (!(str[count] >= 48 && str[count] <= 57))
	return (0);
      else
	count = count + 1;
    }
  return (1);
}
