/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvilch <jorvilch@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 11:05:19 by jorvilch          #+#    #+#             */
/*   Updated: 2026/06/08 08:51:59 by jorvilch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	total_ops(t_stats *stats)
{
	int	total;

	if (!stats)
		return (0);
	total = 0;
	total += stats->sa;
	total += stats->sb;
	total += stats->ss;
	total += stats->pa;
	total += stats->pb;
	total += stats->ra;
	total += stats->rb;
	total += stats->rr;
	total += stats->rra;
	total += stats->rrb;
	total += stats->rrr;
	return (total);
}

/*
void	compute_disorder_dec(int total, int limit)
{
	int		num;
	int		dec;

	num = ((num * 100) / limit);
	dec = ((num * 10000) / limit);
	ft_printf("%d.%02%%\n", num, dec);
}
*/

static char	*get_strategy(int mode, float disorder)
{
	if (mode == 1)
		return ("Simple / O(n²)");
	else if (mode == 2)
		return ("Medium / O(n·√n)");
	else if (mode == 3)
		return ("Complex / O(n·log(n))");
	else
	{
		if (disorder < 0.2)
			return ("Adaptive / O(n²)");
		else if (disorder < 0.5)
			return ("Adaptive / O(n·√n)");
		else
			return ("Adaptive / O(n·log(n))");
	}
}

void	print_results(t_stats *stats, int mode, float disorder)
{
	char	*st;
	int		total;
	float	dis_t;

	total = total_ops(stats);
	st = get_strategy(mode, disorder);
	ft_printf("[bench] disorder:  %f\n%", disorder);
	ft_printf("[bench] strategy:  %s\n", st);
	ft_printf("[bench] total_ops:  %d\n", total);
	ft_printf("[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n", stats->sa,
		stats->sb, stats->ss, stats->pa, stats->pb);
	ft_printf("[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n",
		stats->ra, stats->rb, stats->rr, stats->rra, stats->rrb, stats->rrr);
}
