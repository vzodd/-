/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvilch <jorvilch@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 18:26:48 by alvespin          #+#    #+#             */
/*   Updated: 2026/06/08 08:53:05 by jorvilch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//#include <stdarg.h>
//#include <stdio.h>

int	ft_putfloat(float f)
{
	int	n1;
	int	n2;

	n1 = (int)(f * 100 + .5);
	n2 = ((int)(f * 100 + .5) % 100);
	if (n2 == 0)
		return (ft_printf("%d.0%d", (int)(n1 / 100), n2));
	else
		return (ft_printf("%d.%d", (int)(n1 / 100), n2));
}

/*
int main(int argc, char **argv)
{
    if (argc < 2)
        return (1);
    float ff = atof(argv[1]);
    printf("%.2f\n", ff);
    ft_printf("%f\n", ff);
}*/
