/*
** server.c for server in /home/alkoleek/INTHENAVY/PSU_2016_navy
** 
** Made by Maxime DROUIN
** Login   <alkoleek@epitech.net>
** 
** Started on  Mon Feb  6 14:18:28 2017 Maxime DROUIN
** Last update Sun Feb 12 22:05:02 2017 Maxime DROUIN
*/

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "my.h"

void    connect_handler(int signo, siginfo_t *info, void *context)
{
  if (signo == SIGUSR1)
    g_navy.pid = info->si_pid;
}

int     connect_server()
{
  struct sigaction connexion;

  connexion.sa_sigaction = &connect_handler;
  sigemptyset(&connexion.sa_mask);
  connexion.sa_flags = SA_SIGINFO | SA_RESETHAND;
  if (sigaction(SIGUSR1, &connexion, NULL) == -1)
    return (signal_error());
  while (g_navy.pid == 0)
    pause();
  usleep(SLEEP);
  if (kill(g_navy.pid, SIGUSR2) == -1)
    return (kill_error());
  return (0);
}

int	server_connect()
{
  print_connexion();
  g_navy.turn = 1;
  if (connect_server() != 0)
    return (84);
  my_putstr("enemy connected\n\n");
  return (0);
}

void    signal_handler(int signo)
{
  static int i = 0;

  if (signo == SIGUSR1)
    i = i + 1;
  if (signo == SIGUSR2)
    {
      g_navy.loc = i;
      i = 0;
    }
}

int     signal_to_int()
{
  struct sigaction connexion;

  connexion.sa_handler = &signal_handler;
  sigemptyset(&connexion.sa_mask);
  connexion.sa_flags = 0;
  if (sigaction(SIGUSR1, &connexion, NULL) == -1)
    return (signal_error());
  if (sigaction(SIGUSR2, &connexion, NULL) == -1)
    return (signal_error());
  while (g_navy.loc == 0)
    pause();
  return (0);
}
