#include "push_swap.h"

void	ft_case_analyzer(t_numbers **stack_a, t_numbers **stack_b)
{
	int	stack_len;

	(void)stack_b;
	stack_len = ft_list_len(*stack_a);
	if (stack_len <= 3)
		ft_sort_three_a(stack_a);
	else if (stack_len <= 5)
		ft_sort_five_a(stack_a, stack_b);
	else if (stack_len <= 100)
		ft_sort_more(stack_a, stack_b);
	else if (stack_len > 100)
		ft_sort_more(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_numbers	*stack_a;
	t_numbers	*stack_b;

	stack_a = 0;
	stack_b = 0;
	if (argc == 1)
		exit(0);
	ft_fill_stack_a(argv, &stack_a);
	ft_indicize_list(stack_a);
	ft_case_analyzer(&stack_a, &stack_b);
	ft_freelist(stack_a);
}
