/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfarnia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 16:24:58 by mfarnia           #+#    #+#             */
/*   Updated: 2021/05/12 16:25:00 by mfarnia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three_a(t_numbers **stack_a)
{
	int			curr_elab;

	curr_elab = ft_list_len(*stack_a) - 1;
	if (!curr_elab)
		return ;
	while (!ft_isordered(*stack_a))
	{
		if ((*stack_a)->position > (*stack_a)->next->position)
		{
			ft_do_move(stack_a, NULL, "sa");
		}
		if (ft_isordered(*stack_a))
			break ;
		ft_do_move(stack_a, NULL, "rra");
	}
}

void	ft_sort_five_a(t_numbers **stack_a, t_numbers **stack_b)
{
	int		curr_elab;
	int		index;

	(void)stack_b;
	index = 0;
	curr_elab = ft_list_len(*stack_a) - 1;
	if (!curr_elab)
		return ;
	if (ft_is_consequent_ordered(*stack_a))
	{
		ft_do_convenient_rot_to_top_a(stack_a, 0);
		return ;
	}
	while (ft_list_len(*stack_a) > 3)
	{
		ft_do_convenient_rot_to_top_a(stack_a, index);
		ft_do_move(stack_a, stack_b, "pb");
		index += 1;
	}
	ft_sort_three_a(stack_a);
	while (*stack_b)
	{
		ft_do_move(stack_a, stack_b, "pa");
	}
}

void	ft_sort_more(t_numbers **stack_a, t_numbers **stack_b)
{
	int	median;

	median = ft_median(*stack_a);
	while (*stack_a)
	{
		ft_set_distances_in_stack(*stack_a, *stack_b);
		ft_min_moves(*stack_a, stack_a, stack_b);
		ft_do_move(stack_a, stack_b, "pb");
	}
	ft_max_on_head_b(stack_b);
	while (*stack_b)
	{
		ft_do_move(stack_a, stack_b, "pa");
	}
}
