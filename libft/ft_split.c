/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faal-zub <faal-zub@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 16:14:11 by faal-zub          #+#    #+#             */
/*   Updated: 2024/06/13 15:36:13 by faal-zub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countsep(char const *str, char sep)
{
	int		c;
	int		i;

	c = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != sep)
		{
			c++;
			while (str[i] != sep && str[i])
				i++;
		}
		else
			i++;
	}
	return (c);
}

static int	ft_len(char const *s, char const c, int i)
{
	int		size;

	size = 0;
	while (s[i] != c && s[i])
	{
		i++;
		size++;
	}
	return (size);
}

static void	ft_free(char **s, int i)
{
	while (i >= 0)
	{
		free(s[i]);
		i--;
	}
	free (s);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**split;
	int		i;
	int		a;

	if (!s)
		return (NULL);
	count = ft_countsep(s, c);
	split = (char **)malloc (sizeof(char *) * (count + 1));
	if (split == NULL)
		return (NULL);
	i = -1;
	a = 0;
	while (++i < count)
	{
		while (s[a] == c && s[a])
			a++;
		split[i] = ft_substr(s, a, ft_len(s, c, a));
		if (split[i] == NULL)
			ft_free(split, i);
		a += ft_len(s, c, a);
	}
	split[i] = NULL;
	return (split);
}
