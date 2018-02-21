/*
** my.h for Navy in /home/Rubiks/PSU/PSU_2016_navy
** 
** Made by Maxime BLANCHARD
** Login   <Rubiks@epitech.net>
** 
** Started on  Wed Feb  1 12:48:12 2017 Maxime BLANCHARD
** Last update Mon Feb 13 21:26:13 2017 Maxime DROUIN
*/

#ifndef MY_H_
# define MY_H_
#define SLEEP 1000
typedef struct s_navy t_navy;
struct s_navy
{
  int   pid;
  int   loc;
  int   turn;
  int   hit;
  int	connect;
};
extern t_navy g_navy;
int	direction_error();
int	server_connect();
int	client_connect(int, char **);
int	load_error();
int	kill_error();
int	signal_error();
char	**ship_error();
char	**empty_error();
void	connect_handler(int, siginfo_t *, void *);
void	print_connexion();
void    help();
int	print_win();
void	win_handler(int);
void	test_handler(int);
void    my_putchar(char);
void    my_showtab(char **);
void	do_attack(char ***, char *);
void    print_tab(char **, char **);
void    do_eattack(char ***, char *, char);
int     get_c();
int     signal_to_int();
int     connect_server();
int     c_to_i(char *);
int     is_hit(char **);
int     my_putnbr(int);
int     is_lose(char **);
int	my_strlen(char *);
int	my_strlen(char *);
int     my_putstr(char *);
int     my_getnbr(char *);
int     transmission(int);
int     my_str_isnum(char *);
int     direction(char **);
int     signal_waiter(void *);
int     my_strcmp(char *, char *);
int     connect_cli(int, char **);
int     attack(char ***, char ***);
int     ennemy_attack(char ***, char ***);
char    *correct(char *);
char    *i_to_c(int);
char    *my_revstr(char *);
char	*get_next_line(const int);
char    *my_strcapitalize(char *);
char	*my_realloc(char *, size_t);
char    **load_map(char *);
char    **parse_args(char *, char);
char    **put_ship(char **, int const);
#endif /* !MY_H_ */
