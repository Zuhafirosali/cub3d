/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faal-zub <faal-zub@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 13:20:30 by faal-zub          #+#    #+#             */
/*   Updated: 2024/06/13 15:25:50 by faal-zub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*tos;
	unsigned char		*tod;
	size_t				c;

	c = 0;
	tod = (unsigned char *)dest;
	tos = (unsigned char *)src;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (c < n)
	{
		tod[c] = tos[c];
		c++;
	}
	return (dest);
}
