#include "push_swap.h"

// long		min_num(t_numbers *stack)
// {
// 	int nu;

// 	while ()
// }

int	ft_list_len(t_numbers *stack)
{
	int len;
	t_numbers *curr_nu;

	len = 0;
	curr_nu = stack;
	if (!curr_nu)
		return (0);
	while (curr_nu)
	{
		len += 1;
		curr_nu = curr_nu->next;
	}
	return (len);
}

t_numbers	*min_node(t_numbers *stack)
{
	t_numbers	*ret;
	t_numbers	*curr_nu;

	ret = stack;
	curr_nu = stack;
	if (!curr_nu)
		return (0);
	while (curr_nu)
	{
		if (ret->number > curr_nu->number)
		{
			ret = curr_nu;
		}
		curr_nu = curr_nu->next;
	}
	return (ret);
}

t_numbers	*ft_succ_node(t_numbers *stack, t_numbers *rel_prev)
{
	t_numbers *ret;
	t_numbers *curr_nu;

	curr_nu = stack;
	ret = 0;
	if (!curr_nu || !rel_prev)
		return (0);
	while (curr_nu)
	{
		if (curr_nu->number > rel_prev->number)
		{
			if (ret)
			{
				if (curr_nu->number < ret->number)
					ret = curr_nu;
			}
			else
				ret = curr_nu;
		}
		curr_nu = curr_nu->next;
	}
	return (ret);
}

void	ft_indicize_list(t_numbers *stack)
{
	t_numbers	*min_nu;
	int			index;

	index = 0;
	min_nu = min_node(stack);
	min_nu->position = index;
	while (ft_succ_node(stack, min_nu))
	{
		index += 1;
		min_nu = ft_succ_node(stack, min_nu);
		min_nu->position = index;
	}
}

void	ft_sort_three(t_numbers **stack_a, t_numbers **stack_b)
{
	t_numbers	*curr_nu;
	int			curr_elab;

	(void)stack_b;
	curr_nu = *stack_a;
	curr_elab = ft_list_len(*stack_a) - 1;
	if (!curr_elab)
		return ;
	while (!ft_isordered(*stack_a))
	{
		curr_nu = *stack_a;
		while (curr_nu)
		{
			if ((*stack_a)->position > (*stack_a)->next->position)
			{
				printf("wewe\n");
				ft_swap(stack_a);
			}
			curr_nu = curr_nu->next;
		}
	}
}

void	ft_case_analyzer(t_numbers **stack_a, t_numbers **stack_b)
{
	int	stack_len;

	stack_len = ft_list_len(*stack_a);
	if (stack_len <= 3)
	{
		printf("wewe\n");
		ft_sort_three(stack_a, stack_b);
	}
	if (stack_len <= 5)
	{
		(void)stack_len;
	}
	if (stack_len <= 100)
	{
		(void)stack_len;
	}
	{
		(void)stack_len;
	}
}

int main(int argc, char **argv)
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
	ft_print_list(stack_a);
	printf("len = %d\n", ft_list_len(stack_a));
}