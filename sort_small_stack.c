#include "push_swap.h"

void	sort_two(t_stack *stack)
{
	if (stack->a[0] > stack->a[1])
		sa(stack);
}

void	sort_three(t_stack *stack)
{
	if (stack->a[0] < stack->a[1] && stack->a[1] > stack->a[2])
		rra(stack);
	if (stack->a[0] > stack->a[1] && stack->a[1] > stack->a[2])
	{
		sa(stack);
		rra(stack);
	}
	while (!is_sorted(stack))
	{
		if (stack->a[0] < stack->a[1])
			sa(stack);
		else
			ra(stack);
	}
}

// void	sort_four(t_stack *stack)
// {
// 	while (stack->a[0] != 1)
// 		ra(stack);
// 	pb(stack);
// 	sort_three(stack);
// 	pa(stack);
// }

// static void _move_to_stack_b(t_stack *stack, int pivet, int j)
// {
// 	int	i;

// 	i = 0;
// 	while (stack->a[i] != j)
// 		i++;
// 	if (i > pivet)
// 	{
// 		while (stack->a[0] != j)
// 			rra(stack);
// 	}
// 	else
// 	{
// 		while (stack->a[0] != j)
// 			ra(stack);
// 	}
// 	pb(stack);
// }

// void	sort_five(t_stack *stack)
// {
// 	int	j;
// 	int	pivet;

// 	j = 1;
// 	pivet = stack->size / 2;
// 	while (j != 3)
// 	{
// 		_move_to_stack_b(stack, pivet, j);
// 		j++;
// 	}
// 	sort_three(stack);
// 	if (stack->b[0] < stack->b[1])
// 		sb(stack);
// 	pa(stack);
// 	pa(stack);
// }
