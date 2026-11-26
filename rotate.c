/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgios-arvanitidis <georgios-arvaniti    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 05:56:13 by georgios-ar       #+#    #+#             */
/*   Updated: 2026/11/26 05:56:15 by georgios-ar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack)
{
	int	tmp;
	int	i;
	int	size;

	size = stack_size(stack->a);
	if (size < 2)
		return ;
	tmp = stack->a[0];
	i = 0;
	while (i < size - 1)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	stack->a[size - 1] = tmp;
	ft_putstr_fd("ra\n", 1);
	stack->bench.ra++;
}

void	rb(t_stack *stack)
{
	int	tmp;
	int	i;
	int	size;

	size = stack_size(stack->b);
	if (size < 2)
		return ;
	tmp = stack->b[0];
	i = 0;
	while (i < size - 1)
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	stack->b[size - 1] = tmp;
	ft_putstr_fd("rb\n", 1);
	stack->bench.rb++;
}

static void	_ra(t_stack *stack)
{
	int	tmp;
	int	i;
	int	size;

	size = stack_size(stack->a);
	if (size < 2)
		return ;
	tmp = stack->a[0];
	i = 0;
	while (i < size - 1)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	stack->a[size - 1] = tmp;
	ft_putstr_fd("ra\n", 1);
}

static void	_rb(t_stack *stack)
{
	int	tmp;
	int	i;
	int	size;

	size = stack_size(stack->b);
	if (size < 2)
		return ;
	tmp = stack->b[0];
	i = 0;
	while (i < size - 1)
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	stack->b[size - 1] = tmp;
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack *stack)
{
	_ra(stack);
	_rb(stack);
	ft_putstr_fd("rr\n", 1);
	stack->bench.rr++;
}
