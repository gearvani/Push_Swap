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
# include <limits.h>
# include "libft.h"

typedef struct s_bench
{
	bool	enabled;
	double	disorder;
	char	*strategy;
	char	*complexity;
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
}	t_bench;

typedef enum e_mode
{
	MODE_NONE,
	MODE_ADAPTIVE,
	MODE_SIMPLE,
	MODE_MEDIUM,
	MODE_COMPLEX
}	t_mode;

typedef struct s_stack
{
	char	**temp;
	int		*a;
	int		*b;
	int		size;
	t_bench	bench;
	t_mode	mode;
}	t_stack;

//cleanup.c
int		cleanup_on_failure(t_stack *stack);
void	cleanup(t_stack *stack);

//error.c
int		error_msg_int(char *msg);
char	*error_msg_pointer(char *msg);
void	error_msg(char *msg);

//radix_sort.c
void	radix_sort(t_stack *stack);

//init.c
int		init_stacks(t_stack *stack);

//utils.c
void	index_stack(t_stack *stack);
int		stack_size(int *stack);
int		validate_args(t_stack *stack);


//swap.c
void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack);

//push.c
void	pa(t_stack *stack);
void	pb(t_stack *stack);

//rotate.c
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *stack);

//reverse_rotate.c
void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *stack);

//selection_sort.c & bubble_sort.c
void	selection_sort(t_stack *stack);
void	bubble_sort(t_stack *stack);

//parser.c
int	parse_args(t_stack *stack, int argc, char **argv);

//disorder.c
double	compute_disorder(t_stack *stack);

//bench.c
void	print_bench(t_bench *bench);

#endif