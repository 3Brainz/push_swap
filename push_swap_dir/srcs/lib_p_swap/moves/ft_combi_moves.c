/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_combi_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfarnia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 16:22:32 by mfarnia           #+#    #+#             */
/*   Updated: 2021/05/12 16:22:34 by mfarnia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_whitch_rem(int a, int b)
{
	if (a > b)
		return (JUST_A);
	return (JUST_B);
}

void	ft_module_sub(int a, int b, int *res, int *rem)
{
	if (a > b)
	{
		*rem = a - b;
		*res = a - *rem;
	}
	else
	{
		*rem = b - a;
		*res = b - *rem;
	}
}

void	ft_clean_combi(int *combi)
{
	combi[TOGETHER] = 0;
	combi[JUST_A] = 0;
	combi[JUST_B] = 0;
	combi[TOTAL_M] = 0;
}

void	ft_combi_sum(int *combi)
{
	combi[TOTAL_M] = combi[JUST_A] + combi[JUST_B] + combi[TOGETHER];
}

int	ft_find_min(int	rrr_tot, int rr_tot, int rarrb, int rrarb)
{
	int	results[4];
	int	index;
	int	ret;

	results[0] = rrr_tot;
	results[1] = rr_tot;
	results[2] = rarrb;
	results[3] = rrarb;
	index = 0;
	ret = 0;
	while (index < 3)
	{
		if (results[index] < results[ret])
			ret = index;
		index++;
	}
	return (ret);
}
