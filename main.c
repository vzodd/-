/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvilch <jorvilch@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 12:42:06 by alvespin          #+#    #+#             */
/*   Updated: 2026/05/20 12:12:02 by alvespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(void)
{
	t_stack	stack;
	t_stack	b;

	init_stack(&stack);
	init_stack(&b);
	push(&stack, 3);
	push(&stack, 7);
	push(&stack, 6);
	push(&stack, 4);
	push(&stack, 5);
	print_stacks(&stack, &b);
	sort_simple(&stack, &b);
	print_stacks(&stack, &b);
	return (0);
}
