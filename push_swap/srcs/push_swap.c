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

t_numbers	*ft_min_node(t_numbers *stack)
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
	min_nu = ft_min_node(stack);
	min_nu->position = index;
	while (ft_succ_node(stack, min_nu))
	{
		index += 1;
		min_nu = ft_succ_node(stack, min_nu);
		min_nu->position = index;
	}
}

void	ft_sort_three_a(t_numbers **stack_a)
{
	int			curr_elab;

	curr_elab = ft_list_len(*stack_a) - 1;
	if (!curr_elab)
		return ;
	while (!ft_isordered(*stack_a))
	{
		if ((*stack_a)->position > (*stack_a)->next->position)
		{
			ft_do_move(stack_a, NULL, "sa");
		}
		if(ft_isordered(*stack_a))
			break;
		ft_do_move(stack_a, NULL, "rra");
	}
}

int	ft_node_pos(t_numbers *stack, t_numbers *node)
{
	int			index;
	t_numbers	*curr_pos;

	curr_pos = stack;
	index = 0;
	while (curr_pos->position != node->position)
	{
		index += 1;
		curr_pos = curr_pos->next;
	}
	return (index);
}

t_numbers *ft_node_with_pos(t_numbers *stack, int pos)
{
	t_numbers *curr_pos;

	curr_pos = stack;
	while (curr_pos->position != pos)
	{
		curr_pos = curr_pos->next;
	}
	return(curr_pos);
}

char	*ft_convenient_rotation_a(t_numbers *stack, t_numbers *node)
{
	int len;

	len = ft_list_len(stack);
	if (ft_node_pos(stack, node) > len / 2)
		return("rra");
	return ("ra");
}

void	ft_do_convenient_rot_to_top_a(t_numbers **stack, int pos)
{
	char		*move;
	t_numbers	*node_to_top;

	node_to_top = ft_node_with_pos(*stack, pos);
	move = ft_convenient_rotation_a(*stack, node_to_top);
	while ((*stack)->position != pos)
	{
		ft_do_move(stack, NULL, move);
	}
}

int	ft_is_consequent_ordered(t_numbers *stack)
{
	t_numbers	*curr_nu;
	t_numbers	*next_nu;
	int			len;

	len = ft_list_len(stack);
	curr_nu = ft_min_node(stack);
	while (1)
	{
		if (!curr_nu->next)
			next_nu = stack;
		else
			next_nu = curr_nu->next;
		if (!(curr_nu->position == next_nu->position -1))
		{
			if (curr_nu->position == len - 1 && next_nu->position == 0)
				return (1);
			else
				return (0);
		}
		curr_nu = next_nu;
	}
	return (0);
}

// int		ft_lis_len_from_node(t_numbers *stack, t_numbers *node)
// {
// 	int			len;
// 	int			rel_min_pos;
// 	t_numbers	*curr_nu;
// 	t_numbers	*next_nu;

// 	len = 0;
// 	rel_min_pos = node->position;
// 	curr_nu = node;
// 	while (1)
// 	{
// 		if (!curr_nu->next)
// 			next_nu = stack;
// 		else
// 			next_nu = curr_nu->next;
// 		if (next_nu->position == node->position)
// 			break ;
// 		if (next_nu->position > re)
// 		curr_nu = next_nu;
// 	}
// 	return (len);
// }

void	ft_sort_five_a(t_numbers **stack_a, t_numbers **stack_b)
{
	int		curr_elab;
	int		index;

	(void)stack_b;
	index = 0;
	curr_elab = ft_list_len(*stack_a) - 1;
	if (!curr_elab)
		return ;
	if (ft_is_consequent_ordered(*stack_a))
	{
		ft_do_convenient_rot_to_top_a(stack_a, 0);
		return ;
	}
	while (ft_list_len(*stack_a) > 3)
	{
		ft_do_convenient_rot_to_top_a(stack_a, index);
		ft_do_move(stack_a, stack_b, "pb");
		index += 1;
	}
	ft_sort_three_a(stack_a);
	while (*stack_b)
	{
		ft_do_move(stack_a, stack_b, "pa");
	}
}

void	ft_case_analyzer(t_numbers **stack_a, t_numbers **stack_b)
{
	int	stack_len;

	(void)stack_b;
	stack_len = ft_list_len(*stack_a);
	if (stack_len <= 3)
	{
		ft_sort_three_a(stack_a);
	}
	if (stack_len <= 5)
	{
		ft_sort_five_a(stack_a, stack_b);
	}
	if (stack_len <= 100)
	{
		ft_sort_five_a(stack_a, stack_b);
	}
	if (stack_len > 100)
	{
		ft_sort_five_a(stack_a, stack_b);
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
	// ft_print_list(stack_a);
	// ft_print_list(stack_b);
	// printf("len = %d\n", ft_list_len(stack_a));
}