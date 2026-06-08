/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvilch <jorvilch@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 14:16:24 by alvespin          #+#    #+#             */
/*   Updated: 2026/06/05 18:21:36 by jorvilch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stats(t_stats *stats)
{
	stats->display = -1;
}

void	activate_stats(t_stats *stats)
{
	stats->display = 1;
	stats->sa = 0;
	stats->sb = 0;
	stats->ss = 0;
	stats->pa = 0;
	stats->pb = 0;
	stats->ra = 0;
	stats->rb = 0;
	stats->rr = 0;
	stats->rra = 0;
	stats->rrb = 0;
	stats->rrr = 0;
}

int	is_active(t_stats *stats)
{
	if (stats->display == -1)
		return (0);
	else
		return (1);
}

void	stats_count(int *counter, t_stats *stats, const char *op_name)
{
	if (is_active(stats))
		(*counter)++;
	else
		ft_printf("%s\n", op_name);
}
