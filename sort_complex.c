/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvespin <alvespin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 12:18:39 by alvespin          #+#    #+#             */
/*   Updated: 2026/05/22 12:18:40 by alvespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_two_elements(t_stack *a, t_stack *b, int pos1, int pos2)
{
	int	t1;
	int	t2;

	if (pos1 != pos2)
	{
		while (a->top > pos2)
			pb(a, b);
		t1 = pop(a);
		while (a->top > pos1)
			pb(a, b);
		t2 = pop(a);
		push(a, t1);
		while (a->top < pos2 - 1)
			pa(a, b);
		push(a, t2);
		while (!is_stack_empty(b))
			pa(a, b);
	}
}

static int	partition(t_stack *a, t_stack *b, int low, int high)
{
	int	p;
	int	i;
	int	j;

	p = a->arr[low];
	i = low;
	j = high;
	while (i < j)
	{
		while (a->arr[i] > p && i <= high - 1)
			i++;
		while (a->arr[j] <= p && j >= low + 1)
			j--;
		if (i < j)
		{
			swap_two_elements(a, b, i, j);
		}
	}
	swap_two_elements(a, b, i, high);
	return (i);
}

static void	quick_sort(t_stack *a, t_stack *b, int low, int high)
{
	int	part;

	if (low < high)
	{
		part = partition(a, b, low, high);
		quick_sort(a, b, low, part - 1);
		quick_sort(a, b, part, high);
	}
}

void	sort_complex(t_stack *a, t_stack *b)
{
	quick_sort(a, b, 0, a->top);
}

/*
Functions in reverse order

static int	partition(t_stack *a, t_stack *b, int low, int high)
{
	int	p;
	int	i;
	int	j;

	p = a->arr[low];
	i = low;
	j = high;
	while (i < j)
	{
		while (a->arr[i] <= p && i <= high - 1)
			i++;
		while (a->arr[j] > p && j >= low + 1)
			j--;
		if (i < j)
			swap_two_elements(a, b, i, j);
	}
	swap_two_elements(a, b, low, j);
	return (j);
}

static void	quick_sort(t_stack *a, t_stack *b, int low, int high)
{
	int	part;

	if (low < high)
	{
		part = partition(a, b, low, high);
		quick_sort(a, b, low, part);
		quick_sort(a, b, part + 1, high);
	}
}
*/
