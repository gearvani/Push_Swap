/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgios-arvanitidis <georgios-arvaniti    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 15:30:54 by georgios-ar       #+#    #+#             */
/*   Updated: 2026/11/24 15:30:54 by georgios-ar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include "libft.h"

typedef struct s_stack
{
	char	**temp;
	int		*a;
	int		*b;
	int		size;
}	t_stack;

//cleanup.c
int		cleanup_on_failure(t_stack *stack);
void	cleanup(t_stack *stack);

//error.c
int		error_msg_int(char *msg);
char	*error_msg_pointer(char *msg);
void	error_msg(char *msg);

//init.c
int		init(t_stack *stack, int argc, char **argv);

//utils.c
void	index_stack(t_stack *stack);
int	_size(int *stack);
void	rrr(t_stack *stack);

//operations.c & more_operations.c
void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack);
void	pa(t_stack *stack);
void	pb(t_stack *stack);
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *stack);
void	rra(t_stack *stack);
void	rrb(t_stack *stack);

//selection_sort.c
void	selection_sort(t_stack *stack);

#endif