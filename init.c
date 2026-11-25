/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgios-arvanitidis <georgios-arvaniti    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 15:30:15 by georgios-ar       #+#    #+#             */
/*   Updated: 2026/11/24 15:30:15 by georgios-ar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_stacks(t_stack *stack)
{
	stack->a = ft_calloc(stack->size + 1, sizeof(int));
	if (!stack->a)
		return (-1);
	stack->b = ft_calloc(stack->size + 1, sizeof(int));
	if (!stack->b)
		return (-1);
	return (0);
}