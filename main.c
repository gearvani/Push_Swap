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
		run_simple(stack);
	else if (stack->bench.disorder < 0.5)
		run_medium(stack);
	else
		run_complex(stack);
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
		chunk_sort(stack);
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

int	main(int argc, char **argv)
{
	t_stack	stack;
	int		res;

	ft_bzero(&stack, sizeof(t_stack));
	res = parse_args(&stack, argc, argv);
	if (res == 1)
		return (0);
	if (res == -1 || validate_args(&stack) == -1
		|| init_stacks(&stack) == -1)
		return (cleanup_on_failure(&stack));
	if (check_dup(&stack) == -1)
		return (cleanup_on_failure(&stack));
	index_stack(&stack);
	stack.bench.disorder = compute_disorder(&stack);
	if (is_sorted(&stack))
		return (cleanup_on_failure(&stack));
	_run_strategy(&stack);
	if (stack.bench.enabled)
		print_bench(&stack.bench);
	cleanup(&stack);
	return (0);
}
