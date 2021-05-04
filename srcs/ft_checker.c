#include "checker.h"

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

void	ft_print_list(t_numbers *head)
{
	t_numbers	*curr_num;

	curr_num = head;
	if (!curr_num)
		return ;
	printf("-\n");
	while (curr_num)
	{
		printf("%d\n", curr_num->number);
		curr_num = curr_num->next;
	}
	printf("-\n");
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
	printf("a\n");
	ft_print_list(head);
	printf("b\n");
	ft_print_list(stack_b);
	ft_freelist(stack_b);
	ft_freelist(head);
	return (0);
}
