/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgios-arvanitidis <georgios-arvaniti    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 21:20:00 by georgios-ar       #+#    #+#             */
/*   Updated: 2026/11/24 21:20:29 by georgios-ar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	_is_sorted_a(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack->a[i + 1])
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
	int	i;
	int	j;
	int	swapped;

	size = _size(stack->a);
	if (size < 2)
		return ;
	i = 0;
	while (i < size)
	{
		swapped = 0;
		j = 0;
		while (j < size - 1)
		{
			if (stack->a[0] > stack->a[1])
			{
				sa(stack);
				swapped = 1;
			}
			ra(stack);
			j++;
		}
		/* after a full rotation the largest element is at the bottom */
		if (!swapped || _is_sorted_a(stack))
			break ;
		i++;
	}
}