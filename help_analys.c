/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_analys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faal-zub <faal-zub@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:01:15 by faal-zub          #+#    #+#             */
/*   Updated: 2024/06/22 16:47:24 by faal-zub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	locked(char **map, int row, int colum)
{
	if (colum < 1 || row < 1 || !map[row + 1] || !map[row][colum + 1])
	{
		return (1);
	}
	if (map[row + 1][colum] != ' ' && map[row - 1][colum] != ' '
		&& map[row][colum - 1] != ' ' && map[row][colum + 1] != ' ')
		return (0);
	return (1);
}

int	close_analys(t_mlx *mlx)
{
	int	row;
	int	colum;

	row = 0;
	while (mlx->map.map[row])
	{
		colum = 0;
		while (mlx->map.map[row][colum])
		{
			if (mlx->map.map[row][colum] == '0')
			{
				if (locked(mlx->map.map, row, colum))
					return (1);
			}
			++colum;
		}
		++row;
	}
	return (0);
}

int	horizontal_analys(t_mlx *mlx, int row, int colum)
{
	int	start_c;

	start_c = colum;
	while (mlx->map.map[row][colum])
	{
		if (mlx->map.map[row][colum] == '1')
			break ;
		if (mlx->map.map[row][colum] == '0')
			return (1);
		colum++;
	}
	colum = start_c;
	while (colum >= 0)
	{
		if (mlx->map.map[row][colum] == '1')
			break ;
		if (mlx->map.map[row][colum] == '0')
			return (1);
		--colum;
	}
	return (0);
}

int	vertical_analys(t_mlx *mlx, int row, int colum)
{
	int	start_r;

	start_r = row;
	while (mlx->map.map[row])
	{
		if (mlx->map.map[row][colum] == '1')
			break ;
		if (mlx->map.map[row][colum] == '0')
			return (1);
		row++;
	}
	row = start_r;
	while (row >= 0)
	{
		if (mlx->map.map[row][colum] == '1')
			break ;
		if (mlx->map.map[row][colum] == '0')
			return (1);
		--row;
	}
	return (0);
}

int	not_in_border(t_mlx *mlx, char **map, int r, int c)
{
	if (c < 1 || r < 1 || !map[r + 1] || !map[r][c + 1])
		return (1);
	if (map[r + 1][c] != ' ' && map[r
		- 1][c] != ' ' && map[r][c - 1] != ' ' && map[r][c + 1] != ' ')
	{
		mlx->player.pos_x = (double)r + 0.5;
		mlx->player.pos_y = (double)c + 0.5;
		return (0);
	}
	return (1);
}
