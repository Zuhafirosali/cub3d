/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faal-zub <faal-zub@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:24:52 by faal-zub          #+#    #+#             */
/*   Updated: 2024/06/21 16:23:01 by faal-zub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	validate_map(t_mlx *mlx, char **strs)
{
	if (malloc_map(mlx, strs))
	{
		ft_putstr_fd("Error\n Failed to initialize map.\n", 2);
		return (1);
	}
	if (analys_map(mlx))
	{
		ft_putstr_fd("Error\n Map is not in correct format.\n", 2);
		return (1);
	}
	return (0);
}

int	occurance_of_element(t_mlx *mlx)
{
	if (mlx->map.composition_of_north && mlx->map.composition_of_south
		&& mlx->map.composition_of_west && mlx->map.composition_of_east
		&& mlx->map.color_of_floor && mlx->map.color_of_ceiling)
		return (1);
	return (0);
}

int	element_analys(t_mlx *mlx, char *str)
{
	if (!ft_strncmp(str, "NO ", 3))
	{
		if (read_north(mlx, str))
			return (1);
	}
	else if (!ft_strncmp(str, "SO ", 3))
	{
		if (read_south(mlx, str))
			return (1);
	}
	else if (!ft_strncmp(str, "WE ", 3))
	{
		if (read_west(mlx, str))
			return (1);
	}
	else if (!ft_strncmp(str, "EA ", 3))
	{
		if (read_east(mlx, str))
			return (1);
	}
	else if (ceiling_and_floor_analys(mlx, str))
		return (1);
	return (0);
}

int	element(char *str)
{
	if (!ft_strncmp(str, "NO ", 3) || !ft_strncmp(str, "SO ", 3)
		|| !ft_strncmp(str, "WE ", 3) || !ft_strncmp(str, "EA ", 3)
		|| !ft_strncmp(str, "F ", 2) || !ft_strncmp(str, "C ", 2))
		return (1);
	return (0);
}

int	start_map(t_mlx *mlx, char **strs, int i)
{
	if (element(&(*strs)[i]))
	{
		if (element_analys(mlx, &(*strs)[i]))
			return (1);
	}
	else if (is_map_valid(*strs) && occurance_of_element(mlx))
	{
		if (validate_map(mlx, strs))
			return (1);
		return (2);
	}
	else
	{
		ft_putstr_fd("Error\n Invalid characters in the map "
			"or fields are missing\n", 2);
		return (1);
	}
	return (0);
}
