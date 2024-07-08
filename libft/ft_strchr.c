/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faal-zub <faal-zub@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:01:42 by faal-zub          #+#    #+#             */
/*   Updated: 2024/06/13 15:27:00 by faal-zub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	while (*str != '\0')
	{
		if ((unsigned char)*str == (char)ch)
			return ((char *)str);
		str++;
	}
	if (*str == (char) ch)
		return ((char *)str);
	return (NULL);
}
