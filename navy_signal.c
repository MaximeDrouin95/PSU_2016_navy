/*
** navy_signal.c for navy_signal in /home/alkoleek/INTHENAVY/PSU_2016_navy
** 
** Made by Maxime DROUIN
** Login   <alkoleek@epitech.net>
** 
** Started on  Mon Feb  6 14:33:33 2017 Maxime DROUIN
** Last update Mon Feb  6 16:55:44 2017 Maxime DROUIN
*/

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "my.h"

void    test_handler(int signo)
{
  if (signo == SIGUSR1)
    {
      my_putstr(i_to_c(g_navy.loc));
      my_putstr(": hit\n\n");
      g_navy.hit = 1;
    }
  if (signo == SIGUSR2)
    {
      my_putstr(i_to_c(g_navy.loc));
      my_putstr(": missed\n\n");
      g_navy.hit = -1;
    }
}

void    win_handler(int signo)
{
  if (signo == SIGUSR2)
    g_navy.turn = -1;
}

int     signal_waiter(void *handler)
{
  if (signal(SIGUSR1, handler) == SIG_ERR)
    return (signal_error());
  if (signal(SIGUSR2, handler) == SIG_ERR)
    return (signal_error());
  pause();
  return (0);
}
