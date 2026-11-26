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

int	stack_size(int *stack)
{
	int	i;

	i = 0;
	while (stack[i])
		i++;
	return (i);
}

int	_is_valid_number(char *str)
{
	int	i;

	if (!str || !*str)
		return (0);
	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	_safe_atoi(char *str, long *out)
{
	long	res;
	int		sign;
	int		i;

	res = 0;
	sign = 1;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		if (res > (LONG_MAX - (str[i] - '0')) / 10)
			return (-1);
		res = res * 10 + (str[i] - '0');
		i++;
	}
	res *= sign;
	if (res > INT_MAX || res < INT_MIN)
		return (-1);
	*out = res;
	return (0);
}

int	validate_args(t_stack *stack)
{
	int		i;
	long	val;

	i = 0;
	while (stack->temp[i])
	{
		if (!_is_valid_number(stack->temp[i]))
			return (error_msg_int("Error\n"));
		if (_safe_atoi(stack->temp[i], &val) == -1)
			return (error_msg_int("Error\n"));
		i++;
	}
	return (0);
}
