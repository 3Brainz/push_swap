#include "push_swap.h"

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
		(*dest)->prev = 0;
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
