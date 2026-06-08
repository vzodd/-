/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_nums.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvilch <jorvilch@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 18:23:45 by alvespin          #+#    #+#             */
/*   Updated: 2026/05/25 16:13:21 by jorvilch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_count_words(char const *str, int c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			if (str[i + 1] == c || str[i + 1] == '\0')
				count++;
		}
		i++;
	}
	return (count);
}

static void	free_all(char **splitstr)
{
	int	i;

	i = 0;
	while (splitstr[i] != NULL)
	{
		free(splitstr[i]);
		i++;
	}
	free(splitstr);
}

static int	*read_nums_from_str(char *str, int *size)
{
	char	**arguments;
	int		*num_arr;
	int		i;

	*size = ft_count_words(str, ' ');
	arguments = ft_split(str, *size, ' ');
	num_arr = (int *)malloc(sizeof(int) * (*size));
	i = 0;
	while (i < *size)
	{
		if (ft_is_int(arguments[i]) == 1)
			num_arr[i] = ft_atoi(arguments[i]);
		else
			return (free_all(arguments), NULL);
		i++;
	}
	free_all(arguments);
	return (num_arr);
}

static int	*read_nums_from_argv(char **argv, int argc, int start, int *size)
{
	int	*num_arr;
	int	i;

	*size = argc - start;
	num_arr = (int *)malloc(sizeof(int) * (*size));
	i = 0;
	while (i < *size)
	{
		if (ft_is_int(argv[i + start]) == 1)
			num_arr[i] = ft_atoi(argv[i + start]);
		else
			return (NULL);
		i++;
	}
	return (num_arr);
}

int	*parse_nums(int argc, char **argv, int start, int *size)
{
	int	*num_arr;

	if (ft_strchr(argv[start], ' '))
		num_arr = read_nums_from_str(argv[start], size);
	else
		num_arr = read_nums_from_argv(argv, argc, start, size);
	if (num_arr == NULL)
		ft_exit("Error");
	if (check_num_arr(num_arr, *size) == 0)
	{
		free(num_arr);
		ft_exit("Error");
	}
	return (num_arr);
}
