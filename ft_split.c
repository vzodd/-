/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvespin <alvespin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 15:18:46 by alvespin          #+#    #+#             */
/*   Updated: 2026/05/05 16:26:16 by alvespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	get_len(size_t len, size_t size, unsigned int start)
{
	if (size == 0)
		return (0);
	if (len > size)
	{
		if (start > size)
			return (0);
		else
			return (size - start);
	}
	return (len);
}

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	size;

	i = 0;
	if (!s)
		return (NULL);
	size = 0;
	while (s[size])
		size++;
	len = get_len(len, size, start);
	substr = (char *)malloc((len + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	if (!(start > size))
	{
		while (s[i] && i < len)
		{
			substr[i] = s[start + i];
			i++;
		}
	}
	substr[i] = '\0';
	return (substr);
}

static void	ft_split_str(char **splitstr, char const *str, char c)
{
	int	i;
	int	split_i;
	int	start;

	i = 0;
	start = 0;
	split_i = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			if (str[i - 1] != c && i > 0)
				splitstr[split_i++] = ft_substr(str, start, i - start);
			start = i + 1;
		}
		else if (str[i + 1] == '\0')
			splitstr[split_i++] = ft_substr(str, start, i - start + 1);
		i++;
	}
	splitstr[split_i] = NULL;
}

char	**ft_split(char const *s, int size, int c)
{
	char	**splitstr;

	splitstr = (char **)malloc ((size + 1) * sizeof(char *));
	if (splitstr == NULL)
		return (NULL);
	ft_split_str(splitstr, s, c);
	return (splitstr);
}

/*
#include <stdio.h>
int	main(void)
{
	char		**split;
	char const	*s;
	int			i;

	s = "      split       this for   me  !       ";
	split = ft_split(s, ' ');
	i = 0;
	while (split[i] != NULL)
	{
		printf("%s$\n", split[i]);
		i++;
	}
	i = 0;
	while (split[i] != NULL)
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (0);
}// */
