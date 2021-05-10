#include "push_swap.h"

void ft_pos_at_move(t_numbers *stack, t_move *move)
{
	t_numbers *curr_nu;
	int	operations;

	curr_nu = stack;
	operations= move->operations;
	if ((!ft_strcmp_wo_n("rra", move->move)))
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

int ft_position_rr_dist_head(t_numbers *stack, int position)
{
	t_numbers	*curr_nu;
	int 		dist;

	dist = 1;
	curr_nu = ft_last_elem(stack);
	if (!curr_nu)
		return (0);
	while (curr_nu)
	{
		if (curr_nu->position == position)
			return (dist);
		dist += 1;
		curr_nu = curr_nu->prev;
	}
	return (dist);
}

int ft_position_r_dist_head(t_numbers *stack, int position)
{
	t_numbers	*curr_nu;
	int 		dist;

	dist = 1;
	curr_nu = stack;
	if (!curr_nu)
		return (0);
	while (curr_nu)
	{
		if (curr_nu->position == position)
			return (dist);
		dist += 1;
		curr_nu = curr_nu->next;
	}
	return (dist);
}

int ft_position_rr_dist_last(t_numbers *stack, int position)
{
	t_numbers	*curr_nu;
	int 		dist;

	dist = 0;
	curr_nu = ft_last_elem(stack);
	if (!curr_nu)
		return (0);
	while (curr_nu)
	{
		if (curr_nu->position == position)
			return (dist);
		dist += 1;
		curr_nu = curr_nu->prev;
	}
	return (dist);
}

int ft_position_r_dist_last(t_numbers *stack, int position)
{
	t_numbers	*curr_nu;
	int 		dist;
	dist = 0;
	curr_nu = stack;
	if (!curr_nu)
		return (0);
	while (curr_nu)
	{
		if (curr_nu->position == position)
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

void	ft_clean_positions(t_near_positions *positions)
{
	positions->next = -1;
	positions->prev = -1;
}

int		ft_nearest_next_in_stack(t_numbers *stack, int position)
{
	int	min_position;
	int	next_nu;
	t_numbers *curr_nu;

	curr_nu = stack;
	min_position = -1;
	next_nu = position;
	while (curr_nu)
	{
		if (curr_nu->position > position)
		{
			min_position = curr_nu->position;
			break ;
		}
		curr_nu = curr_nu->next;
	}
	while(curr_nu)
	{
		if (curr_nu->position > position && curr_nu->position < min_position)
		min_position = curr_nu->position;
		curr_nu = curr_nu->next;
	}
	return (min_position);
}

int ft_nearest_prev_in_stack(t_numbers *stack, int position)
{
	int	max_position;
	int	next_nu;
	t_numbers *curr_nu;

	curr_nu = stack;
	max_position = MAX_INT;
	next_nu = position;
	while (curr_nu)
	{
		if (curr_nu->position < position)
		{
			max_position = curr_nu->position;
			break ;
		}
		curr_nu = curr_nu->next;
	}
	while(curr_nu)
	{
		if (curr_nu->position < position && curr_nu->position > max_position)
			max_position = curr_nu->position;
		curr_nu = curr_nu->next;
	}
	if (max_position == MAX_INT)
		max_position = -1;
	return (max_position);
}

void	ft_near_positions_in_stack(int position, t_numbers *stack, t_near_positions *positions)
{
	int			prev;
	int			next;
	ft_clean_positions(positions);
	prev = position;
	next = position;
	if (!stack)
		return ;
	prev = ft_nearest_prev_in_stack(stack, position);
	next = ft_nearest_next_in_stack(stack, position);
	if (prev != -1)
		positions->prev = prev;
	if (next != -1)
		positions->next = next;
}

void	ft_best_move_to_next_sup(t_move *move, t_numbers **stack, t_numbers **stack_b, int median)
{
	int min_moves_ra_sa;
	int min_moves_rra_sa;
	t_near_positions positions;

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
	ft_near_positions_in_stack((*stack)->position, *stack_b, &positions);
	printf("next_in_b:%i, prev_in_b:%i\n", positions.next, positions.prev);
	usleep(1000000);
}

void	ft_best_move_to_bring_on_top_b(t_move *move, t_numbers *stack, int position)
{
	int	r_dist;
	int rr_dist;

	r_dist = ft_position_r_dist_head(stack, position);
	rr_dist = ft_position_rr_dist_head(stack, position);
	if (r_dist < rr_dist)
	{
		move->move = "rb";
		move->operations = r_dist;
	}
	else
	{
		move->move = "rrb";
		move->operations = rr_dist;
	}
	move->pos_of_nu = position;
}

void	ft_best_move_to_bring_on_bottom_b(t_move *move, t_numbers *stack, int position)
{
	int	r_dist;
	int rr_dist;

	r_dist = ft_position_r_dist_last(stack, position);
	rr_dist = ft_position_rr_dist_last(stack, position);
	if (r_dist < rr_dist)
	{
		move->move = "rb";
		move->operations = r_dist;
	}
	else
	{
		move->move = "rrb";
		move->operations = rr_dist;
	}
	move->pos_of_nu = position;
}

void	ft_copy_move(t_move *dest, t_move *src)
{
	dest->move = src->move;
	dest->next = src->next;
	dest->operations = src->operations;
	dest->pos_of_nu = src->pos_of_nu;
}

void	ft_clean_move(t_move *move)
{
	move->operations = 0;
	move->next = 0;
	move->move = 0;
	move->pos_of_nu = -1;
}

void	ft_compare_moves_and_copy(t_move *move_1, t_move *move_2, t_move *dest)
{
	ft_clean_move(dest);
	if (move_1->move && move_2->move)
	{
		if (move_1->operations < move_2->operations)
			ft_copy_move(dest, move_1);
		else
			ft_copy_move(dest, move_2);
	}
	else if (move_1->move)
		ft_copy_move(move_1, dest);
	else if (move_2->move)
		ft_copy_move(move_1, dest);
}

void	ft_analyzer_move_b(t_numbers *stack_b, t_near_positions *positions, t_move *move_a, t_move *move_b)
{
	t_move	move_prev;
	t_move	move_next;

	ft_clean_move(&move_next);
	ft_clean_move(&move_prev);
	if (positions->next != -1)
		ft_best_move_to_bring_on_bottom_b(&move_next, stack_b, positions->next);
	if (positions->prev != -1)
		ft_best_move_to_bring_on_top_b(&move_prev, stack_b, positions->prev);
	if ((move_prev.move) && !ft_strcmp_wo_n(move_prev.move, move_a->move))
		ft_copy_move(move_b, &move_prev);
	if ((move_next.move) && !ft_strcmp_wo_n(move_next.move, move_a->move))
		ft_copy_move(move_b, &move_next);
	else
		ft_compare_moves_and_copy(&move_prev, &move_next, move_b);
}

char	*ft_guess_combi_move(char *move)
{
	if (!ft_strcmp_wo_n(move, "ra"))
		return ("rr");
	else
		return ("rrr");
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

void	ft_do_combined_moves(t_move *moves, t_numbers **stack_a, t_numbers **stack_b)
{
	int moves_index;
	int iterator;

	moves_index = 0;
	while (moves_index < 3)
	{
		iterator = 0;
		printf("wewee:%s", moves[moves_index].move);
		while (moves[moves_index].operations != iterator)
		{
			ft_do_move(stack_a, stack_b, moves[moves_index].move);
			iterator += 1;
		}
		moves_index += 1;
	}
}


t_move	*ft_consequent_moves(t_move *move_a, t_move *move_b)
{
	t_move	*combined;
	int		index;
	int		min;

	index = 0;
	combined = ft_calloc(sizeof(t_move), 4);
	if ((!ft_strcmp_wo_n(move_a->move, "ra") && !ft_strcmp_wo_n(move_b->move, "rb"))
		|| (!ft_strcmp_wo_n(move_a->move, "rra") && !ft_strcmp_wo_n(move_b->move, "rrb")))
	{
		min = ft_min(move_a->operations, move_b->operations);
		combined[index].move = ft_guess_combi_move(move_a->move);
		combined[index].operations = min;
		move_b->operations -= min;
		move_a->operations -= min;
		index += 1;
	}
	if (move_a->operations)
	{
		ft_copy_move(&combined[index], move_a);
		index += 1;
	}
	if (move_b->operations)
		ft_copy_move(&combined[index], move_b);
	index = 0;
	return (combined);
}

void	ft_combined_moves_sup(t_numbers **stack_a, t_numbers **stack_b, int median)
{
	t_move	move_a;
	t_move	move_b;
	t_move	*combined;
	t_near_positions positions;

	ft_clean_move(&move_a);
	ft_clean_move(&move_b);
	ft_best_move_to_next_sup(&move_a , stack_a, stack_b, median);
	ft_analyzer_move_b(*stack_b, &positions, &move_a, &move_b);
	combined = ft_consequent_moves(&move_a, &move_b);
	ft_do_combined_moves(combined, stack_a, stack_b);
	ft_do_move(stack_a, stack_b, "pb");
	free(combined);
}


void	ft_sort_more(t_numbers **stack_a, t_numbers **stack_b)
{
	int max_index;
	int median;
	// t_move move_a;

	max_index = ft_list_len(*stack_a) - 1;
	median = ft_list_len(*stack_a) / 2;
	while (ft_contains_indexes(*stack_a, median, max_index))
	{

		ft_combined_moves_sup(stack_a, stack_b, median);
		// ft_best_move_to_next_sup(&move_a, stack_a, stack_b,max_index);
		// while ((*stack_a)->position < median)
		// {
		// 	if (ft_list_len(*stack_b) < 2)
		// 		ft_do_move(stack_a, stack_b, move_a.move);
		// 	else
		// 		ft_do_move(stack_a, stack_b, move_a.move);
		// }
		// ft_do_move(stack_a, stack_b, "pb");
		// system("clear")															;
		// printf("contains:%i\n", ft_contains_indexes(*stack_a, 0, max_index / 2))	;
		// ft_print_list(*stack_b)													;
		// ft_print_list(*stack_a)													;
		// usleep(1000000)															;
		//																			;
		//																			;
		//																			;
		//																			;
		//																			;
		//																			;
		//																			;
		//																			;
		//																			;
		//																			;
		//																			;
		//																			;
		//																			;
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
	else if (stack_len <= 5)
	{
		ft_sort_five_a(stack_a, stack_b);
	}
	else if (stack_len <= 100)
	{
		ft_sort_more(stack_a, stack_b);
	}
	else if (stack_len > 100)
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