/*
** load_map.c for navy in /home/alkoleek/PSU_2016_navy
** 
** Made by Maxime DROUIN
** Login   <maxime.drouin@epitech.eu>
** 
** Started on  Tue Feb  7 22:39:49 2017 Maxime DROUIN
** Last update Mon Feb 13 22:05:54 2017 Maxime DROUIN
*/

#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

char	**load_map(char *filepath)
{
  char	**map;
  char	*s;
  int	fd;
  int	i;

  i = 0;
  if ((fd = open(filepath, O_RDONLY)) == -1)
    return (NULL);
  if ((map = malloc(sizeof(char *) * 11)) == NULL)
    return (NULL);
  while (s = get_next_line(fd))
    {
      map[i] = s;
      i = i + 1;
    }
  map[i] = NULL;
  return (map);
}
