/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfarnia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 16:22:17 by mfarnia           #+#    #+#             */
/*   Updated: 2021/05/12 16:22:18 by mfarnia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_copynu(t_numbers *dest, t_numbers *src)
{
	dest->number = src->number;
	dest->next = src->next;
	dest->position = src->position;
	dest->prev = src->prev;
}

t_numbers	*ft_last_elem(t_numbers *list)
{
	t_numbers	*curr_elem;

	if (!list)
		return (0);
	curr_elem = list;
	while (curr_elem->next)
		curr_elem = curr_elem->next;
	return (curr_elem);
}
