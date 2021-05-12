/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfarnia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 16:30:25 by mfarnia           #+#    #+#             */
/*   Updated: 2021/05/12 16:30:29 by mfarnia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_node_distances_from_head(t_numbers *node, t_distances *distances)
{
	t_numbers	*curr_nu;
	t_distances	rrr;

	ft_clean_distances(&rrr);
	curr_nu = node;
	while (curr_nu)
	{
		if (!curr_nu->prev)
			break ;
		rrr.r += 1;
		curr_nu = curr_nu->prev;
	}
	curr_nu = node;
	while (curr_nu)
	{
		if (!curr_nu->prev)
			break ;
		rrr.rr += 1;
		curr_nu = curr_nu->next;
		if (!curr_nu)
			curr_nu = ft_first_elem(curr_nu);
	}
	distances->r = rrr.r;
	distances->rr = rrr.rr;
}

void	ft_node_distances_from_bottom(t_numbers *node, t_distances *distances)
{
	t_numbers	*curr_nu;
	t_distances	rrr;

	ft_clean_distances(&rrr);
	curr_nu = node;
	while (curr_nu)
	{
		if (!curr_nu->next)
			break ;
		curr_nu = curr_nu->prev;
		if (!curr_nu)
			curr_nu = ft_last_elem(node);
		rrr.r += 1;
	}
	curr_nu = node;
	while (curr_nu)
	{
		if (!curr_nu->next)
			break ;
		rrr.rr += 1;
		curr_nu = curr_nu->next;
	}
	distances->r = rrr.r;
	distances->rr = rrr.rr;
}

void	ft_ideal_pos_after_push(t_numbers *node, t_numbers *head_dest)
{
	t_numbers	*ideal_prev;
	t_numbers	*ideal_next;

	ft_dist_clear(&node->dist_in_next_next_b);
	ft_dist_clear(&node->dist_in_next_prev_h);
	ideal_next = ft_nearest_next_in_stack(head_dest, node->position);
	ideal_prev = ft_nearest_prev_in_stack(head_dest, node->position);
	if (ideal_prev)
	{
		ft_node_distances_from_head(ideal_prev, &node->dist_in_next_prev_h);
		node->dist_in_next_prev_h.num = ideal_prev->position;
	}
	if (ideal_next)
	{
		ft_node_distances_from_bottom(ideal_next, &node->dist_in_next_next_b);
		node->dist_in_next_next_b.num = ideal_next->position;
	}
}

void	ft_set_distances_in_stack(t_numbers *stack, t_numbers *dest_stack)
{
	t_numbers	*curr_nu;

	curr_nu = stack;
	if (!curr_nu)
		return ;
	while (curr_nu)
	{
		ft_node_distances_from_head(curr_nu, &curr_nu->dist_head);
		ft_ideal_pos_after_push(curr_nu, dest_stack);
		curr_nu->min_combi_moves = ft_ideal_move_len(curr_nu);
		curr_nu = curr_nu->next;
	}
}
