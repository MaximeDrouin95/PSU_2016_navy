/*
** do_attack.c for navy in /home/alkoleek/PSU_2016_navy
** 
** Made by Maxime DROUIN
** Login   <maxime.drouin@epitech.eu>
** 
** Started on  Tue Feb  7 22:39:21 2017 Maxime DROUIN
** Last update Tue Feb  7 22:39:23 2017 Maxime DROUIN
*/

#include <signal.h>
#include <stdlib.h>
#include "my.h"

void	do_attack(char ***map, char *pos)
{
  if ((*map) != NULL && pos != NULL)
    {
      if (((*map)[pos[1] - 48 + 1][(pos[0] - 64) * 2] >= '0'
	  && (*map)[pos[1] - 48 + 1][(pos[0] - 64) * 2] <= '9')
	  || ((*map)[pos[1] - 48 + 1][(pos[0] - 64) * 2] == 'x'))
	(*map)[pos[1] - 48 + 1][(pos[0] - 64) * 2] = 'x';
      else
	(*map)[pos[1] - 48 + 1][(pos[0] - 64) * 2] = 'o';
    }
  else
    (*map) = NULL;
}

void    do_eattack(char ***emap, char *pos, char entry)
{
  if ((*emap)[pos[1] - 48 + 1][(pos[0] - 64) * 2] == '.')
    (*emap)[pos[1] - 48 + 1][(pos[0] - 64) * 2] = entry;
}
