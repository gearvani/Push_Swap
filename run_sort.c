/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joschmun <joschmun@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/27 19:02:01 by joschmun          #+#    #+#             */
/*   Updated: 2026/11/27 20:15:39 by joschmun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	run_simple(t_stack *stack)
{
		if (stack->size == 2)
			sort_two(stack);
		else if (stack->size == 3)
			sort_three(stack);
		else
			selection_sort(stack);
}

void	run_medium(t_stack *stack)
{
		if (stack->size == 2)
			sort_two(stack);
		else if (stack->size == 3)
			sort_three(stack);
		else
			chunk_sort(stack);
}

void	run_complex(t_stack *stack)
{
		if (stack->size == 2)
			sort_two(stack);
		else if (stack->size == 3)
			sort_three(stack);
		else if (stack->size == 4)
			sort_four(stack);
		else
			radix_sort(stack);
}
