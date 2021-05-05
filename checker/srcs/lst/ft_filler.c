#include "checker.h"

void	ft_split_nu(t_numbers **head, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) || ft_issymbol(str[i]))
		{
			ft_lst_add(ft_atoi(&str[i]), head);
			if (ft_last_elem(*head)->number > MAX_INT || \
				ft_last_elem(*head)->number < MIN_INT)
			{
				ft_freelist(*head);
				write(2, "Error\n", 6);
				exit (1);
			}
		}
		while (ft_isdigit(str[i]) || ft_issymbol(str[i]))
			i++;
		while (str[i] == ' ')
			i++;
	}
}

void	ft_fill_stack_a(char **argv, t_numbers **stack_a)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!(ft_validarg(argv[i])))
		{
			write (2, "Error\n", 6);
			exit (1);
		}
		i++;
	}
	i = 1;
	while (argv[i])
	{
		ft_split_nu(stack_a, argv[i]);
		i++;
	}
	if (ft_checkdoubles(*stack_a))
	{
		write (2, "Error\n", 6);
		ft_freelist(*stack_a);
		exit (1);
	}
}
