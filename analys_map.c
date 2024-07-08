/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analys_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faal-zub <faal-zub@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:38:08 by faal-zub          #+#    #+#             */
/*   Updated: 2024/06/22 16:42:22 by faal-zub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	analys_map(t_mlx *mlx)
{
	if (mlx->map.max < 3 || mlx->map.size < 3)
		return (1);
	if (spaces_analys(mlx))
		return (1);
	if (bottom_and_top_analys(mlx))
		return (1);
	if (sides_analys(mlx))
		return (1);
	if (validate_starting_position(mlx))
		return (1);
	if (close_analys(mlx))
		return (1);
	return (0);
}

int	spaces_analys(t_mlx *mlx)
{
	int	row;
	int	colum;

	row = 0;
	while (mlx->map.map[row])
	{
		colum = 0;
		while (mlx->map.map[row][colum])
		{
			if (mlx->map.map[row][colum] == ' ')
			{
				if (vertical_analys(mlx, row, colum))
					return (1);
				if (horizontal_analys(mlx, row, colum))
					return (1);
			}
			++colum;
		}
		++row;
	}
	return (0);
}

int	bottom_and_top_analys(t_mlx *mlx)
{
	int	colum;

	colum = 0;
	while (mlx->map.map[0][colum])
	{
		if (mlx->map.map[0][colum] == ' ' || mlx->map.map[0][colum] == '1')
			;
		else
			return (1);
		++colum;
	}
	colum = 0;
	while (mlx->map.map[mlx->map.size - 1][colum])
	{
		if (mlx->map.map[mlx->map.size - 1][colum] == ' '
			|| mlx->map.map[mlx->map.size - 1][colum] == '1')
			;
		else
			return (1);
		++colum;
	}
	return (0);
}

int	sides_analys(t_mlx *mlx)
{
	int	row;

	row = 0;
	while (mlx->map.map[row])
	{
		if (mlx->map.map[row][0] == ' ' || mlx->map.map[row][0] == '1')
			;
		else
			return (1);
		++row;
	}
	row = 0;
	while (mlx->map.map[row])
	{
		if (mlx->map.map[row][mlx->map.max - 1] == ' '
			|| mlx->map.map[row][mlx->map.max - 1] == '1')
			;
		else
			return (1);
		++row;
	}
	return (0);
}

int	validate_starting_position(t_mlx *mlx)
{
	int	row;
	int	c;
	int	found;

	row = 0;
	found = 0;
	while (mlx->map.map[row])
	{
		c = 0;
		while (mlx->map.map[row][c])
		{
			if (mlx->map.map[row][c] == 'E' || mlx->map.map[row][c] == 'N'
				|| mlx->map.map[row][c] == 'W' || mlx->map.map[row][c] == 'S')
			{
				if (not_in_border(mlx, mlx->map.map, row, c))
					return (1);
				found++;
			}
			++c;
		}
		++row;
	}
	if (found != 1)
		return (1);
	return (0);
}
