/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joschmun <joschmun@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 23:50:31 by joschmun          #+#    #+#             */
/*   Updated: 2026/11/26 05:16:51 by joschmun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	_ft_sqrt(int n)
{
	int	i;

	if (n <= 0)
		return (0);
	i = 1;
	while (i <= n / i)
		i++;
	return (i - 1);
}

static int	_find_max_pos(int *stack)
{
	int	i;
	int	max;
	int	pos;

	i = 0;
	max = stack[0];
	pos = 0;
	while (stack[i])
	{
		if (stack[i] > max)
		{
			max = stack[i];
			pos = i;
		}
		i++;
	}
	return (pos);
}

static void	_push_chunks_to_b(t_stack *stack, int chunk)
{
	int	i;

	i = 1;
	while (stack_size(stack->a) > 0)
	{
		if (stack->a[0] <= i)
		{
			pb(stack);
			rb(stack);
			i++;
		}
		else if (stack->a[0] <= i + chunk)
		{
			pb(stack);
			i++;
		}
		else
			ra(stack);
	}
}

static void	_push_max_to_a(t_stack *stack)
{
	int	pos;
	int	size;

	while (stack_size(stack->b) > 0)
	{
		pos = _find_max_pos(stack->b);
		size = stack_size(stack->b);
		if (pos <= size / 2)
		{
			while (pos-- > 0)
				rb(stack);
		}
		else
		{
			while (pos++ < size)
				rrb(stack);
		}
		pa(stack);
	}
}

void	chunk_sort(t_stack *stack)
{
	int	chunk;

	if (stack->size < 2)
		return ;
	chunk = _ft_sqrt(stack->size);
	if (chunk < 1)
		chunk = 1;
	_push_chunks_to_b(stack, chunk);
	_push_max_to_a(stack);
}
