/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faal-zub <faal-zub@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 20:03:23 by faal-zub          #+#    #+#             */
/*   Updated: 2023/12/25 19:51:51 by faal-zub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		i;

	i = ft_strlen(s);
	dest = malloc(sizeof(char) * i + 1);
	if (!dest)
	{
		return (0);
	}
	ft_memcpy(dest, s, i);
	dest[i] = '\0';
	return (dest);
}
