/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_nums_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvespin <alvespin@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 16:30:52 by alvespin          #+#    #+#             */
/*   Updated: 2026/06/05 16:31:20 by alvespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_num_in_arr(int *arr, int size, int num)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == num)
			return (1);
		i++;
	}
	return (0);
}

int	check_num_arr(int *num_arr, int size)
{
	int	*aux_arr;
	int	i;
	int	j;	

	i = 0;
	j = 0;
	aux_arr = (int *)calloc(size, sizeof(int));
	if (!aux_arr)
		return (0);
	while (i < size)
	{
		if (num_arr[i] == 0 || ft_num_in_arr(aux_arr, size, num_arr[i]) == 1)
			return (free(aux_arr), 0);
		else
			aux_arr[j++] = num_arr[i];
		i++;
	}
	free(aux_arr);
	return (1);
}
