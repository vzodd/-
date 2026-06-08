/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvespin <alvespin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 13:33:22 by alvespin          #+#    #+#             */
/*   Updated: 2026/05/19 16:50:48 by alvespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

static void	ft_putnbr_rec(int nb, int *total)
{
	long int	n;

	n = nb;
	if (n < 0)
	{
		n = n * (-1);
		*total += ft_putchar('-');
	}
	if (n >= 10)
		ft_putnbr_rec(n / 10, total);
	*total += ft_putchar(n % 10 + '0');
}

static int	ft_putnbr(int nb)
{
	int	total;

	total = 0;
	ft_putnbr_rec(nb, &total);
	return (total);
}

static int	print_elements(char const *s, size_t i, va_list *arg_list)
{
	if (s[i] == 'd')
		return (ft_putnbr(va_arg(*arg_list, int)));
	else if (s[i] == 's')
		return (ft_putstr(va_arg(*arg_list, char *)));
	else if (s[i] == 'f')
		return (ft_putfloat(va_arg(*arg_list, double)));
	else
		return (0);
}

int	ft_printf(char const *s, ...)
{
	va_list		arg_list;
	size_t		i;
	size_t		total;

	va_start(arg_list, s);
	i = 0;
	total = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			total += print_elements(s, i, &arg_list);
		}
		else
			total += ft_putchar(s[i]);
		i++;
	}
	va_end(arg_list);
	return (total);
}
