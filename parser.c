/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgios-arvanitidis <georgios-arvaniti    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 05:55:27 by georgios-ar       #+#    #+#             */
/*   Updated: 2026/11/26 05:55:29 by georgios-ar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	_set_flag(t_stack *stack, char *arg)
{
	if (ft_strncmp(arg, "--bench", 8) == 0 && !stack->bench.enabled)
		stack->bench.enabled = true;
	else if (ft_strncmp(arg, "--simple", 9) == 0 && !stack->mode)
		stack->mode = MODE_SIMPLE;
	else if (ft_strncmp(arg, "--medium", 9) == 0 && !stack->mode)
		stack->mode = MODE_MEDIUM;
	else if (ft_strncmp(arg, "--complex", 10) == 0 && !stack->mode)
		stack->mode = MODE_COMPLEX;
	else if (ft_strncmp(arg, "--adaptive", 11) == 0 && !stack->mode)
		stack->mode = MODE_ADAPTIVE;
	else
		return (error_msg_int("Error\n"));
	return (0);
}

static int	_parse_flags(t_stack *stack, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc && ft_strncmp(argv[i], "--", 2) == 0)
	{
		if (_set_flag(stack, argv[i]) == -1)
			return (-1);
		i++;
	}
	if (stack->mode == MODE_NONE)
		stack->mode = MODE_ADAPTIVE;
	return (i);
}

static char	**_copy_args(char **argv, int start, int argc)
{
	char	**temp;
	int		i;

	temp = ft_calloc((argc - start) + 1, sizeof(char *));
	if (!temp)
		return (NULL);
	i = 0;
	while (start + i < argc)
	{
		temp[i] = ft_strdup(argv[start + i]);
		if (!temp[i])
			return (NULL);
		i++;
	}
	return (temp);
}

int	parse_args(t_stack *stack, int argc, char **argv)
{
	int	start;

	start = _parse_flags(stack, argc, argv);
	if (start == -1)
		return (-1);
	if (start >= argc)
		return (1);
	if (argc - start == 1)
		stack->temp = ft_split(argv[start], ' ');
	else
		stack->temp = _copy_args(argv, start, argc);
	if (!stack->temp || !stack->temp[0])
		return (-1);
	while (stack->temp[stack->size])
		stack->size++;
	return (0);
}
