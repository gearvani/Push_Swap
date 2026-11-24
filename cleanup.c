/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgios-arvanitidis <georgios-arvaniti    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 15:29:45 by georgios-ar       #+#    #+#             */
/*   Updated: 2026/11/24 15:29:45 by georgios-ar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cleanup_on_failure(t_stack *stack)
{
	int	i;

	if (!stack)
		return (-1);
	if (stack->temp)
	{
		i = 0;
		while (stack->temp[i])
		{
			free(stack->temp[i]);
			i++;
		}
		free(stack->temp);
	}
	if (stack->a)
		free(stack->a);
	if (stack->b)
		free(stack->b);
	return (-1);
}

void	cleanup(t_stack *stack)
{
	int	i;

	if (!stack)
		return ;
	if (stack->temp)
	{
		i = 0;
		while (stack->temp[i])
		{
			free(stack->temp[i]);
			i++;
		}
		free(stack->temp);
	}
	if (stack->a)
		free(stack->a);
	if (stack->b)
		free(stack->b);
}
