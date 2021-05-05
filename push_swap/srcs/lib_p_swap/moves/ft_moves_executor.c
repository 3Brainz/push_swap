#include "push_swap.h"

int	ft_doswap(t_numbers **stack_a, t_numbers **stack_b, char *move)	
{
	if (!ft_strcmp_wo_n("sa", move))
	{
		ft_swap(stack_a);
		return (1);
	}
	if (!ft_strcmp_wo_n("sb", move))
	{
		ft_swap(stack_b);
		return (1);
	}
	if (!ft_strcmp_wo_n("ss", move))
	{
		ft_swap(stack_a);
		ft_swap(stack_b);
		return (1);
	}
	else
		return (0);
}

int	ft_dopush(t_numbers **stack_a, t_numbers **stack_b, char *move)
{
	if (!ft_strcmp_wo_n("pb", move))
	{
		ft_push(stack_b, stack_a);
		return (1);
	}
	if (!ft_strcmp_wo_n("pa", move))
	{
		ft_push(stack_a, stack_b);
		return (1);
	}
	else
		return (0);
}

int	ft_dorotate(t_numbers **stack_a, t_numbers **stack_b, char *move)
{
	if (!ft_strcmp_wo_n("ra", move))
	{		
		ft_rotate(stack_a);
		return (1);
	}
	if (!ft_strcmp_wo_n("rb", move))
	{
		ft_rotate(stack_b);
		return (1);
	}
	if (!ft_strcmp_wo_n("rr", move))
	{
		ft_rotate(stack_a);
		ft_rotate(stack_b);
		return (1);
	}
	else
		return (0);
}

int	ft_do_reverse_rotate(t_numbers **stack_a, t_numbers **stack_b, char *move)
{
	if (!ft_strcmp_wo_n("rra", move))
	{
		ft_reverse_rotate(stack_a);
		return (1);
	}
	if (!ft_strcmp_wo_n("rrb", move))
	{
		ft_reverse_rotate(stack_b);
		return (1);
	}
	if (!ft_strcmp_wo_n("rrr", move))
	{
		ft_reverse_rotate(stack_a);
		ft_reverse_rotate(stack_b);
		return (1);
	}
	else
		return (0);
}

void	ft_do_move(t_numbers **stack_a, t_numbers **stack_b, char *move)
{
	write(1, move, ft_strlen(move));
	if (!(ft_doswap(stack_a, stack_b, move) || \
		ft_dopush(stack_a, stack_b, move) || \
		ft_dorotate(stack_a, stack_b, move) || \
		ft_do_reverse_rotate(stack_a, stack_b, move)))
	{
		write (2, "Error\n", 6);
		exit (1);
	}
}
