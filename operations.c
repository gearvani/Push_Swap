/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgios-arvanitidis <georgios-arvaniti    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 19:21:15 by georgios-ar       #+#    #+#             */
/*   Updated: 2026/11/24 19:59:38 by georgios-ar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ---------- SWAP ---------- */

void	sa(t_stack *stack)
{
	int	tmp;

	if (_size(stack->a) < 2)
		return ;
	tmp = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = tmp;
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack *stack)
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
	sa(stack);
	sb(stack);
	ft_putstr_fd("ss\n", 1);
}

/* ---------- PUSH ---------- */

void	pa(t_stack *stack)
{
	int	i;
	int	size_b;

	size_b = _size(stack->b);
	if (size_b == 0)
		return ;
	i = _size(stack->a);
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

	size_a = _size(stack->a);
	if (size_a == 0)
		return ;
	i = _size(stack->b);
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

/* ---------- ROTATE ---------- */

void	ra(t_stack *stack)
{
	int	tmp;
	int	i;
	int	size;

	size = _size(stack->a);
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
