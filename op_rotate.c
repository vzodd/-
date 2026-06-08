/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvilch <jorvilch@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 13:23:55 by alvespin          #+#    #+#             */
/*   Updated: 2026/06/05 17:41:19 by jorvilch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rotate(t_stack *s)
{
	int	top;
	int	i;

	if (s->top <= 0)
		return (-1);
	top = peek(s);
	i = s->top;
	while (i >= 0)
	{
		s->arr[i + 1] = s->arr[i];
		i--;
	}
	s->arr[0] = top;
	return (1);
}

void	ra(t_stack *a)
{
	rotate(a);
	stats_count(&((a->stats).ra), &a->stats, "ra");
}

void	rb(t_stack *b, t_stack *a)
{
	rotate(b);
	stats_count(&((a->stats).rb), &a->stats, "rb");
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	stats_count(&((a->stats).rr), &a->stats, "rr");
}
