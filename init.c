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

static	char	**_save_temp_stack(char **argv, int argc)
{
	char	**temp_stack;
	int		i;

	i = 0;
	temp_stack = malloc((argc * sizeof(char *)) - 1);
	if (!temp_stack)
		return (NULL);
	temp_stack[argc - 2] = NULL;
	while (argv[i + 1])
	{
		temp_stack[i] = ft_strdup(argv[i + 1]);
		i++;
	}
	return (temp_stack);
}

static int	_init_stack(t_stack *stack)
{
	stack ->a = ft_calloc(stack->size + 1, sizeof(int));
	if (!stack->a)
		return (-1);
	stack->b = ft_calloc(stack->size + 1, sizeof(int));
	if (!stack->b)
	{
		return (-1);
	}
	return (0);
}

static int	_split_stack(char **argv, t_stack *stack)
{
	stack->temp = ft_split(argv[1], ' ');
	if (!stack->temp)
		return (-1);
	while (stack->temp[stack->size])
		stack->size++;
	if (stack->size < 3)
		return (error_msg_int("error: stack too small\n"));
	return (0);
}

int	init(t_stack *stack, int argc, char **argv)
{
	if (argc == 2)
	{
		if (_split_stack(argv, stack) == -1)
			return (-1);
	}
	if (argc == 3)
		return (error_msg_int("error: stack too small\n"));
	if (argc > 3)
	{
		stack->temp = _save_temp_stack(argv, argc);
		if (!stack->temp)
			return (-1);
	}
	if (_init_stack(stack))
		return (-1);
	return (0);
}
