/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvilch <jorvilch@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 11:56:37 by jorvilch          #+#    #+#             */
/*   Updated: 2026/06/08 11:02:36 by jorvilch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_chunk_size(int total_size)
{
	if (total_size <= 16)
		return (8);
	if (total_size <= 100)
		return (20);
	return (50);
}

void	push_chunks_to_b(t_stack *a, t_stack *b)
{
	int	i;
	int	chunk_size;

	i = 0;
	chunk_size = get_chunk_size(a->size);
	while (a->top >= 0)
	{
		if (a->arr[a->top] <= i)
		{
			pb(a, b);
			i++;
		}
		else if (a->arr[a->top] <= i + chunk_size)
		{
			pb(a, b);
			rb(b, a);
			i++;
		}
		else
			ra(a);
	}
}

int	find_max_pos(t_stack *stack)
{
	int	max_val;
	int	max_pos;
	int	i;

	i = stack->top;
	max_val = stack->arr[i];
	max_pos = i;
	while (i >= 0)
	{
		if (stack->arr[i] > max_val)
		{
			max_val = stack->arr[i];
			max_pos = i;
		}
		i--;
	}
	return (max_pos);
}

void	push_max_to_a(t_stack *a, t_stack *b)
{
	int	max_pos;
	int	steps;

	max_pos = find_max_pos(b);
	if (b->top - max_pos <= b->top / 2)
	{
		steps = b->top - max_pos;
		while (steps > 0)
		{
			rb(b, a);
			steps--;
		}
	}
	else
	{
		steps = max_pos + 1;
		while (steps > 0)
		{
			rrb(b, a);
			steps--;
		}
	}
	pa(a, b);
}

void	sort_medium(t_stack *a, t_stack *b)
{
	push_chunks_to_b(a, b);
	while (b->top >= 0)
	{
		push_max_to_a(a, b);
	}
}
