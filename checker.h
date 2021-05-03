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

#endif
