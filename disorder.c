/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgios-arvanitidis <georgios-arvaniti    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 05:54:48 by georgios-ar       #+#    #+#             */
/*   Updated: 2026/11/26 05:54:50 by georgios-ar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	compute_disorder(t_stack *stack)
{
	int	i;
	int	j;
	int	mistakes;
	int	total;

	if (stack->size < 2)
		return (0.0);
	mistakes = 0;
	total = 0;
	i = 0;
	while (i < stack->size - 1)
	{
		j = i + 1;
		while (j < stack->size)
		{
			if (stack->a[i] > stack->a[j])
				mistakes++;
			total++;
			j++;
		}
		i++;
	}
	return ((double)mistakes / (double)total);
}
