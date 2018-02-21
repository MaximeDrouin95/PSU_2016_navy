/*
** converter.c for navy in /home/alkoleek/PSU_2016_navy
** 
** Made by Maxime DROUIN
** Login   <maxime.drouin@epitech.eu>
** 
** Started on  Tue Feb  7 22:38:10 2017 Maxime DROUIN
** Last update Mon Feb 13 21:29:20 2017 Maxime DROUIN
*/

#include <signal.h>
#include <stdlib.h>
#include "my.h"

int	c_to_i(char *pos)
{
  int	l;
  int	c;

  if (pos == NULL)
    return (-1);
  l = (pos[1] - 48) * 8;
  c = pos[0] - 64;
  return (l + c - 8);
}

char	*i_to_c(int signal)
{
  int	i;
  int	j;
  int	k;
  char	*pos;

  i = signal + 8;
  j = 1;
  k = i - j * 8;
  if ((pos = malloc(sizeof(char) * 3)) == NULL)
    return (NULL);
  while (k > 8)
    {
      j = j + 1;
      k = i - j * 8;
    }
  pos[0] = k + 64;
  pos[1] = j + 48;
  pos[2] = '\0';
  return (pos);
}

int     get_c()
{
  char  *str;
  char	*check;

  my_putstr("attack: ");
  check = get_next_line(0);
  str = correct(check);
  while (str == NULL)
    {
      my_putstr("wrong position\n");
      my_putstr("attack: ");
      check = get_next_line(0);
      str = correct(check);
    }
  return (c_to_i(str));
}
