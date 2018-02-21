/*
** my_showtab.c for navy in /home/alkoleek/PSU_2016_navy
** 
** Made by Maxime DROUIN
** Login   <maxime.drouin@epitech.eu>
** 
** Started on  Tue Feb  7 22:45:20 2017 Maxime DROUIN
** Last update Tue Feb  7 22:45:22 2017 Maxime DROUIN
*/

#include <signal.h>
#include <stdlib.h>
#include "my.h"

void	my_showtab(char **tab)
{
  int	i;

  i = 0;
  if (tab != NULL)
    while (tab[i] != NULL)
      {
	my_putstr(tab[i]);
	i++;
	if (tab[i] != NULL && tab[i][0] != '\n')
	  my_putchar('\n');
      }
  my_putstr("\n\n");
}
