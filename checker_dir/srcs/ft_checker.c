/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfarnia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 15:26:11 by mfarnia           #+#    #+#             */
/*   Updated: 2021/05/12 15:26:13 by mfarnia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	char		*line;
	t_numbers	*head;
	t_numbers	*stack_b;

	head = 0;
	stack_b = 0;
	if (argc == 1)
		exit(0);
	ft_fill_stack_a(argv, &head);
	while (get_next_line(0, &line))
	{
		ft_do_move(&head, &stack_b, line);
		free(line);
	}
	free(line);
	if (ft_isordered(head) && !stack_b)
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
	ft_freelist(stack_b);
	ft_freelist(head);
	return (0);
}
