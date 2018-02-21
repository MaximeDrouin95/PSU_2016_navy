/*
** help.c for navy in /home/alkoleek/PSU_2016_navy
** 
** Made by Maxime DROUIN
** Login   <maxime.drouin@epitech.eu>
** 
** Started on  Tue Feb  7 22:39:35 2017 Maxime DROUIN
** Last update Tue Feb  7 22:39:37 2017 Maxime DROUIN
*/

#include <signal.h>
#include <stdlib.h>
#include "my.h"

void    help()
{
  my_putstr("USAGE\n\t\t./navy [first_player_pid] navy_positions\n\n");
  my_putstr("DESCRIPTION\n\t\tfirst_player_pid\tonly for the 2nd player.");
  my_putstr("  pid of the first player.\n");
  my_putstr("\t\tnavy_positions\t\tfile representing ");
  my_putstr("the positions of the ships\n");
}
