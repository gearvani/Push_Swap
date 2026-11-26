/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgios-arvanitidis <georgios-arvaniti    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 05:56:34 by georgios-ar       #+#    #+#             */
/*   Updated: 2026/11/26 05:56:36 by georgios-ar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack)
{
	int	tmp;

	if (stack_size(stack->a) < 2)
		return ;
	tmp = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = tmp;
	ft_putstr_fd("sa\n", 1);
	stack->bench.sa++;
}

void	sb(t_stack *stack)
{
	int	tmp;

	if (stack_size(stack->b) < 2)
		return ;
	tmp = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = tmp;
	ft_putstr_fd("sb\n", 1);
	stack->bench.sb++;
}

static void	_sa(t_stack *stack)
{
	int	tmp;

	if (stack_size(stack->a) < 2)
		return ;
	tmp = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = tmp;
	ft_putstr_fd("sa\n", 1);
}

static void	_sb(t_stack *stack)
{
	int	tmp;

	if (stack_size(stack->b) < 2)
		return ;
	tmp = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = tmp;
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack *stack)
{
	_sa(stack);
	_sb(stack);
	ft_putstr_fd("ss\n", 1);
	stack->bench.ss++;
}
