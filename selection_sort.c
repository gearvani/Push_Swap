/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joschmun <joschmun@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 05:56:24 by georgios-ar       #+#    #+#             */
/*   Updated: 2026/11/27 19:01:48 by joschmun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	_find_min_pos(int *stack)
{
	int	i;
	int	min;
	int	pos;

	i = 0;
	min = stack[0];
	pos = 0;
	while (stack[i])
	{
		if (stack[i] < min)
		{
			min = stack[i];
			pos = i;
		}
		i++;
	}
	return (pos);
}

static void	_bring_to_top(t_stack *stack, int pos)
{
	int	size;

	size = stack_size(stack->a);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			ra(stack);
	}
	else
	{
		while (pos++ < size)
			rra(stack);
	}
}

void	selection_sort(t_stack *stack)
{
	int	pos;

	while (stack_size(stack->a) > 0)
	{
		pos = _find_min_pos(stack->a);
		_bring_to_top(stack, pos);
		pb(stack);
	}
	while (stack_size(stack->b) > 0)
		pa(stack);
}
