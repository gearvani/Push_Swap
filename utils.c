/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgios-arvanitidis <georgios-arvaniti    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 15:31:03 by georgios-ar       #+#    #+#             */
/*   Updated: 2026/11/24 15:31:03 by georgios-ar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_stack(t_stack *stack)
{
	int	pos_x;
	int	pos_y;
	int	counter;

	pos_x = 0;
	pos_y = 0;
	counter = 0;
	while (stack->temp[pos_x])
	{
		while (stack->temp[pos_y])
		{
			if (ft_atoi(stack->temp[pos_x]) >= ft_atoi(stack->temp[pos_y]))
				counter++;
			pos_y++;
		}
		stack->a[pos_x] = counter;
		pos_x++;
		pos_y = 0;
		counter = 0;
	}
}
