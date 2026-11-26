/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgios-arvanitidis <georgios-arvaniti    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 05:52:23 by georgios-ar       #+#    #+#             */
/*   Updated: 2026/11/26 05:54:14 by georgios-ar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	_print_disorder(double disorder)
{
	int	scaled;
	int	whole;
	int	dec;

	scaled = (int)(disorder * 10000.0 + 0.5);
	whole = scaled / 100;
	dec = scaled % 100;
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putnbr_fd(whole, 2);
	ft_putchar_fd('.', 2);
	if (dec < 10)
		ft_putchar_fd('0', 2);
	ft_putnbr_fd(dec, 2);
	ft_putstr_fd("%\n", 2);
}

static void	_print_ops_part1(t_bench *bench)
{
	ft_putstr_fd("[bench] sa: ", 2);
	ft_putnbr_fd(bench->sa, 2);
	ft_putstr_fd(" sb: ", 2);
	ft_putnbr_fd(bench->sb, 2);
	ft_putstr_fd(" ss: ", 2);
	ft_putnbr_fd(bench->ss, 2);
	ft_putstr_fd(" pa: ", 2);
	ft_putnbr_fd(bench->pa, 2);
	ft_putstr_fd(" pb: ", 2);
	ft_putnbr_fd(bench->pb, 2);
	ft_putchar_fd('\n', 2);
}

static void	_print_ops_part2(t_bench *bench)
{
	ft_putstr_fd("[bench] ra: ", 2);
	ft_putnbr_fd(bench->ra, 2);
	ft_putstr_fd(" rb: ", 2);
	ft_putnbr_fd(bench->rb, 2);
	ft_putstr_fd(" rr: ", 2);
	ft_putnbr_fd(bench->rr, 2);
	ft_putstr_fd(" rra: ", 2);
	ft_putnbr_fd(bench->rra, 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(bench->rrb, 2);
	ft_putstr_fd(" rrr: ", 2);
	ft_putnbr_fd(bench->rrr, 2);
	ft_putchar_fd('\n', 2);
}

void	print_bench(t_bench *bench)
{
	int	total;

	total = bench->sa + bench->sb + bench->ss + bench->pa + bench->pb
		+ bench->ra + bench->rb + bench->rr + bench->rra + bench->rrb
		+ bench->rrr;
	_print_disorder(bench->disorder);
	ft_putstr_fd("[bench] strategy: ", 2);
	ft_putstr_fd(bench->strategy, 2);
	ft_putstr_fd(" / ", 2);
	ft_putstr_fd(bench->complexity, 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(total, 2);
	ft_putchar_fd('\n', 2);
	_print_ops_part1(bench);
	_print_ops_part2(bench);
}
