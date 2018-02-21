/*
** my_revstr.c for navy in /home/alkoleek/PSU_2016_navy
** 
** Made by Maxime DROUIN
** Login   <maxime.drouin@epitech.eu>
** 
** Started on  Tue Feb  7 22:44:47 2017 Maxime DROUIN
** Last update Tue Feb  7 22:45:04 2017 Maxime DROUIN
*/

#include <signal.h>
#include <stdlib.h>
#include "my.h"

char    *my_revstr(char *str)
{
  int   count;
  int	count2;
  int   temp;

  count = 0;
  count2 = 0;
  temp = 0;
  while (str[count2] != '\0')
    count2 = count2 + 1;
  count2 = count2 - 1;
  while (count < count2)
    {
      temp = str[count];
      str[count] = str[count2];
      str[count2] = temp;
      count = count + 1;
      count2 = count2 - 1;
    }
  return (str);
}
