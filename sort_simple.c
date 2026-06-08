/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvespin <alvespin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 14:56:32 by alvespin          #+#    #+#             */
/*   Updated: 2026/05/19 14:56:34 by alvespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_elements(t_stack *a, t_stack *b, int pos)
{
	int	i;

	i = a->top;
	while (i > pos)
	{
		pb(a, b);
		i--;
	}
	sa(a);
	while (!is_stack_empty(b))
	{
		pa(a, b);
	}
}

void	sort_simple(t_stack *a, t_stack *b)
{
	int	i;
	int	j;
	int	swapped;

	i = a->top;
	while (i >= 0)
	{
		j = a->top;
		swapped = 0;
		while (j > 0)
		{
			if (a->arr[j] > a->arr[j - 1])
			{
				swap_elements(a, b, j);
				swapped = 1;
			}
			j--;
		}
		if (swapped == 0)
			break ;
		i--;
	}
}

/*
void	sort_simple(t_stack *a, t_stack *b)
{
	int	i;
	int	j;
	int	swapped;

	i = 0;
	while (i < a->top)
	{
		j = 0;
		swapped = 0;
		while (j < a->top - i)
		{
			if (a->arr[j] > a->arr[j + 1])
			{
				swap_elements(a, b, j);
				swapped = 1;
			}
			j++;
		}
		if (swapped == 0)
			break ;
		i++;
	}
}*/

/*
swap(arr + j, arr + j + 1);


j = top,	swap(top, top - 1)

5		4								
4		5				
6		6
7		7
3		3

*/
