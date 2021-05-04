#include "checker.h"

int	ft_atoi(char *str)
{
	int	i;
	int	neg;
	int	nbr;

	i = 0;
	neg = 1;
	nbr = 0;
	while ((str[i] == '\t') || (str[i] == '\n') || (str[i] == '\v') || \
		(str[i] == '\f') || (str[i] == '\r') || (str[i] == ' '))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = neg * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10;
		nbr = nbr + str[i] - '0';
		i++;
	}
	nbr = nbr * neg;
	return (nbr);
}

void	*ft_calloc(long count, long size)
{
	void	*ptr;
	long	i;

	i = 0;
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	while (i < count * size)
		((char *)ptr)[i++] = 0;
	return (ptr);
}

t_numbers	*ft_new_node(int nu, t_numbers *prev)
{
	t_numbers	*ret;

	ret = ft_calloc(1, sizeof(t_numbers));
	ret->number = nu;
	ret->prev = prev;
	return (ret);
}

void	ft_lst_add(int nu, t_numbers **head)
{
	t_numbers	*curr_num;

	if (!(*head))
	{
		*head = ft_new_node(nu, NULL);
		return ;
	}
	curr_num = *head;
	while (curr_num->next)
	{
		curr_num = curr_num->next;
	}
	curr_num->next = ft_new_node(nu, curr_num);
}

void	ft_split_nu(t_numbers **head, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) || ft_issymbol(str[i]))
		{
			ft_lst_add(ft_atoi(&str[i]), head);
		}
		while (ft_isdigit(str[i]) || ft_issymbol(str[i]))
		{
			i++;
		}
		while (str[i] == ' ')
		{
			i++;
		}
	}
}

void	ft_freelist(t_numbers *head)
{
	t_numbers	*next_nu;

	if (!head)
		return ;
	while (head)
	{
		next_nu = head->next;
		ft_bzero(head, sizeof(head));
		free(head);
		head = next_nu;
	}
}

int	ft_checkdoubles(t_numbers *head)
{
	t_numbers	*curr_nu;
	t_numbers	*tested_nu;

	curr_nu = head;
	while (curr_nu)
	{
		tested_nu = curr_nu->next;
		while (tested_nu)
		{
			if (curr_nu->number == tested_nu->number)
			{
				return (1);
			}
			tested_nu = tested_nu->next;
		}
		curr_nu = curr_nu->next;
	}
	return (0);
}

int	ft_isordered(t_numbers *head)
{
	t_numbers	*curr_nu;

	curr_nu = head;
	while (curr_nu)
	{
		if (curr_nu->next)
		{
			if (curr_nu->number > curr_nu->next->number)
			{
				return (0);
			}
		}
		curr_nu = curr_nu->next;
	}
	return (1);
}
