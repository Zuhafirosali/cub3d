/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faal-zub <faal-zub@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:30:19 by faal-zub          #+#    #+#             */
/*   Updated: 2024/06/22 16:59:32 by faal-zub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
	{
		while (src[i])
			++i;
		return (i);
	}
	while (i < dstsize && src[i] != '\0')
	{
		dst[i] = src[i];
		++i;
	}
	while (i < dstsize)
		dst[i++] = ' ';
	dst[i] = '\0';
	return (i);
}
