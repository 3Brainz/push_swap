/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_checks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppunzo <ppunzo@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 16:23:44 by mfarnia           #+#    #+#             */
/*   Updated: 2021/05/12 16:23:46 by mfarnia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(char c)
{
	int	i;

	i = 0;
	while (V_DIGITS[i])
	{
		if (c == V_DIGITS[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_isvalidchar(char c)
{
	int	i;

	i = 0;
	while (V_CHARSET[i])
	{
		if (c == V_CHARSET[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_issymbol(char c)
{
	int	i;

	i = 0;
	while (V_SYMBOLS[i])
	{
		if (c == V_SYMBOLS[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_validarg(char *str)
{
	int	j;

	j = 0;
	while (str[j])
	{
		if (ft_isvalidchar(str[j]))
		{
			if (str[j] == '+' || str[j] == '-')
			{
				if (!(ft_isdigit(str[j + 1])))
					return (0);
			}
			if (ft_isdigit(str[j]))
			{
				if (!(str[j + 1] == ' ' || ft_isdigit(str[j + 1]) || \
				(!str[j + 1])))
					return (0);
			}
		}
		else
			return (0);
		j++;
	}
	return (1);
}
