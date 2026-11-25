/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joschmun <joschmun@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 22:51:25 by joschmun          #+#    #+#             */
/*   Updated: 2026/11/25 22:51:56 by joschmun         ###   ########.fr       */
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
