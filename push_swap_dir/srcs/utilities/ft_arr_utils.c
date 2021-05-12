/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppunzo <ppunzo@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 16:29:14 by mfarnia           #+#    #+#             */
/*   Updated: 2021/05/12 16:29:16 by mfarnia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_void_int_array(int len)
{
	int	*arr;
	int	index;

	index = 0;
	arr = malloc(len + 1 * sizeof(int));
	while (index < len)
	{
		arr[index] = -1;
		index += 1;
	}
	return (arr);
}

int	ft_int_arr_len(int *arr)
{
	int	index;

	index = 0;
	while (arr[index] > 0)
	{
		index++;
	}
	return (index);
}
