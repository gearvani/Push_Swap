/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgios-arvanitidis <georgios-arvaniti    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 05:56:03 by georgios-ar       #+#    #+#             */
/*   Updated: 2026/11/26 05:56:06 by georgios-ar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *stack)
{
	int	tmp;
	int	i;
	int	size;

	size = stack_size(stack->a);
	if (size < 2)
		return ;
	tmp = stack->a[size - 1];
	i = size - 1;
	while (i > 0)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[0] = tmp;
	ft_putstr_fd("rra\n", 1);
	stack->bench.rra++;
}

void	rrb(t_stack *stack)
{
	int	tmp;
	int	i;
	int	size;

	size = stack_size(stack->b);
	if (size < 2)
		return ;
	tmp = stack->b[size - 1];
	i = size - 1;
	while (i > 0)
	{
		stack->b[i] = stack->b[i - 1];
		i--;
	}
	stack->b[0] = tmp;
	ft_putstr_fd("rrb\n", 1);
	stack->bench.rrb++;
}

static void	_rra(t_stack *stack)
{
	int	tmp;
	int	i;
	int	size;

	size = stack_size(stack->a);
	if (size < 2)
		return ;
	tmp = stack->a[size - 1];
	i = size - 1;
	while (i > 0)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[0] = tmp;
	ft_putstr_fd("rra\n", 1);
	stack->bench.rra++;
}

static void	_rrb(t_stack *stack)
{
	int	tmp;
	int	i;
	int	size;

	size = stack_size(stack->b);
	if (size < 2)
		return ;
	tmp = stack->b[size - 1];
	i = size - 1;
	while (i > 0)
	{
		stack->b[i] = stack->b[i - 1];
		i--;
	}
	stack->b[0] = tmp;
	ft_putstr_fd("rrb\n", 1);
	stack->bench.rrb++;
}

void	rrr(t_stack *stack)
{
	_rra(stack);
	_rrb(stack);
	ft_putstr_fd("rrr\n", 1);
	stack->bench.rrr++;
}
