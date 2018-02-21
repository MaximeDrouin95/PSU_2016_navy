/*
** error.c for navy in /home/alkoleek/PSU_2016_navy
** 
** Made by Maxime DROUIN
** Login   <maxime.drouin@epitech.eu>
** 
** Started on  Wed Feb 15 22:37:04 2017 Maxime DROUIN
** Last update Wed Feb 15 22:37:04 2017 Maxime DROUIN
*/

#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"

int	kill_error()
{
  my_putstr("Error: connexion lost\n");
  return (84);
}

int	signal_error()
{
  my_putstr("Error: signal error\n");
  return (84);
}

int	load_error()
{
  my_putstr("Error: map loading error\n");
  return (84);
}

char	**empty_error()
{
  my_putstr("Error: empty file\n");
  return (NULL);
}

char	**ship_error()
{
  my_putstr("Error: invalid ship placement\n");
  return (NULL);
}
