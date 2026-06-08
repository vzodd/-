/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvilch <jorvilch@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 10:52:13 by jorvilch          #+#    #+#             */
/*   Updated: 2026/06/02 10:52:35 by jorvilch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void	sort_array(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
			j++;
		}
		i++;
	}
}

static int	find_index(int *sorted, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (sorted[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

void	normalize_stack(t_stack *a)
{
	int	*sorted;
	int	size;
	int	i;

	size = a->top + 1;
	sorted = malloc(sizeof(int) * size);
	if (!sorted)
		return ;
	i = 0;
	while (i < size)
	{
		sorted[i] = a->arr[i];
		i++;
	}
	sort_array(sorted, size);
	i = 0;
	while (i < size)
	{
		a->arr[i] = find_index(sorted, size, a->arr[i]);
		i++;
	}
	free(sorted);
}
