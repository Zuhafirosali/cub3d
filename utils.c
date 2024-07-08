/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faal-zub <faal-zub@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:01:52 by faal-zub          #+#    #+#             */
/*   Updated: 2024/06/21 16:22:49 by faal-zub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	set_ceiling_color(t_mlx *mlx, char *str)
{
	if (!mlx->map.color_of_ceiling)
	{
		str += 2;
		while (*str == ' ')
			str++;
		mlx->map.shade_of_ceiling = ft_strdup(str);
		mlx->map.color_of_ceiling = 1;
	}
	else
	{
		ft_putstr_fd("Error\n Duplicates found.\n", 2);
		return (1);
	}
	return (0);
}

int	set_floor_color(t_mlx *mlx, char *str)
{
	if (!mlx->map.color_of_floor)
	{
		str += 2;
		while (*str == ' ')
			str++;
		mlx->map.shade_of_floor = ft_strdup(str);
		mlx->map.color_of_floor = 1;
	}
	else
	{
		ft_putstr_fd("Error\n Duplicates found.\n", 2);
		return (1);
	}
	return (0);
}
