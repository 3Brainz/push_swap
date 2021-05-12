/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfarnia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 16:23:12 by mfarnia           #+#    #+#             */
/*   Updated: 2021/05/12 16:23:14 by mfarnia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_max_on_head_b(t_numbers **stack_b)
{
	t_numbers	*max;

	max = ft_max_node_in_stack(*stack_b);
	ft_node_distances_from_head(max, &max->dist_head);
	if (max->dist_head.r < max->dist_head.rr)
	{
		while (max->dist_head.r > 0)
		{
			ft_do_move(NULL, stack_b, "rb");
			max->dist_head.r -= 1;
		}
	}
	else
	{
		while (max->dist_head.rr > 0)
		{
			ft_do_move(NULL, stack_b, "rrb");
			max->dist_head.rr -= 1;
		}
	}
}
