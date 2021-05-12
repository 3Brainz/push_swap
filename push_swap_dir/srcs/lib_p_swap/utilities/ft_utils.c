/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppunzo <ppunzo@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 16:23:57 by mfarnia           #+#    #+#             */
/*   Updated: 2021/05/12 16:23:59 by mfarnia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = c;
		i++;
	}
	return (b);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

long	ft_atoi(char *str)
{
	int		i;
	int		neg;
	long	nbr;

	i = 0;
	neg = 1;
	nbr = 0;
	while ((str[i] == '\t') || (str[i] == '\n') || (str[i] == '\v') || \
		(str[i] == '\f') || (str[i] == '\r') || (str[i] == ' '))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = neg * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10;
		nbr = nbr + str[i] - '0';
		i++;
	}
	nbr = nbr * neg;
	return (nbr);
}

void	*ft_calloc(long count, long size)
{
	void	*ptr;
	long	i;

	i = 0;
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	while (i < count * size)
		((char *)ptr)[i++] = 0;
	return (ptr);
}

void	ft_print_list(t_numbers *head)
{
	t_numbers	*curr_num;

	curr_num = head;
	if (!curr_num)
		return ;
	printf("-\n");
	while (curr_num)
	{
		printf("num: %li pos: %i min_combi:%i \n", \
		curr_num->number, curr_num->position, curr_num->min_combi_moves);
		curr_num = curr_num->next;
	}
	printf("-\n");
}
