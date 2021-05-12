/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_math.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppunzo <ppunzo@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 16:29:33 by mfarnia           #+#    #+#             */
/*   Updated: 2021/05/12 16:29:34 by mfarnia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_min_pos_in_stack(t_numbers *stack)
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

int	ft_max_pos_in_stack(t_numbers *stack)
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

int	ft_median(t_numbers *stack)
{
	int	min;
	int	max;

	min = ft_min_pos_in_stack(stack);
	max = ft_max_pos_in_stack(stack);
	return ((max - min) / 2);
}
