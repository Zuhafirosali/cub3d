/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faal-zub <faal-zub@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 12:26:33 by faal-zub          #+#    #+#             */
/*   Updated: 2023/12/27 00:49:53 by faal-zub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*tob;
	size_t			co;

	co = 0;
	tob = (unsigned char *)b;
	while (co < len)
	{
		tob[co] = (unsigned char)c;
		co++;
	}
	return (b);
}
