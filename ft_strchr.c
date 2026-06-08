/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvespin <alvespin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 10:28:07 by alvespin          #+#    #+#             */
/*   Updated: 2026/05/13 16:05:50 by alvespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strchr(char const *s, int c)
{
	int		i;
	char	*res;

	i = 0;
	res = (char *)s;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (&res[i]);
		i++;
	}
	if ((char)c == '\0')
		return (&res[i]);
	return (NULL);
}
