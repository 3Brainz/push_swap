#include "push_swap.h"

void ft_pos_at_move(t_numbers *stack, t_move *move)
{
	t_numbers *curr_nu;
	int	operations;

	curr_nu = stack;
	operations= move->operations;
	if ((!ft_strcmp_wo_n("ra", move->move)))
	{
		while (operations)
		{
			curr_nu = curr_nu->next;
			operations -= 1;
		}
	}
	else
	{
		while (operations)
		{
			if (!curr_nu->prev)
				curr_nu = ft_last_elem(stack);
			else
				curr_nu = curr_nu->prev;
			operations -= 1;
		}
	}
	move->pos_of_nu = curr_nu->position;
}

int	ft_next_inferior_index_ra_dist(t_numbers *stack, int median)
{
	t_numbers	*curr_nu;
	int 		dist;

	dist = 0;
	curr_nu = stack;
	if (!curr_nu)
		return (0);
	while (curr_nu)
	{
		if (curr_nu->position < median)
			return (dist);
		dist += 1;
		curr_nu = curr_nu->next;
	}
	return (dist);
}

int ft_next_inferior_index_rra_dist(t_numbers *stack, int median)
{
	t_numbers	*curr_nu;
	int 		dist;

	if (stack->position < median)
		return (0);
	dist = 1;
	curr_nu = ft_last_elem(stack);
	if (!curr_nu)
		return (0);
	while (curr_nu)
	{
		if (curr_nu->position < median)
			return (dist);
		dist += 1;
		curr_nu = curr_nu->prev;
	}
	return (dist);
}

int	ft_next_sup_index_ra_dist(t_numbers *stack, int median)
{
	t_numbers	*curr_nu;
	int 		dist;

	dist = 0;
	curr_nu = stack;
	if (!curr_nu)
		return (0);
	while (curr_nu)
	{
		if (curr_nu->position > median)
			return (dist);
		dist += 1;
		curr_nu = curr_nu->next;
	}
	return (dist);
}

int ft_next_sup_index_rra_dist(t_numbers *stack, int median)
{
	t_numbers	*curr_nu;
	int 		dist;

	if (stack->position > median)
		return (0);
	dist = 1;
	curr_nu = ft_last_elem(stack);
	if (!curr_nu)
		return (0);
	while (curr_nu)
	{
		if (curr_nu->position > median)
			return (dist);
		dist += 1;
		curr_nu = curr_nu->prev;
	}
	return (dist);
}

int ft_contains_indexes(t_numbers *stack, int from, int to)
{
	t_numbers *curr_nu;

	curr_nu = stack;
	if (!curr_nu)
		return (0);
	while (curr_nu)
	{
		if (curr_nu->position >= from && curr_nu->position <= to)
		{
			return (1);
		}
		curr_nu = curr_nu->next;
	}
	return (0);
}

void	ft_best_move_to_next_inf(t_move *move, t_numbers **stack, int median)
{
	int min_moves_ra_sa;
	int min_moves_rra_sa;

	min_moves_ra_sa = ft_next_sup_index_ra_dist(*stack, median);
	min_moves_rra_sa = ft_next_sup_index_rra_dist(*stack, median);
	if (min_moves_rra_sa < min_moves_ra_sa)
	{
		move->operations =  min_moves_rra_sa;
		move->move = "rra";
	}
	else
	{
		move->operations = min_moves_ra_sa;
		move->move = "ra";
	}
}

void	ft_best_move_to_next_sup(t_move *move, t_numbers **stack, int median)
{
	int min_moves_ra_sa;
	int min_moves_rra_sa;

	min_moves_ra_sa = ft_next_sup_index_ra_dist(*stack, median);
	min_moves_rra_sa = ft_next_sup_index_rra_dist(*stack, median);
	if (min_moves_rra_sa < min_moves_ra_sa)
	{
		move->operations = min_moves_rra_sa;
		move->move = "rra";
	}
	else
	{
		move->operations = min_moves_ra_sa;
		move->move = "ra";
	}
	ft_pos_at_move(*stack, move);
	printf("move->next_position:%i\n", move->pos_of_nu);
	usleep(1000000);
}

void	ft_max_near_nu(t_numbers **stack_a, int medium, t_move *move)
{
	int			r;
	int			rr;
	t_numbers	*curr_nu_r;
	t_numbers	*curr_nu_rr;

	curr_nu_r = *stack_a;
	r = 0;
	rr = 1;
	while (curr_nu_r)
	{
		if (curr_nu_r->position > medium)
			break ;
		r += 1;
		curr_nu_r = curr_nu_r->next;
	}
	curr_nu_rr = ft_last_elem(*stack_a);
	while (curr_nu_rr)
	{
		if (curr_nu_rr->position > medium)
			break ;
		rr += 1;
		curr_nu_rr = curr_nu_rr->prev;
	}
	if (r > rr)
	{
		move->pos_of_nu = curr_nu_r->position;
		move->move = "rra";
		move->operations = rr;
	}
	else
	{
		move->pos_of_nu = curr_nu_r->position;
		move->move = "rr";
		move->operations = r;
	}
}

void	ft_sort_more(t_numbers **stack_a, t_numbers **stack_b)
{
	int max_index;
	int median;
	t_move move_a;
	// t_move move_b;


	max_index = ft_list_len(*stack_a) - 1;
	median = ft_list_len(*stack_a) / 2;
	while (ft_contains_indexes(*stack_a, median, max_index))
	{
		ft_best_move_to_next_sup(&move_a, stack_a, max_index);
		while ((*stack_a)->position < median)
		{
			if (ft_list_len(*stack_b) < 2)
				ft_do_move(stack_a, stack_b, move_a.move);
			else
			ft_do_move(stack_a, stack_b, move_a.move);
		}
		ft_do_move(stack_a, stack_b, "pb");
		// system("clear");
		// printf("contains:%i\n", ft_contains_indexes(*stack_a, 0, max_index / 2));
		// ft_print_list(*stack_b);
		// ft_print_list(*stack_a);
		// usleep(1000000);
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
		ft_sort_more(stack_a, stack_b);
	}
	if (stack_len > 100)
	{
		ft_sort_more(stack_a, stack_b);
	}
	// system("clear");
	ft_print_list(*stack_a);
	ft_print_list(*stack_b);
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
}