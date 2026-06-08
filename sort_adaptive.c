/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvilch <jorvilch@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 12:50:08 by jorvilch          #+#    #+#             */
/*   Updated: 2026/05/28 14:39:30 by jorvilch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_adaptive(t_stack *a, t_stack *b, float *disorder)
{
	*disorder = compute_disorder(a);
	if (*disorder < 0.2)
		sort_simple(a, b);
	else if (*disorder < 0.5)
		sort_medium(a, b);
	else
		sort_complex(a, b);
}
