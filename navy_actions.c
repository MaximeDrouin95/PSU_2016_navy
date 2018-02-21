/*
** navy_actions.c for navy_actions in /home/alkoleek/INTHENAVY/PSU_2016_navy
** 
** Made by Maxime DROUIN
** Login   <alkoleek@epitech.net>
** 
** Started on  Mon Feb  6 14:26:50 2017 Maxime DROUIN
** Last update Tue Feb  7 22:25:47 2017 Maxime DROUIN
*/

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "my.h"

int	lose_handler(char ***map, char ***emap)
{
  if (is_lose((*map)) == 1)
    {
      g_navy.turn = -2;
      if (kill(g_navy.pid, SIGUSR2) == -1)
	return (kill_error());
      print_tab((*map), (*emap));
      return (-1);
    }
  else
    {
      if (kill(g_navy.pid, SIGUSR1) == -1)
	return (kill_error());
      return (0);
    }
}

int     ennemy_attack(char ***map, char ***emap)
{
  int	i;

  my_putstr("waiting for enemy's attack...\n");
  if (signal_to_int() != 0)
    return (84);
  usleep(SLEEP);
  if (is_hit((*map)) == 1)
    {
      if (kill(g_navy.pid, SIGUSR1) == -1)
	return (kill_error());
    }
  else
    {
      if (kill(g_navy.pid, SIGUSR2) == -1)
	return (kill_error());
    }
  do_attack(map, i_to_c(g_navy.loc));
  g_navy.turn = 1;
  usleep(SLEEP);
  if ((i = lose_handler(map, emap)) != 0)
    return (i);
  return (0);
}

int     attack(char ***map, char ***emap)
{
  if ((g_navy.loc = get_c()) == -1)
    return (84);
  if (transmission(g_navy.loc) != 0)
    return (kill_error());
  if (signal_waiter(test_handler) != 0)
    return (84);
  if (g_navy.hit == 1)
    do_eattack(emap, i_to_c(g_navy.loc), 'x');
  else if (g_navy.hit == -1)
    do_eattack(emap, i_to_c(g_navy.loc), 'o');
  g_navy.hit = 0;
  g_navy.turn = 0;
  if (signal_waiter(win_handler) != 0)
    return (84);
  if (g_navy.turn == -1)
    {
      print_tab((*map), (*emap));
      return (-1);
    }
  return (0);
}
