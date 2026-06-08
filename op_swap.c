/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvilch <jorvilch@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 12:17:23 by alvespin          #+#    #+#             */
/*   Updated: 2026/06/05 17:41:39 by jorvilch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	swap(t_stack *s)
{
	int	top1;
	int	top2;

	if (is_stack_empty(s))
		return (-1);
	top1 = pop(s);
	top2 = pop(s);
	if (top1 == -1 || top2 == -1)
		return (-1);
	push(s, top1);
	push(s, top2);
	return (1);
}

void	sa(t_stack *a)
{
	swap(a);
	stats_count(&((a->stats).sa), &a->stats, "sa");
}

void	sb(t_stack *b, t_stack *a)
{
	swap(b);
	stats_count(&((a->stats).sb), &a->stats, "sb");
}

void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	stats_count(&((a->stats).ss), &a->stats, "ss");
}
