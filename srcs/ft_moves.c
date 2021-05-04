#include "checker.h"

int	ft_strcmp_wo_n(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] || str2[i])
	{
		if (str1[i] != str2[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

t_numbers	*ft_last_elem(t_numbers *list)
{
	t_numbers	*curr_elem;

	if (!list)
		return (0);
	curr_elem = list;
	while (curr_elem->next)
		curr_elem = curr_elem->next;
	return (curr_elem);
}

void	ft_copynu(t_numbers *dest, t_numbers *src)
{
	dest->number = src->number;
	dest->next = src->next;
	dest->position = src->position;
	dest->prev = src->prev;
}

void	ft_swap(t_numbers **head)
{
	t_numbers	temp_next;
	t_numbers	*next;

	if (!(*head) || !(*head)->next)
		return ;
	next = (*head)->next;
	ft_copynu(&temp_next, (*head)->next);
	next->prev = (*head)->prev;
	next->next = (*head);
	(*head)->prev = next;
	(*head)->next = temp_next.next;
	if ((*head)->next)
	{
		(*head)->next->prev = *head;
	}
	*head = next;
}

void	ft_push(t_numbers **dest, t_numbers **src)
{
	t_numbers	*temp_dest;
	t_numbers	*temp_src_next;

	if (!(*src))
		return ;
	if (!(*dest))
	{
		*dest = *src;
		*src = (*src)->next;
		(*src)->prev = 0;
		(*dest)->next = 0;
	}
	else
	{
		temp_dest = *dest;
		temp_src_next = (*src)->next;
		*dest = *src;
		(*dest)->next = temp_dest;
		(*dest)->next->prev = *dest;
		*src = temp_src_next;
		if (*src)
			(*src)->prev = 0;
	}	
}

void	ft_rotate(t_numbers **stack)
{
	t_numbers	*last_elem;
	t_numbers	*temp_head;

	if (!((*stack) && (*stack)->next))
		return ;
	temp_head = *stack;
	last_elem = ft_last_elem(*stack);
	(*stack) = (*stack)->next;
	(*stack)->prev = 0;
	last_elem->next = temp_head;
	last_elem->next->prev = last_elem;
	last_elem->next->next = 0;
}

void	ft_reverse_rotate(t_numbers **stack)
{
	t_numbers	*last_elem;
	t_numbers	*temp_head;

	if (!((*stack) && (*stack)->next))
		return ;
	temp_head = *stack;
	last_elem = ft_last_elem(*stack);
	last_elem->prev->next = 0;
	(*stack) = last_elem;
	(*stack)->prev = 0;
	(*stack)->next = temp_head;
	(*stack)->next->prev = *stack;
}

int	ft_doswap(t_numbers **stack_a, t_numbers **stack_b, char *move)	
{
	if (!ft_strcmp_wo_n("sa", move))
	{
		ft_swap(stack_a);
		return (1);
	}
	if (!ft_strcmp_wo_n("sb", move))
	{
		ft_swap(stack_b);
		return (1);
	}
	if (!ft_strcmp_wo_n("ss", move))
	{
		ft_swap(stack_a);
		ft_swap(stack_b);
		return (1);
	}
	else
		return (0);
}

int	ft_dopush(t_numbers **stack_a, t_numbers **stack_b, char *move)
{
	if (!ft_strcmp_wo_n("pb", move))
	{
		ft_push(stack_b, stack_a);
		return (1);
	}
	if (!ft_strcmp_wo_n("pa", move))
	{
		ft_push(stack_a, stack_b);
		return (1);
	}
	else
		return (0);
}

int	ft_dorotate(t_numbers **stack_a, t_numbers **stack_b, char *move)
{
	if (!ft_strcmp_wo_n("ra", move))
	{		
		ft_rotate(stack_a);
		return (1);
	}
	if (!ft_strcmp_wo_n("rb", move))
	{
		ft_rotate(stack_b);
		return (1);
	}
	if (!ft_strcmp_wo_n("rr", move))
	{
		ft_rotate(stack_a);
		ft_rotate(stack_b);
		return (1);
	}
	else
		return (0);
}

int	ft_do_reverse_rotate(t_numbers **stack_a, t_numbers **stack_b, char *move)
{
	if (!ft_strcmp_wo_n("rra", move))
	{
		ft_reverse_rotate(stack_a);
		return (1);
	}
	if (!ft_strcmp_wo_n("rrb", move))
	{
		ft_reverse_rotate(stack_b);
		return (1);
	}
	if (!ft_strcmp_wo_n("rrr", move))
	{
		ft_reverse_rotate(stack_a);
		ft_reverse_rotate(stack_b);
		return (1);
	}
	else
		return (0);
}

void	ft_do_move(t_numbers **stack_a, t_numbers **stack_b, char *move)
{
	if (!(ft_doswap(stack_a, stack_b, move) || \
		ft_dopush(stack_a, stack_b, move) || \
		ft_dorotate(stack_a, stack_b, move) || \
		ft_do_reverse_rotate(stack_a, stack_b, move)))
	{
		write (2, "Error\n", 6);
		ft_freelist(*stack_a);
		ft_freelist(*stack_b);
		free(&move);
		exit (1);
	}
}
