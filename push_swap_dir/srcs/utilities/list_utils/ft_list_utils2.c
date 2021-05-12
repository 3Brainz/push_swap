/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppunzo <ppunzo@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 16:29:56 by mfarnia           #+#    #+#             */
/*   Updated: 2021/05/12 16:29:58 by mfarnia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_numbers	*ft_first_elem(t_numbers *node)
{
	t_numbers	*curr_nu;

	curr_nu = node;
	if (!curr_nu)
		return (0);
	if (!curr_nu->prev)
		return (curr_nu);
	while (curr_nu->prev)
	{
		curr_nu = curr_nu->prev;
	}
	return (curr_nu);
}

int	ft_contains_bigger(t_numbers *stack, int then)
{
	t_numbers	*curr_nu;

	curr_nu = stack;
	if (!curr_nu)
		return (0);
	while (curr_nu)
	{
		if (curr_nu->position > then)
			return (1);
		curr_nu = curr_nu->next;
	}
	return (0);
}

int	ft_near_bigger_number_head(t_numbers *stack, int then)
{
	t_numbers	*curr_nu_r;
	t_numbers	*curr_nu_rr;
	t_distances	rrr;

	curr_nu_r = stack;
	rrr.r = 0;
	rrr.rr = 1;
	while (curr_nu_r)
	{
		if (curr_nu_r->position > then)
			break ;
		rrr.r++;
		curr_nu_r = curr_nu_r->next;
	}
	curr_nu_rr = ft_last_elem(stack);
	while (curr_nu_rr->prev)
	{
		if (curr_nu_rr->position > then)
			break ;
		rrr.rr++;
		curr_nu_rr = curr_nu_rr->prev;
	}
	if (rrr.r < rrr.rr)
		return (curr_nu_r->position);
	return (curr_nu_rr->position);
}
