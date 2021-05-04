#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define V_CHARSET "0123456789+- "
# define V_DIGITS "0123456789"
# define V_SYMBOLS "+-"
# define NODOUBLES ""
# define BUFFER_SIZE 1

typedef struct s_numbers
{
	int					number;
	struct s_numbers	*next;
	struct s_numbers	*prev;
	int					position;
}	t_numbers;

int			ft_isdigit(char c);
int			ft_isvalidchar(char c);
int			ft_validarg(char *str);
int			ft_issymbol(char c);
int			ft_atoi(char *str);
void		*ft_calloc(long count, long size);
t_numbers	*ft_new_node(int nu, t_numbers *prev);
void		ft_lst_add(int nu, t_numbers **head);
void		ft_split_nu(t_numbers **head, char *str);
void		*ft_memset(void *b, int c, size_t len);
void		ft_bzero(void *s, size_t n);
void		ft_freelist(t_numbers *head);
int			ft_checkdoubles(t_numbers *head);
int			ft_isordered(t_numbers *head);
void		ft_swap(t_numbers **head);
void		ft_do_move(t_numbers **stack_a, t_numbers **stack_b, char *move);
void		ft_push(t_numbers **dest, t_numbers **src);
void		ft_rotate(t_numbers **stack);
void		ft_reverse_rotate(t_numbers **stack);
size_t		ft_strlen(const char *str);
int			ft_iscinstr(char c, char const *str, size_t len);
char		*ft_strnew(size_t size);
char		*ft_strjoin(char *s1, char *s2);

#endif
