/*
** my_putstr.c for navy in /home/alkoleek/PSU_2016_navy
** 
** Made by Maxime DROUIN
** Login   <maxime.drouin@epitech.eu>
** 
** Started on  Tue Feb  7 22:42:57 2017 Maxime DROUIN
** Last update Tue Feb  7 22:43:15 2017 Maxime DROUIN
*/

#include <signal.h>
#include <stdlib.h>
#include "my.h"

int	my_putstr(char *str)
{
  int	count;

  count = 0;
  while (str[count] != '\0')
    {
      my_putchar(str[count]);
      count = count + 1;
    }
  return (0);
}
