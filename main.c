/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gearvani <gearvani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 18:10:07 by gearvani          #+#    #+#             */
/*   Updated: 2026/11/19 18:12:40 by gearvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	_check_dup(t_stack *stack)
{
	int	pos_x;
	int	pos_y;

	pos_x = 0;
	pos_y = 0;
	while (stack->temp[pos_x])
	{
		while (stack->temp[pos_y])
		{
			if (ft_atoi(stack->temp[pos_x]) == ft_atoi(stack->temp[pos_y])
				&& pos_x != pos_y)
				return (error_msg_int("error: has_dup\n"));
			pos_y++;
		}
		pos_x++;
		pos_y = 0;
	}
	return (0);
}

static int	_is_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack->a[i + 1])
	{
		if (stack->a[i] > stack->a[i + 1])
			return (0);
		i++;
	}
	return (error_msg_int("error: is_sorted\n"));
}

void	debug(t_stack *stack)
{
	int i = 0;
	printf("\n\n=======PUSH SWAP DEBUG========\n\nstack:\n");

	while(stack->a[i])
	{
		printf("%i\n",stack->a[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	stack;

	ft_bzero(&stack, sizeof(t_stack));
	if (init(&stack, argc, argv) == -1)
		return (cleanup_on_failure(&stack));
	if (_check_dup(&stack) == -1)
		return (cleanup_on_failure(&stack));
	index_stack(&stack);
	if (_is_sorted(&stack) == -1)
		return (cleanup_on_failure(&stack));
	if (stack.size <= 5)
		bubble_sort(&stack);
	if (stack.size > 5)
		radix_sort(&stack);
	else
		selection_sort(&stack);
	debug(&stack);
	cleanup(&stack);
}
