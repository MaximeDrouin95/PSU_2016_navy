/*
** client.c for navy in /home/alkoleek/PSU_2016_navy
** 
** Made by Maxime DROUIN
** Login   <maxime.drouin@epitech.eu>
** 
** Started on  Tue Feb  7 22:37:47 2017 Maxime DROUIN
** Last update Sun Feb 12 22:08:42 2017 Maxime DROUIN
*/

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "my.h"

void    connect_validation(int signo, siginfo_t *info, void *context)
{
  if (signo == SIGUSR2)
    {
      if (g_navy.pid == info->si_pid)
	g_navy.connect = 1;
      else
	g_navy.connect = -1;
    }
}

int	connect_waiter()
{
  struct sigaction connexion;
  int	i;

  i = 0;
  connexion.sa_sigaction = &connect_validation;
  sigemptyset(&connexion.sa_mask);
  connexion.sa_flags = SA_SIGINFO | SA_RESETHAND;
  if (sigaction(SIGUSR2, &connexion, NULL) == -1)
    return (84);
  while (i < 10 && g_navy.connect == 0)
    {
      usleep(SLEEP);
      i = i + 1;
    }
  return (0);
}

int     connect_cli(int ac, char **av)
{
  usleep(SLEEP);
  if (kill(g_navy.pid, SIGUSR1) == -1)
    {
      my_putstr("Error: connexion failed\n");
      return (84);
    }
  if (connect_waiter() != 0)
    return (signal_error());
  if (g_navy.connect == 0)
    {
      my_putstr("Error: connexion timed-out\n");
      return (84);
    }
  if (g_navy.connect == -1)
    {
      my_putstr("Error: got connexion from wrong pid\n");
      return (84);
    }
  return (0);
}

int	client_connect(int ac, char **av)
{
  g_navy.pid = my_getnbr(av[1]);
  my_putstr("my_pid:\t");
  my_putnbr(getpid());
  my_putchar('\n');
  if (connect_cli(ac, av) != 0)
    return (84);
  my_putstr("successfully connected\n\n");
  return (0);
}

int     transmission(int loc)
{
  int   i;

  i = 0;
  usleep(SLEEP);
  while (i < loc)
    {
      usleep(SLEEP);
      if (kill(g_navy.pid, SIGUSR1) == -1)
	return (-1);
      i = i + 1;
    }
  usleep(SLEEP);
  if (kill(g_navy.pid, SIGUSR2) == -1)
    return (-1);
  return (0);
}
