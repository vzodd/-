/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvilch <jorvilch@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 14:49:05 by jorvilch          #+#    #+#             */
/*   Updated: 2026/05/18 15:47:02 by jorvilch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	compute_disorder(t_stack *a)
{
	int	i;
	int	j;
	int	mistakes;
	int	total_pairs;

	i = 0;
	j = 0;
	mistakes = 0;
	total_pairs = 0;
	while (i < a->top)
	{
		j = i + 1;
		while (j <= a->top)
		{
			total_pairs++;
			if (a->arr[i] > a->arr[j])
			{
				mistakes++;
				j++;
			}
		}
		i++;
	}
	return (mistakes / total_pairs);
}
