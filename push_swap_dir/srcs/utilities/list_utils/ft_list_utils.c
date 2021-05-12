/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppunzo <ppunzo@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 16:29:49 by mfarnia           #+#    #+#             */
/*   Updated: 2021/05/12 16:29:50 by mfarnia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_list_len(t_numbers *stack)
{
	int			len;
	t_numbers	*curr_nu;

	len = 0;
	curr_nu = stack;
	if (!curr_nu)
		return (0);
	while (curr_nu)
	{
		len += 1;
		curr_nu = curr_nu->next;
	}
	return (len);
}

void	ft_indicize_list(t_numbers *stack)
{
	t_numbers	*min_nu;
	int			index;

	index = 0;
	min_nu = ft_min_node(stack);
	min_nu->position = index;
	while (ft_succ_node(stack, min_nu))
	{
		index += 1;
		min_nu = ft_succ_node(stack, min_nu);
		min_nu->position = index;
	}
}

int	ft_is_consequent_ordered(t_numbers *stack)
{
	t_numbers	*curr_nu;
	t_numbers	*next_nu;
	int			len;

	len = ft_list_len(stack);
	curr_nu = ft_min_node(stack);
	while (1)
	{
		if (!curr_nu->next)
			next_nu = stack;
		else
			next_nu = curr_nu->next;
		if (!(curr_nu->position == next_nu->position -1))
		{
			if (curr_nu->position == len - 1 && next_nu->position == 0)
				return (1);
			else
				return (0);
		}
		curr_nu = next_nu;
	}
	return (0);
}

int	ft_is_consequent_ordered_rev(t_numbers *stack)
{
	t_numbers	*curr_nu;
	t_numbers	*next_nu;
	int			len;

	len = ft_list_len(stack);
	curr_nu = ft_min_node(stack);
	while (1)
	{
		if (!curr_nu->prev)
			next_nu = ft_last_elem(stack);
		else
			next_nu = curr_nu->prev;
		if (!(curr_nu->position == next_nu->position - 1))
		{
			if (curr_nu->position == len - 1 && next_nu->position == 0)
				return (1);
			else
				return (0);
		}
		curr_nu = next_nu;
	}
	return (0);
}
