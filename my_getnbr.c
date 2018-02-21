/*
** my_getnbr.c for navy in /home/alkoleek/PSU_2016_navy
** 
** Made by Maxime DROUIN
** Login   <maxime.drouin@epitech.eu>
** 
** Started on  Tue Feb  7 22:40:55 2017 Maxime DROUIN
** Last update Tue Feb  7 22:41:02 2017 Maxime DROUIN
*/

#include <signal.h>
#include <stdlib.h>
#include "my.h"

int	my_getnbr(char *str)
{
  int	result;

  result = 0;
  while (*str != '\0' && *str >= '0' && *str <= '9')
    {
      if (result > 214748364)
	return (0);
      if (result == 214748364 && *str > 7)
	return (0);
      if (result == 214748364 && *str > 8)
	return (0);
      result = result * 10 + *str - 48;
      str = str + 1;
    }
  return (result);
}
