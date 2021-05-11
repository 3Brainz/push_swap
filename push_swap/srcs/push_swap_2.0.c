#include "push_swap.h"

char	*ft_move_to_string(int move)
{
	if (move == 1)
		return ("pa");
	if (move == 2)
		return ("ra");
	if (move == 3)
		return ("rra");
	if (move == 4)
		return ("sa");
	if (move == 5)
		return ("pb");
	if (move == 6)
		return ("rb");
	if (move == 7)
		return ("rrb");
	if (move == 8)
		return ("sb");
	if (move == 9)
		return ("rr");
	if (move == 10)
		return ("rrr");
	if (move == 11)
		return ("ss");
	return ("");
}

t_numbers *ft_first_elem(t_numbers *node)
{
	t_numbers *curr_nu;

	curr_nu = node;
	if (!curr_nu)
		return (0);
	if (!curr_nu->prev)
		return (curr_nu);
	while (curr_nu->prev)
	{
		curr_nu = curr_nu->prev;
	}
	return (curr_nu);
}

int		ft_contains_bigger(t_numbers *stack, int then)
{
	t_numbers *curr_nu;

	curr_nu = stack;
	if (!curr_nu)
		return (0);
	while (curr_nu)
	{
		if (curr_nu->position > then)
			return (1);
		curr_nu = curr_nu->next;
	}
	return (0);
}

int		ft_near_bigger_number_head(t_numbers *stack, int then)
{
	t_numbers	*curr_nu_r;
	t_numbers	*curr_nu_rr;
	int			r;
	int			rr;

	curr_nu_r = stack;
	r = 0;
	rr = 1;
	while (curr_nu_r)
	{
		if (curr_nu_r->position > then)
			break ;
		r++;
		curr_nu_r = curr_nu_r->next;
	}
	curr_nu_rr = ft_last_elem(stack);
	while (curr_nu_rr->prev)
	{
		if (curr_nu_rr->position > then)
			break ;
		rr++;
		curr_nu_rr = curr_nu_rr->prev;
	}
	if (r < rr)
		return (curr_nu_r->position);
	return(curr_nu_rr->position);
}

void	ft_node_distances_from_head(t_numbers *node, t_distances *distances)
{
	t_numbers	*curr_nu;
	int			r;
	int			rr;

	r = 0;
	rr = 0;
	curr_nu = node;
	while (curr_nu)
	{
		if (!curr_nu->prev)
			break ;
		r++;
		curr_nu = curr_nu->prev;
	}
	curr_nu = node;
	while (curr_nu)
	{
		if (!curr_nu->prev)
			break ;
		rr++;
		curr_nu = curr_nu->next;
		if (!curr_nu)
			curr_nu = ft_first_elem(curr_nu);
	}
	distances->r = r;
	distances->rr = rr;
}

void	ft_node_distances_from_bottom(t_numbers *node, t_distances *distances)
{
	t_numbers	*curr_nu;
	int			r;
	int			rr;

	r = 0;
	rr = 0;
	curr_nu = node;
	while (curr_nu)
	{
		if (!curr_nu->next)
			break ;
		curr_nu = curr_nu->prev;
		if (!curr_nu)
			curr_nu = ft_last_elem(node);
		r++;
	}
	curr_nu = node;
	while (curr_nu)
	{
		if (!curr_nu->next)
			break ;
		rr++;
		curr_nu = curr_nu->next;
	}
	distances->r = r;
	distances->rr = rr;
}


void	ft_dist_clear(t_distances *dist)
{
	dist->r = -1;
	dist->rr = -1;
}

int		is_dist(t_distances *dist)
{
	if (dist->r == -1 || dist->rr == -1)
		return 0;
	return (1);
}

int		ft_whitch_rem(int a, int b)
{
	if (a > b)
		return (JUST_A);
	return (JUST_B);
}

void	ft_module_sub(int a, int b, int *res, int *rem)
{
	if (a > b)
	{
		*rem = a - b;
		*res = a - *rem;
	}
	else
	{
		*rem = b - a;
		*res = b - *rem;
	}
}

void	ft_clean_combi(int *combi)
{
	combi[TOGETHER] = 0;
	combi[JUST_A] = 0;
	combi[JUST_B] = 0;
	combi[TOTAL_M] = 0;
}

void	ft_combi_sum(int *combi)
{
	combi[TOTAL_M] = combi[JUST_A] + combi[JUST_B] + combi[TOGETHER];
}

int	ft_find_min(int	rrr_tot, int rr_tot, int rarrb, int rrarb)
{
	int	results[4];
	int	index;
	int ret;

	results[0] = rrr_tot;
	results[1] = rr_tot;
	results[2] = rarrb;
	results[3] = rrarb;
	index = 0;
	ret = 0;
	while (index < 3)
	{
		if (results[index] < results[ret])
			ret = index;
		index++;
	}
	return (ret);
}

int		ft_calculate_min_comb(int ra, int rra, int rb, int rrb)
{
	int rrr[4];
	int rr[4];
	int	rarrb;
	int	rrarb;
	int rel_min;

	ft_clean_combi(rr);
	ft_clean_combi(rrr);
	ft_module_sub(ra, rb, &rr[TOGETHER], &rr[ft_whitch_rem(ra, rb)]);
	ft_module_sub(rra, rrb, &rrr[TOGETHER], &rrr[ft_whitch_rem(rra, rrb)]);
	ft_combi_sum(rr);
	ft_combi_sum(rrr);
	rarrb = ra + rrb;
	rrarb = rra + rb;
	rel_min = ft_find_min(rrr[TOTAL_M], rr[TOTAL_M], rarrb, rarrb);
	if (rel_min == 0)
		return (rrr[TOTAL_M]);
	else if (rel_min == 1)
		return (rr[TOTAL_M]);
	else if (rel_min == 2)
		return (rarrb);
	else
		return (rrarb);
	return (0);
}

int		ft_min(int a, int b)
{
	if (a < b)
		return a;
	return b;
}

int		ft_ideal_move_len(t_numbers *node)
{
	int min_prev_h;
	int min_next_b;

	min_prev_h = ft_calculate_min_comb(node->dist_head.r, node->dist_head.rr, node->dist_in_next_prev_h.r, node->dist_in_next_prev_h.rr);
	min_next_b = ft_calculate_min_comb(node->dist_head.r, node->dist_head.rr, node->dist_in_next_next_b.r, node->dist_in_next_next_b.rr);
	if (!is_dist(&node->dist_in_next_next_b) && \
		!is_dist(&node->dist_in_next_prev_h))
		return (0);
	if (!is_dist(&node->dist_in_next_next_b))
		return (min_prev_h);
	else if (!is_dist(&node->dist_in_next_prev_h))
		return (min_next_b);
	else
		return (ft_min(min_next_b, min_prev_h));
}


void	ft_ideal_pos_after_push(t_numbers *node, t_numbers *head_dest)
{
	t_numbers	*ideal_prev;
	t_numbers	*ideal_next;

	ft_dist_clear(&node->dist_in_next_next_b);
	ft_dist_clear(&node->dist_in_next_prev_h);
	ideal_next= ft_nearest_next_in_stack(head_dest, node->position);
	ideal_prev = ft_nearest_prev_in_stack(head_dest, node->position);
	if (ideal_prev)
	{
		ft_node_distances_from_head(ideal_prev, &node->dist_in_next_prev_h);
		node->dist_in_next_prev_h.num = ideal_prev->position;
	}
	if (ideal_next)
	{
		ft_node_distances_from_bottom(ideal_next, &node->dist_in_next_next_b);
		node->dist_in_next_next_b.num = ideal_next->position;
	}
}

void	ft_set_distances_in_stack(t_numbers *stack, t_numbers *dest_stack)
{
	t_numbers *curr_nu;

	curr_nu = stack;
	if (!curr_nu)
		return ;
	while (curr_nu)
	{
		ft_node_distances_from_head(curr_nu, &curr_nu->dist_head);
		ft_ideal_pos_after_push(curr_nu, dest_stack);
		curr_nu->min_combi_moves = ft_ideal_move_len(curr_nu);
		curr_nu = curr_nu->next;
	}
}

t_distances		*ft_ideal_move_target(t_numbers *node)
{
	int min_prev_h;
	int min_next_b;

	min_prev_h = ft_calculate_min_comb(node->dist_head.r, node->dist_head.rr, node->dist_in_next_prev_h.r, node->dist_in_next_prev_h.rr);
	min_next_b = ft_calculate_min_comb(node->dist_head.r, node->dist_head.rr, node->dist_in_next_next_b.r, node->dist_in_next_next_b.rr);
	if (!is_dist(&node->dist_in_next_next_b) && \
		!is_dist(&node->dist_in_next_prev_h))
		return (0);
	if (!is_dist(&node->dist_in_next_next_b))
		return (&node->dist_in_next_prev_h);
	else if (!is_dist(&node->dist_in_next_prev_h))
		return (&node->dist_in_next_next_b);
	else
	{
		if (min_prev_h < min_next_b)
			return (&node->dist_in_next_prev_h);
		return (&node->dist_in_next_next_b);
	}
}

t_numbers	*min_moves_node(t_numbers *stack)
{
	t_numbers *curr_nu;
	t_numbers *min;
	curr_nu = stack;
	min =	stack;
	while (curr_nu)
	{
		if (curr_nu->min_combi_moves < min->min_combi_moves)
			min = curr_nu;
		curr_nu = curr_nu->next;
	}
	return (min);
}

// t_numbers	*ft_max_node_in_stack(t_numbers *stack)
// {
// 	t_numbers	*curr_nu;
// 	t_numbers	*max;

// 	curr_nu = stack;
// 	max = stack;

// 	while (curr_nu)
// 	{
// 		if (max->position < curr_nu->position)
// 			max = curr_nu;
// 		curr_nu = curr_nu->next;
// 	}
// 	return (max);
// }

void	ft_max_on_head_b(t_numbers **stack_b)
{
	t_numbers *max;

	max = ft_max_node_in_stack(*stack_b);
	ft_node_distances_from_head(max, &max->dist_head);
	if (max->dist_head.r < max->dist_head.rr)
	{
		while (max->dist_head.r > 0)
		{
			ft_do_move(NULL, stack_b, "rb");
			max->dist_head.r -= 1;
		}
	}
	else
	{
		while (max->dist_head.rr > 0)
		{
			ft_do_move(NULL, stack_b, "rrb");
			max->dist_head.rr -= 1;
		}
	}
}

/*
int		ft_calculate_min_comb(int ra, int rra, int rb, int rrb)
{
	int rrr[4];
	int rr[4];
	int	rarrb;
	int	rrarb;
	int rel_min;

	ft_clean_combi(rr);
	ft_clean_combi(rrr);
	ft_module_sub(ra, rb, &rr[TOGETHER], &rr[ft_whitch_rem(ra, rb)]);
	ft_module_sub(rra, rrb, &rrr[TOGETHER], &rrr[ft_whitch_rem(rra, rrb)]);
	ft_combi_sum(rr);
	ft_combi_sum(rrr);
	rarrb = ra + rrb;
	rrarb = rra + rb;
	rel_min = ft_find_min(rrr[TOTAL_M], rr[TOTAL_M], rarrb, rarrb);
	if (rel_min == 0)
		return (rrr[TOTAL_M]);
	else if (rel_min == 1)
		return (rr[TOTAL_M]);
	else if (rel_min == 2)
		return (rarrb);
	else
		return (rrarb);
	return (0);
}
*/

void	ft_rrr_comb(int *rrr, t_numbers **stack_a, t_numbers **stack_b)
{
	while (rrr[TOGETHER] > 0)
	{
		ft_do_move(stack_a, stack_b, "rrr");
		rrr[TOGETHER] -= 1;
	}
	while (rrr[JUST_A] > 0)
	{
		ft_do_move(stack_a, stack_b, "rra");
		rrr[JUST_A] -= 1;
	}
	while (rrr[JUST_B] > 0)
	{
		ft_do_move(stack_a, stack_b, "rrb");
		rrr[JUST_B] -= 1;
	}
}

void	ft_rr_comb(int *rr, t_numbers **stack_a, t_numbers **stack_b)
{
	while (rr[TOGETHER] > 0)
	{
		ft_do_move(stack_a, stack_b, "rr");
		rr[TOGETHER] -= 1;
	}
	while (rr[JUST_A] > 0)
	{
		ft_do_move(stack_a, stack_b, "ra");
		rr[JUST_A] -= 1;
	}
	while (rr[JUST_B] > 0)
	{
		ft_do_move(stack_a, stack_b, "rb");
		rr[JUST_B] -= 1;
	}
}

void	ft_rarrb_comb(int ra, int rrb, t_numbers **stack_a, t_numbers **stack_b)
{
	while (ra > 0)
	{
		ft_do_move(stack_a, stack_b, "ra");
		ra -= 1;
	}
	while (rrb > 0)
	{
		ft_do_move(stack_a, stack_b, "rrb");
		rrb -= 1;
	}
}

void	ft_rrarb_comb(int rra, int rb, t_numbers **stack_a, t_numbers **stack_b)
{
	while (rra > 0)
	{
		ft_do_move(stack_a, stack_b, "rra");
		rra -= 1;
	}
	while (rb > 0)
	{
		ft_do_move(stack_a, stack_b, "rb");
		rb -= 1;
	}
}

void		ft_do_min_comb(int ra, int rra, int rb, int rrb, t_numbers **stack_a, t_numbers **stack_b)
{
	int rrr[4];
	int rr[4];
	int	rarrb;
	int	rrarb;
	int rel_min;

	ft_clean_combi(rr);
	ft_clean_combi(rrr);
	ft_module_sub(ra, rb, &rr[TOGETHER], &rr[ft_whitch_rem(ra, rb)]);
	ft_module_sub(rra, rrb, &rrr[TOGETHER], &rrr[ft_whitch_rem(rra, rrb)]);
	ft_combi_sum(rr);
	ft_combi_sum(rrr);
	rarrb = ra + rrb;
	rrarb = rra + rb;
	rel_min = ft_find_min(rrr[TOTAL_M], rr[TOTAL_M], rarrb, rarrb);
	if (rel_min == 0)
		ft_rrr_comb(rrr, stack_a, stack_b);
	else if (rel_min == 1)
		ft_rr_comb(rr, stack_a, stack_b);
	else if (rel_min == 2)
		ft_rarrb_comb(ra, rrb, stack_a, stack_b);
	else
		ft_rrarb_comb(rra, rb, stack_a, stack_b);
}


void	ft_do_min_moves_node(t_numbers *node, t_numbers **stack_a, t_numbers **stack_b)
{
	t_distances *move_distances;

	move_distances = ft_ideal_move_target(node);
	if (!move_distances)
		return ;
	ft_do_min_comb(node->dist_head.r, node->dist_head.rr, move_distances->r, move_distances->rr, stack_a, stack_b);
}

void	ft_min_moves(t_numbers *head, t_numbers **stack_a, t_numbers **stack_b)
{
	t_numbers	*min_node;

	min_node = min_moves_node(head);
	// printf("min_node : %i\n", min_node->position);
	ft_do_min_moves_node(min_node, stack_a, stack_b);
}

void	ft_sort_more(t_numbers **stack_a, t_numbers **stack_b)
{
	int	median;

	median = ft_median(*stack_a);
	while (*stack_a)
	{
		ft_set_distances_in_stack(*stack_a, *stack_b);
		ft_min_moves(*stack_a, stack_a, stack_b);
		ft_do_move(stack_a, stack_b, "pb");
		// ft_print_list(*stack_a);
		// printf("\n");
		// ft_print_list(*stack_b);
		// read(0, NULL, 1);
	}
	ft_max_on_head_b(stack_b);
	while (*stack_b)
	{
		ft_do_move(stack_a, stack_b, "pa");
	}
	// ft_print_list(*stack_a);
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
		 (void)stack_len;
		 ft_sort_more(stack_a, stack_b);
		// ft_sort_more(stack_a, stack_b);
	}
	else if (stack_len > 100)
	{
		 (void)stack_len;
		ft_sort_more(stack_a, stack_b);
		// ft_sort_more(stack_a, stack_b);
	}
	// system("clear");
	// ft_print_list(*stack_a);
	// ft_print_list(*stack_b);
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