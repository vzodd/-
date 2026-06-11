/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/* sort_medium.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/* By: jorvilch <jorvilch@student.42malaga.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/* Created: 2026/05/22 11:56:37 by jorvilch          #+#    #+#              */
/* Updated: 2026/06/11 00:00:00 by jorvilch         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_chunk_size(int total_size)
{
	if (total_size <= 16)
		return (8);
	if (total_size <= 100)
		return (20);
	return (50);
}

static void	push_chunks_to_b(t_stack *a, t_stack *b)
{
	int	chunk_size;
	int	threshold;
	int	min;
	int	max;
	int	i;
	int	rotations;

	chunk_size = get_chunk_size(a->size);
	min = a->arr[0];
	max = a->arr[0];
	i = 1;
	while (i <= a->top)
	{
		if (a->arr[i] < min)
			min = a->arr[i];
		if (a->arr[i] > max)
			max = a->arr[i];
		i++;
	}
	threshold = min + chunk_size;
	while (a->top >= 0)
	{
		rotations = a->top + 1;
		while (rotations-- > 0 && a->arr[a->top] > threshold)
			ra(a);
		if (a->arr[a->top] <= threshold)
		{
			pb(a, b);
			if (b->top > 0 && b->arr[b->top] < threshold - chunk_size / 2)
				rb(b, a);
		}
		else
			threshold += chunk_size;
	}
}

static int	find_max_idx(t_stack *b)
{
	int	max_val;
	int	max_idx;
	int	i;

	i = 0;
	max_val = b->arr[0];
	max_idx = 0;
	while (i <= b->top)
	{
		if (b->arr[i] > max_val)
		{
			max_val = b->arr[i];
			max_idx = i;
		}
		i++;
	}
	return (max_idx);
}

static void	rotate_b_to_max(t_stack *a, t_stack *b)
{
	int	max_idx;
	int	steps_rb;
	int	steps_rrb;

	max_idx = find_max_idx(b);
	steps_rb = b->top - max_idx;
	steps_rrb = max_idx + 1;
	if (steps_rb <= steps_rrb)
		while (steps_rb-- > 0)
			rb(b, a);
	else
		while (steps_rrb-- > 0)
			rrb(b, a);
}

void	sort_medium(t_stack *a, t_stack *b)
{
	push_chunks_to_b(a, b);
	while (b->top >= 0)
	{
		rotate_b_to_max(a, b);
		pa(a, b);
	}
}
