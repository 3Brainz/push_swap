/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_combi_moves4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppunzo <ppunzo@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 16:22:56 by mfarnia           #+#    #+#             */
/*   Updated: 2021/05/12 16:22:58 by mfarnia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_do_min_moves_node(t_numbers *node, t_numbers **stack_a, \
t_numbers **stack_b)
{
	t_distances	*move_distances;

	move_distances = ft_ideal_move_target(node);
	if (!move_distances)
		return ;
	ft_do_min_comb(&node->dist_head, move_distances, stack_a, stack_b);
}

void	ft_min_moves(t_numbers *head, t_numbers **stack_a, t_numbers **stack_b)
{
	t_numbers	*min_node;

	min_node = min_moves_node(head);
	ft_do_min_moves_node(min_node, stack_a, stack_b);
}
