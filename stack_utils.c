/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvilch <jorvilch@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 16:25:56 by jorvilch          #+#    #+#             */
/*   Updated: 2026/06/05 16:25:58 by jorvilch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Initializes the stack
void	init_stack(t_stack *stack, int size)
{
	stack->top = -1;
	stack->size = size;
	stack->arr = (int *)malloc(size * sizeof(int));
}

// Free the data stored in the stack
void	free_stack(t_stack *stack)
{
	free(stack->arr);
}

static int	get_max(int n1, int n2)
{
	if (n1 > n2)
		return (n1);
	else
		return (n2);
}

// Print the two stacks
void	print_stacks(t_stack *a, t_stack *b)
{
	int		i;
	char	*sep;

	i = get_max(a->top, b->top);
	sep = "    ";
	while (i >= 0)
	{
		if (a->top >= i)
			ft_printf(" %d", a->arr[i]);
		else
			ft_printf("  ");
		ft_printf("%s", sep);
		if (b->top >= i)
			ft_printf(" %d", b->arr[i]);
		else
			ft_printf("  ");
		ft_printf("\n", sep);
		i--;
	}
	ft_printf(" _%s_\n a%sb\n\n", sep, sep);
}
