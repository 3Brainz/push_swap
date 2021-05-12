/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfarnia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 16:25:17 by mfarnia           #+#    #+#             */
/*   Updated: 2021/05/12 16:25:19 by mfarnia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_dist_clear(t_distances *dist)
{
	dist->r = -1;
	dist->rr = -1;
}

int	ft_is_dist(t_distances *dist)
{
	if (dist->r == -1 || dist->rr == -1)
		return (0);
	return (1);
}
