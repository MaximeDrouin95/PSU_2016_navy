/*
** my_strcapitalize.c for navy in /home/alkoleek/PSU_2016_navy
** 
** Made by Maxime DROUIN
** Login   <maxime.drouin@epitech.eu>
** 
** Started on  Tue Feb  7 22:46:20 2017 Maxime DROUIN
** Last update Tue Feb  7 22:46:22 2017 Maxime DROUIN
*/

#include <signal.h>
#include <stdlib.h>
#include "my.h"

char	*my_strcapitalize(char *str)
{
  int   count;

  count = 0;
  while (str[count] != '\0')
    {
      if (str[count] == str[0])
	{
	  if (str[count] > 96 && str[count] < 123)
	    str[count] = str[count] - 32;
	  count = count + 1;
	}
      if (!(str[count - 1] >= 65 && str[count - 1] <= 90)
	 && !(str[count - 1] >= 97 && str[count - 1] <= 122))
	{
	  if (str[count] > 96 && str[count] < 123)
	    str[count] = str[count] - 32;
	}
      count = count + 1;
    }
  return (str);
}
