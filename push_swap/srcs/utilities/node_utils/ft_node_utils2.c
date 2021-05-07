#include "push_swap.h"

int	ft_min_near_nu(t_numbers **stack_a, int medium)
{
	int			r;
	int			rr;
	t_numbers	*curr_nu_r;
	t_numbers	*curr_nu_rr;

	curr_nu_r = *stack_a;
	r = 0;
	rr = 0;
	while (curr_nu_r)
	{
		if (curr_nu_r->position < medium)
			break ;
		r += 1;
		curr_nu_r = curr_nu_r->next;
	}
	curr_nu_rr = ft_last_elem(*stack_a);
	while (curr_nu_rr)
	{
		if (curr_nu_rr->position < medium)
			break ;
		rr += 1;
		curr_nu_rr = curr_nu_rr->prev;
	}
	if (r > rr)
		return (curr_nu_r->position);
	else
		return (curr_nu_rr->position);
	return (0);
}
