#include "push_swap.h"

t_numbers	*ft_new_node(long nu, t_numbers *prev)
{
	t_numbers	*ret;

	ret = ft_calloc(1, sizeof(t_numbers));
	ret->number = nu;
	ret->prev = prev;
	return (ret);
}

void	ft_lst_add(long nu, t_numbers **head)
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
