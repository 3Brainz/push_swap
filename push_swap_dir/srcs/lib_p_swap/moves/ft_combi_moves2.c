/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_combi_moves2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppunzo <ppunzo@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 16:22:41 by mfarnia           #+#    #+#             */
/*   Updated: 2021/05/12 16:22:42 by mfarnia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_calculate_min_comb(int ra, int rra, int rb, int rrb)
{
	int	rrr[4];
	int	rr[4];
	int	rarrb;
	int	rrarb;
	int	rel_min;

	ft_clean_combi(rr);
	ft_clean_combi(rrr);
	ft_module_sub(ra, rb, &rr[TOGETHER], &rr[ft_whitch_rem(ra, rb)]);
	ft_module_sub(rra, rrb, &rrr[TOGETHER], &rrr[ft_whitch_rem(rra, rrb)]);
	ft_combi_sum(rr);
	ft_combi_sum(rrr);
	rarrb = ra + rrb;
	rrarb = rra + rb;
	rel_min = ft_find_min(rrr[TOTAL_M], rr[TOTAL_M], rarrb, rarrb);
	if (rel_min == 0)
		return (rrr[TOTAL_M]);
	else if (rel_min == 1)
		return (rr[TOTAL_M]);
	else if (rel_min == 2)
		return (rarrb);
	else
		return (rrarb);
	return (0);
}

int	ft_ideal_move_len(t_numbers *node)
{
	int	min_prev_h;
	int	min_next_b;

	min_prev_h = ft_calculate_min_comb(node->dist_head.r, node->dist_head.rr, \
	node->dist_in_next_prev_h.r, node->dist_in_next_prev_h.rr);
	min_next_b = ft_calculate_min_comb(node->dist_head.r, node->dist_head.rr, \
	node->dist_in_next_next_b.r, node->dist_in_next_next_b.rr);
	if (!ft_is_dist(&node->dist_in_next_next_b) && \
		!ft_is_dist(&node->dist_in_next_prev_h))
		return (0);
	if (!ft_is_dist(&node->dist_in_next_next_b))
		return (min_prev_h);
	else if (!ft_is_dist(&node->dist_in_next_prev_h))
		return (min_next_b);
	else
		return (ft_min(min_next_b, min_prev_h));
}

t_distances	*ft_ideal_move_target(t_numbers *node)
{
	int	min_prev_h;
	int	min_next_b;

	min_prev_h = ft_calculate_min_comb(node->dist_head.r, node->dist_head.rr, \
	node->dist_in_next_prev_h.r, node->dist_in_next_prev_h.rr);
	min_next_b = ft_calculate_min_comb(node->dist_head.r, node->dist_head.rr, \
	node->dist_in_next_next_b.r, node->dist_in_next_next_b.rr);
	if (!ft_is_dist(&node->dist_in_next_next_b) && \
		!ft_is_dist(&node->dist_in_next_prev_h))
		return (0);
	if (!ft_is_dist(&node->dist_in_next_next_b))
		return (&node->dist_in_next_prev_h);
	else if (!ft_is_dist(&node->dist_in_next_prev_h))
		return (&node->dist_in_next_next_b);
	else
	{
		if (min_prev_h < min_next_b)
			return (&node->dist_in_next_prev_h);
		return (&node->dist_in_next_next_b);
	}
}

t_numbers	*min_moves_node(t_numbers *stack)
{
	t_numbers	*curr_nu;
	t_numbers	*min;

	curr_nu = stack;
	min = stack;
	while (curr_nu)
	{
		if (curr_nu->min_combi_moves < min->min_combi_moves)
			min = curr_nu;
		curr_nu = curr_nu->next;
	}
	return (min);
}
