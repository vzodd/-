/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvilch <jorvilch@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 12:47:41 by jorvilch          #+#    #+#             */
/*   Updated: 2026/06/05 16:38:14 by jorvilch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	if (is_stack_empty(b))
		return ;
	push(a, pop(b));
	stats_count(&((a->stats).pa), &a->stats, "pa");
}

void	pb(t_stack *a, t_stack *b)
{
	if (is_stack_empty(a))
		return ;
	push(b, pop(a));
	stats_count(&((a->stats).pb), &a->stats, "pb");
}
