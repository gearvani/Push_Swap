/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgios-arvanitidis <georgios-arvaniti    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 19:43:49 by georgios-ar       #+#    #+#             */
/*   Updated: 2026/11/24 20:00:10 by georgios-ar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_stack *stack)
{
	int	tmp;
	int	i;
	int	size;

	size = _size(stack->b);
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
	ra(stack);
	rb(stack);
	ft_putstr_fd("rr\n", 1);
}

void	rra(t_stack *stack)
{
	int	tmp;
	int	i;
	int	size;

	size = _size(stack->a);
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
}

void	rrb(t_stack *stack)
{
	int	tmp;
	int	i;
	int	size;

	size = _size(stack->b);
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
}
