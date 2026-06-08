/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvilch <jorvilch@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 11:56:37 by jorvilch          #+#    #+#             */
/*   Updated: 2026/06/08 09:04:59 by jorvilch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_max_pos(t_stack *b)
{
	int	max;
	int	max_pos;
	int	i;

	max = b->arr[0];
	max_pos = 0;
	i = 1;
	while (i <= b->top)
	{
		if (b->arr[i] > max)
		{
			max = b->arr[i];
			max_pos = i;
		}
		i++;
	}
	return (max_pos);
}

static void	move_max_to_top(t_stack *b, t_stack *a)
{
	int	pos;
	int	size;

	pos = find_max_pos(b);
	size = b->top + 1;
	if (pos <= size / 2)
	{
		pos = size - pos;
		while (pos-- > 0)
			rrb(b, a);
	}
	else
		while (pos-- > 0)
			rb(b, a);
}

static void	push_chunks(t_stack *a, t_stack *b,
	int chunk_min, int chunk_max)
{
	int	size;
	int	i;

	while (1)
	{
		size = a->top + 1;
		i = size - 1;
		while (i >= 0 && (a->arr[i] < chunk_min || a->arr[i] > chunk_max))
			i--;
		if (i < 0)
			break ;
		if (i >= size / 2)
			while (peek(a) < chunk_min || peek(a) > chunk_max)
				ra(a);
		else
			while (peek(a) < chunk_min || peek(a) > chunk_max)
				rra(a);
		pb(a, b);
		if (peek(b) < chunk_min + (chunk_max - chunk_min) / 2)
			rb(b, a);
	}
}

static void	push_to_a(t_stack *a, t_stack *b)
{
	while (b->top >= 0)
	{
		move_max_to_top(b, a);
		pa(a, b);
	}
}

void	sort_medium(t_stack *a, t_stack *b)
{
	int	size;
	int	chunk_size;
	int	chunk_min;
	int	chunk_max;

	size = a->top + 1;
	normalize_stack(a);
	chunk_size = (int)sqrt((double)size);
	if (chunk_size < 1)
		chunk_size = 1;
	chunk_min = 0;
	while (chunk_min < size)
	{
		chunk_max = chunk_min + chunk_size - 1;
		if (chunk_max >= size)
			chunk_max = size - 1;
		push_chunks(a, b, chunk_min, chunk_max);
		chunk_min += chunk_size;
	}
	push_to_a(a, b);
}
