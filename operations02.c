/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joschmun <joschmun@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 21:43:56 by joschmun          #+#    #+#             */
/*   Updated: 2026/11/25 21:45:06 by joschmun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	_sa(t_stack *stack)
{
	int	tmp;

	if (_size(stack->a) < 2)
		return ;
	tmp = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = tmp;
	ft_putstr_fd("sa\n", 1);
}

static void	_sb(t_stack *stack)
{
	int	tmp;

	if (_size(stack->b) < 2)
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
}