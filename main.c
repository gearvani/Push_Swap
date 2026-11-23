/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgios-arvanitidis <georgios-arvaniti    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 15:31:41 by georgios-ar       #+#    #+#             */
/*   Updated: 2026/11/23 16:35:55 by georgios-ar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char **_save_temp_stack(char **argv, int argc)
{
	char **temp_stack;
	int i;

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

static int *_index_stack(char **temp_stack, int stack_size)
{
	int *stack_a;
	int pos_x;
	int pos_y;
	int counter;

	pos_x = 0;
	pos_y = 0;
	counter = 0;
	stack_a = malloc(stack_size * sizeof(int) + 1);
	if (!stack_a)
		return (0);
	stack_a[stack_size] = 0;
	while(temp_stack[pos_x])
	{
		while (temp_stack[pos_y])
		{
			if (ft_atoi(temp_stack[pos_x]) >= ft_atoi(temp_stack[pos_y]))
				counter++;
			pos_y++;
		}
		stack_a[pos_x] = counter;
		pos_x++;
		pos_y = 0;
		counter = 0;
	}
	return (stack_a);
}

static bool _check_dup(char **temp_stack)
{
	int pos_x;
	int pos_y;

	pos_x = 0;
	pos_y = 0;
	while(temp_stack[pos_x])
	{
		while (temp_stack[pos_y])
		{
			if (ft_atoi(temp_stack[pos_x]) == ft_atoi(temp_stack[pos_y]) && pos_x != pos_y)
				return (true);
			pos_y++;
		}
		pos_x++;
		pos_y = 0;
	}
	return (false);
}

static bool _is_sorted(int *stack_a)
{
	int i;

	i = 0;
	while (stack_a[i + 1])
	{
		if (stack_a[i] > stack_a[i + 1])
			return (false);
		i++;
	}
	return(true);
}

int main(int argc, char **argv)
{
	char **temp_stack;
	int *stack_a;
	int *stack_b;
	int stack_size;

	stack_size = 0;
	if (argc == 2)
	{
		temp_stack = ft_split(argv[1], ' ');
		if (!temp_stack)
			return (-1);
		while (temp_stack[stack_size])
			stack_size++;
		if (stack_size < 3)
			return (0);
	}
	if (argc == 3)
		return (0);
	if (argc > 3)
	{
		temp_stack = _save_temp_stack(argv, argc);
		if (!temp_stack)
			return (-1);
	}
	if (_check_dup(temp_stack))
        {
        printf("error: has_dup\n");
		return(-1);
        }
	stack_a = _index_stack(temp_stack, stack_size);
	if (!stack_a)
	{
		//cleanup funktion
		return (-1);
	}
	stack_b = malloc(stack_size * sizeof(int) + 1);
	if (!stack_b)
	{
		//cleanup funktion
		return (-1);
	}
    if (_is_sorted(stack_a))
    {
        printf("error: is_sorted\n");
        return (-1);
    }
}
