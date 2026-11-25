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

static void	_run_adaptive(t_stack *stack)
{
	if (stack->bench.disorder < 0.2)
	{
		stack->bench.strategy = "Adaptive (Simple)";
		stack->bench.complexity = "O(n^2)";
		selection_sort(stack);
	}
	else if (stack->bench.disorder < 0.5)
	{
		stack->bench.strategy = "Adaptive (Medium)";
		stack->bench.complexity = "O(n*sqrt(n))";
		selection_sort(stack);
	}
	else
	{
		stack->bench.strategy = "Adaptive (Complex)";
		stack->bench.complexity = "O(n log n)";
		radix_sort(stack);
	}
}

static void	_run_strategy(t_stack *stack)
{
	if (stack->mode == MODE_SIMPLE)
	{
		stack->bench.strategy = "Simple";
		stack->bench.complexity = "O(n^2)";
		selection_sort(stack);
	}
	else if (stack->mode == MODE_MEDIUM)
	{
		stack->bench.strategy = "Medium";
		stack->bench.complexity = "O(n*sqrt(n))";
		selection_sort(stack);
	}
	else if (stack->mode == MODE_COMPLEX)
	{
		stack->bench.strategy = "Complex";
		stack->bench.complexity = "O(n log n)";
		radix_sort(stack);
	}
	else
		_run_adaptive(stack);
}

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
				return (error_msg_int("Error\n"));
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
	return (error_msg_int("Error\n"));
}

int	main(int argc, char **argv)
{
	t_stack	stack;
	int		res;

	ft_bzero(&stack, sizeof(t_stack));
	res = parse_args(&stack, argc, argv);
	if (res == 1)
		return (0);
	if (res == -1 || init_stacks(&stack) == -1)
		return (cleanup_on_failure(&stack));
	if (_check_dup(&stack) == -1)
		return (cleanup_on_failure(&stack));
	index_stack(&stack);
	stack.bench.disorder = compute_disorder(&stack);
	if (_is_sorted(&stack) == -1)
		return (cleanup_on_failure(&stack));
	_run_strategy(&stack);
	if (stack.bench.enabled)
		print_bench(&stack.bench);
	cleanup(&stack);
	return (0);
}
