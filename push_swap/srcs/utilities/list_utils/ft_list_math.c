#include "push_swap.h"

int		ft_min_pos_in_stack(t_numbers *stack)
{
	t_numbers	*curr_nu;
	int			ret;

	ret = stack->position;
	curr_nu = stack;
	if (!curr_nu)
		return (-1);
	while (curr_nu)
	{
		if (curr_nu->position < ret)
			ret = curr_nu->position;
		curr_nu = curr_nu->next;
	}
	return (ret);
}

int		ft_max_pos_in_stack(t_numbers *stack)
{
	t_numbers	*curr_nu;
	int			ret;

	ret = stack->position;
	curr_nu = stack;
	if (!curr_nu)
		return (-1);
	while (curr_nu)
	{
		if (curr_nu->position > ret)
			ret = curr_nu->position;
		curr_nu = curr_nu->next;
	}
	return (ret);
}

t_numbers	*ft_max_node_in_stack(t_numbers *stack)
{
	t_numbers	*curr_nu;
	t_numbers	*ret;

	ret = stack;
	curr_nu = stack;
	if (!curr_nu)
		return (0);
	while (curr_nu)
	{
		if (curr_nu->position > ret->position)
			ret = curr_nu;
		curr_nu = curr_nu->next;
	}
	return (ret);
}

int		ft_median(t_numbers *stack)
{
	int min;
	int max;

	min = ft_min_pos_in_stack(stack);
	max = ft_max_pos_in_stack(stack);
	return ((max - min) / 2);
}

t_numbers	*ft_nearest_next_in_stack(t_numbers *stack, int position)
{
	t_numbers	*min_position;
	int	next_nu;
	t_numbers *curr_nu;

	curr_nu = stack;
	min_position = 0;
	next_nu = position;
	while (curr_nu)
	{
		if (curr_nu->position > position)
		{
			min_position = curr_nu;
			break ;
		}
		curr_nu = curr_nu->next;
	}
	while(curr_nu)
	{
		if (curr_nu->position > position && curr_nu->position < min_position->position)
		min_position = curr_nu;
		curr_nu = curr_nu->next;
	}
	return (min_position);
}

t_numbers	*ft_nearest_prev_in_stack(t_numbers *stack, int position)
{
	t_numbers	*max_position;
	int	next_nu;
	t_numbers *curr_nu;

	curr_nu = stack;
	max_position = ft_max_node_in_stack(stack);
	next_nu = position;
	while (curr_nu)
	{
		if (curr_nu->position < position)
		{
			max_position = curr_nu;
			break ;
		}
		curr_nu = curr_nu->next;
	}
	while(curr_nu)
	{
		if (curr_nu->position < position && curr_nu->position > max_position->position)
			max_position = curr_nu;
		curr_nu = curr_nu->next;
	}
	return (max_position);
}