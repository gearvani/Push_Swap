/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgios-arvanitidis <georgios-arvaniti    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 20:26:30 by georgios-ar       #+#    #+#             */
/*   Updated: 2026/11/24 20:42:22 by georgios-ar      ###   ########.fr       */
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

	size = _size(stack->a);
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

	while (_size(stack->a) > 0)
	{
		pos = _find_min_pos(stack->a);
		_bring_to_top(stack, pos);
		pb(stack);
	}
	while (_size(stack->b) > 0)
		pa(stack);
}
