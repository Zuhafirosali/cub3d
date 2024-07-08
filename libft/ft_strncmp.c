/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faal-zub <faal-zub@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:36:25 by faal-zub          #+#    #+#             */
/*   Updated: 2024/06/13 15:36:27 by faal-zub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	f;

	if (!s1 || !s2)
	{
		return (0);
	}
	f = 0;
	while (f < n && (s1[f] || s2[f]))
	{
		if (s1[f] != s2[f])
			return (((unsigned char *)s1)[f] - ((unsigned char *)s2)[f]);
		f++;
	}
	return (0);
}
