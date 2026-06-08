/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvespin <alvespin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 15:34:36 by alvespin          #+#    #+#             */
/*   Updated: 2026/05/20 11:50:00 by alvespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	stack_nums(t_stack *s, int *num_arr, int size)
{
	int	i;

	i = size - 1;
	while (i >= 0)
	{
		if (push(s, num_arr[i]) == -1)
			return (0);
		i--;
	}
	return (1);
}

static int	parse_flags(int argc, char **argv, int *start, int *bench)
{
	int	i;
	int	mode;

	i = 1;
	mode = 0;
	while (i < argc && argv[i][0] == '-' && argv[i][1] == '-')
	{
		if (ft_strncmp(argv[i], "--bench", 10) == 0)
			*bench = 1;
		else if (ft_strncmp(argv[i], "--simple", 10) == 0)
			mode = 1;
		else if (ft_strncmp(argv[i], "--medium", 10) == 0)
			mode = 2;
		else if (ft_strncmp(argv[i], "--complex", 10) == 0)
			mode = 3;
		i++;
	}
	*start = i;
	return (mode);
}

static int	setup_stacks(int argc, char **argv, t_stack *a, t_stack *b)
{
	int	*num_arr;
	int	start;
	int	mode;
	int	bench;
	int	size;

	start = 0;
	bench = 0;
	size = 0;
	mode = parse_flags(argc, argv, &start, &bench);
	num_arr = parse_nums(argc, argv, start, &size);
	if (!num_arr)
		return (-1);
	init_stack(a, size);
	init_stats(&a->stats);
	stack_nums(a, num_arr, size);
	free(num_arr);
	if (bench == 1)
		activate_stats(&a->stats);
	init_stack(b, size);
	return (mode);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		mode;
	float	dis;

	if (argc < 2)
		return (1);
	mode = setup_stacks(argc, argv, &a, &b);
	dis = 0.0;
	if (mode == 1)
		sort_simple(&a, &b);
	else if (mode == 2)
		sort_medium(&a, &b);
	else if (mode == 3)
		sort_complex(&a, &b);
	else if (mode == 0)
		sort_adaptive(&a, &b, &dis);
	if (is_active(&a.stats))
		print_results(&a.stats, mode, dis);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
