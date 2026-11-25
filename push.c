/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joschmun <joschmun@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 19:21:15 by georgios-ar       #+#    #+#             */
/*   Updated: 2026/11/25 22:11:42 by joschmun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *stack)
{
	int	i;
	int	size_b;

	size_b = stack_size(stack->b);
	if (size_b == 0)
		return ;
	i = stack_size(stack->a);
	while (i > 0)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[0] = stack->b[0];
	i = 0;
	while (i < size_b - 1)
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	stack->b[size_b - 1] = 0;
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack *stack)
{
	int	i;
	int	size_a;

	size_a = stack_size(stack->a);
	if (size_a == 0)
		return ;
	i = stack_size(stack->b);
	while (i > 0)
	{
		stack->b[i] = stack->b[i - 1];
		i--;
	}
	stack->b[0] = stack->a[0];
	i = 0;
	while (i < size_a - 1)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	stack->a[size_a - 1] = 0;
	ft_putstr_fd("pb\n", 1);
}


