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

#include <stdlib.h>
#include <stdio.h>

static char **_save_stack(char **argv, int argc)
{
	char **stack;
	int i;

	i = 0;
	stack = malloc((argc * sizeof(char *)) - 1);
	if (!stack)
		return (0);
	stack[argc - 2] = NULL;
	while (argv[i + 1])
	{
		stack[i] = ft_strdup(argv[i + 1]);
		i++;
	}
	return (stack);
}

int main(int argc, char **argv)
{
	char **stack;
	int i;

	i = 0;
	if (argc == 2)
	{
		stack = ft_split(argv[1], ' ');
		while (stack[i])
			i++;
		if (i < 3)
			return (0);
	}
	if (argc == 3)
		return (0);
	if (argc > 3)
		stack = _save_stack(argv, argc);
}
