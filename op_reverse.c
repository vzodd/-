/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvilch <jorvilch@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 13:23:49 by jorvilch          #+#    #+#             */
/*   Updated: 2026/06/05 18:00:49 by jorvilch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	reverse_rotate(t_stack *s)
{
	int	first;
	int	i;

	if (s->top <= 0)
		return (-1);
	first = s->arr[s->top - 1];
	i = s->top - 1;
	while (i > 0)
	{
		s->arr[i] = s->arr[i - 1];
		i--;
	}
	s->arr[0] = first;
	return (1);
}

void	rra(t_stack *a)
{
	reverse_rotate(a);
	stats_count(&((a->stats).rra), &a->stats, "rra");
}

void	rrb(t_stack *b, t_stack *a)
{
	reverse_rotate(b);
	stats_count(&((a->stats).rrb), &a->stats, "rrb");
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	stats_count(&((a->stats).rrr), &a->stats, "rrr");
}
