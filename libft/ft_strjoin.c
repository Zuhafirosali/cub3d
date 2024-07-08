/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faal-zub <faal-zub@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 21:28:00 by faal-zub          #+#    #+#             */
/*   Updated: 2024/06/24 12:16:25 by faal-zub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sub;
	size_t	f;
	size_t	w;

	f = 0;
	w = 0;
	if (s1 != NULL && s2 != NULL)
	{
		sub = malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
		if (sub == NULL)
			return (NULL);
		while (s1[w])
		{
			sub[w] = s1[w];
			w++;
		}
		while (s2[f])
		{
			sub[w + f] = s2[f];
			f++;
		}
		sub[w + f] = '\0';
		return (sub);
	}
	return (NULL);
}
