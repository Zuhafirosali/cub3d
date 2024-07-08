/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faal-zub <faal-zub@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:32:08 by faal-zub          #+#    #+#             */
/*   Updated: 2024/06/24 13:48:48 by faal-zub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_valid_number(const char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	lower_col_check(t_mlx *mlx, char **strs)
{
	int	i;
	int	r;
	int	g;
	int	b;

	i = 0;
	while (strs[i])
		++i;
	if (i != 3)
		return (ft_putstr_fd("Error\n Invalid number of floor\n", 2), 1);
	if (!is_valid_number(strs[0]) || !is_valid_number(strs[1])
		|| !is_valid_number(strs[2]))
		return (ft_putstr_fd("Error\n Invalid character floor\n", 2), 1);
	r = ft_atoi(strs[0]);
	g = ft_atoi(strs[1]);
	b = ft_atoi(strs[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (ft_putstr_fd("Error\n floor out of range (0-255)\n", 2), 1);
	mlx->map.floor_r = r;
	mlx->map.floor_g = g;
	mlx->map.floor_b = b;
	return (0);
}

int	upper_col_check(t_mlx *mlx, char **strs)
{
	int	i;
	int	r;
	int	g;
	int	b;

	i = 0;
	while (strs[i])
		++i;
	if (i != 3)
		return (ft_putstr_fd("Error\n Invalid number of ceiling.\n", 2), 1);
	if (!is_valid_number(strs[0]) || !is_valid_number(strs[1])
		|| !is_valid_number(strs[2]))
		return (ft_putstr_fd("Error\n Invalid character ceiling.\n", 2), 1);
	r = ft_atoi(strs[0]);
	g = ft_atoi(strs[1]);
	b = ft_atoi(strs[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (ft_putstr_fd("Error\n ceiling out of range(0-255)\n", 2), 1);
	mlx->map.ceil_r = r;
	mlx->map.ceil_g = g;
	mlx->map.ceil_b = b;
	return (0);
}

int	color_analys(t_mlx *mlx)
{
	char	**tmp;

	tmp = ft_split(mlx->map.shade_of_floor, ',');
	if (lower_col_check(mlx, tmp))
	{
		free_split(tmp);
		return (1);
	}
	free_split(tmp);
	tmp = ft_split(mlx->map.shade_of_ceiling, ',');
	if (upper_col_check(mlx, tmp))
	{
		free_split(tmp);
		return (1);
	}
	free_split(tmp);
	return (0);
}

int	map_validity_check(t_mlx *mlx)
{
	if (mlx->map.map == NULL)
	{
		ft_putstr_fd("Error\n Failed to initialize map.\n", 2);
		return (1);
	}
	if (color_analys(mlx))
	{
		ft_putstr_fd(" RGB color values are wrong.\n", 2);
		return (1);
	}
	return (0);
}
