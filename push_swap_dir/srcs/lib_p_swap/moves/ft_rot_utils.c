#include "push_swap.h"

char	*ft_convenient_rotation_a(t_numbers *stack, t_numbers *node)
{
	int	len;

	if (!stack)
		return ("");
	len = ft_list_len(stack);
	if (ft_node_pos(stack, node) > len / 2)
		return ("rra");
	return ("ra");
}

char	*ft_convenient_rotation_b(t_numbers *stack, t_numbers *node)
{
	int	len;

	if (!stack)
		return ("");
	len = ft_list_len(stack);
	if (ft_node_pos(stack, node) > len / 2)
		return ("rrb");
	return ("rb");
}

char	*ft_convenient_rotation(t_numbers *stack, t_numbers *node)
{
	int	len;

	if (!stack)
		return ("");
	len = ft_list_len(stack);
	if (ft_node_pos(stack, node) > len / 2)
		return ("rr");
	return ("r");
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
