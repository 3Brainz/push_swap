/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfarnia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 16:30:18 by mfarnia           #+#    #+#             */
/*   Updated: 2021/05/12 16:30:20 by mfarnia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_clean_distances(t_distances *dist)
{
	dist->r = 0;
	dist->rr = 0;
}

void	ft_set_first_last(t_numbers **first, t_numbers **last, t_numbers *stack)
{
	*first = stack;
	*last = ft_last_elem(stack);
}

int	ft_max_near_nu(t_numbers **stack_a, int medium)
{
	t_distances	rrr;
	t_numbers	*curr_nu_r;
	t_numbers	*curr_nu_rr;

	ft_set_first_last(&curr_nu_r, &curr_nu_rr, *stack_a);
	ft_clean_distances(&rrr);
	while (curr_nu_r)
	{
		if (curr_nu_r->position > medium)
			break ;
		rrr.r += 1;
		curr_nu_r = curr_nu_r->next;
	}
	while (curr_nu_rr)
	{
		if (curr_nu_rr->position > medium)
			break ;
		rrr.rr += 1;
		curr_nu_rr = curr_nu_rr->prev;
	}
	if (rrr.r > rrr.rr)
		return (curr_nu_r->position);
	else
		return (curr_nu_rr->position);
	return (0);
}

int	ft_min_near_nu(t_numbers **stack_a, int medium)
{
	t_distances	rrr;
	t_numbers	*curr_nu_r;
	t_numbers	*curr_nu_rr;

	ft_set_first_last(&curr_nu_r, &curr_nu_rr, *stack_a);
	ft_clean_distances(&rrr);
	while (curr_nu_r)
	{
		if (curr_nu_r->position < medium)
			break ;
		rrr.r += 1;
		curr_nu_r = curr_nu_r->next;
	}
	while (curr_nu_rr)
	{
		if (curr_nu_rr->position < medium)
			break ;
		rrr.rr += 1;
		curr_nu_rr = curr_nu_rr->prev;
	}
	if (rrr.r > rrr.rr)
		return (curr_nu_r->position);
	else
		return (curr_nu_rr->position);
	return (0);
}
