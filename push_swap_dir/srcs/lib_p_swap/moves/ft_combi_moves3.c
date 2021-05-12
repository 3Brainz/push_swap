/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_combi_moves3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppunzo <ppunzo@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 16:22:48 by mfarnia           #+#    #+#             */
/*   Updated: 2021/05/12 16:22:50 by mfarnia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrr_comb(int *rrr, t_numbers **stack_a, t_numbers **stack_b)
{
	while (rrr[TOGETHER] > 0)
	{
		ft_do_move(stack_a, stack_b, "rrr");
		rrr[TOGETHER] -= 1;
	}
	while (rrr[JUST_A] > 0)
	{
		ft_do_move(stack_a, stack_b, "rra");
		rrr[JUST_A] -= 1;
	}
	while (rrr[JUST_B] > 0)
	{
		ft_do_move(stack_a, stack_b, "rrb");
		rrr[JUST_B] -= 1;
	}
}

void	ft_rr_comb(int *rr, t_numbers **stack_a, t_numbers **stack_b)
{
	while (rr[TOGETHER] > 0)
	{
		ft_do_move(stack_a, stack_b, "rr");
		rr[TOGETHER] -= 1;
	}
	while (rr[JUST_A] > 0)
	{
		ft_do_move(stack_a, stack_b, "ra");
		rr[JUST_A] -= 1;
	}
	while (rr[JUST_B] > 0)
	{
		ft_do_move(stack_a, stack_b, "rb");
		rr[JUST_B] -= 1;
	}
}

void	ft_rarrb_comb(int ra, int rrb, t_numbers **stack_a, t_numbers **stack_b)
{
	while (ra > 0)
	{
		ft_do_move(stack_a, stack_b, "ra");
		ra -= 1;
	}
	while (rrb > 0)
	{
		ft_do_move(stack_a, stack_b, "rrb");
		rrb -= 1;
	}
}

void	ft_rrarb_comb(int rra, int rb, t_numbers **stack_a, t_numbers **stack_b)
{
	while (rra > 0)
	{
		ft_do_move(stack_a, stack_b, "rra");
		rra -= 1;
	}
	while (rb > 0)
	{
		ft_do_move(stack_a, stack_b, "rb");
		rb -= 1;
	}
}

void	ft_do_min_comb(t_distances *dist_a, t_distances *dist_b, \
t_numbers **stack_a, t_numbers **stack_b)
{
	int	rrr[4];
	int	rr[4];
	int	rarrb;
	int	rrarb;
	int	rel_min;

	ft_clean_combi(rr);
	ft_clean_combi(rrr);
	ft_module_sub(dist_a->r, dist_b->r, &rr[TOGETHER], \
	&rr[ft_whitch_rem(dist_a->r, dist_b->r)]);
	ft_module_sub(dist_a->rr, dist_b->rr, &rrr[TOGETHER], \
	&rrr[ft_whitch_rem(dist_a->rr, dist_b->rr)]);
	ft_combi_sum(rr);
	ft_combi_sum(rrr);
	rarrb = dist_a->r + dist_b->rr;
	rrarb = dist_a->rr + dist_b->r;
	rel_min = ft_find_min(rrr[TOTAL_M], rr[TOTAL_M], rarrb, rarrb);
	if (rel_min == 0)
		ft_rrr_comb(rrr, stack_a, stack_b);
	else if (rel_min == 1)
		ft_rr_comb(rr, stack_a, stack_b);
	else if (rel_min == 2)
		ft_rarrb_comb(dist_a->r, dist_b->rr, stack_a, stack_b);
	else
		ft_rrarb_comb(dist_a->rr, dist_b->r, stack_a, stack_b);
}
