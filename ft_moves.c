/*

pa : push a - take the first element at the top of b and put it at the top of a. Do
nothing if b is empty.
pb : push b - take the first element at the top of a and put it at the top of b. Do
nothing if a is empty.
ra : rotate a - shift up all elements of stack a by 1. The first element becomes
the last one.
rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
rr : ra and rb at the same time.
rra : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
rrb : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
rrr : rra and rrb at the same time.
*/

#include "checker.h"

int ft_strcmp_wo_n(char *str1, char *str2)
{
	int i;

	i = 0;
	while (str1[i] && str1[i] != '\n')
	{
		if (str1[i] != str2[i])
		{
			return (1);
		}
		i++;
	}
	return(0);
}
/*
sa : swap a - swap the first 2 elements at the top of stack a. (Do nothing if there is only one or no elements).
sb : swap b - swap the first 2 elements at the top of stack b. (Do nothing if there is only one or no elements).
ss : sa and sb at the same time.
*/
void	ft_swap(t_numbers *stack)
{
	t_numbers temp;

	if (!stack || !stack->next)
		return ;
	temp.prev = stack->next->prev;
	temp.next = stack->next->next;
	stack->prev = stack;
	stack->next = temp.next->next;

}

void ft_do_move(t_numbers *stack_a, t_numbers *stack_b, char *move)
{

}
