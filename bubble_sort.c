/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgios-arvanitidis <georgios-arvaniti    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 05:54:24 by georgios-ar       #+#    #+#             */
/*   Updated: 2026/11/26 05:54:27 by georgios-ar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	_is_sorted(t_stack *stack, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (stack->a[i] > stack->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	bubble_sort(t_stack *stack)
{
	int	size;
	int	j;
	int	swapped;

	size = stack_size(stack->a);
	if (size < 2)
		return ;
	while (!_is_sorted(stack, size))
	{
		swapped = 0;
		j = -1;
		while (++j < size - 1)
		{
			if (stack->a[0] > stack->a[1])
			{
				sa(stack);
				swapped = 1;
			}
			ra(stack);
		}
		ra(stack);
		if (!swapped)
			break ;
	}
}
