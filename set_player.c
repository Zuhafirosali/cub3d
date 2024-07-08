/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faal-zub <faal-zub@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:44:59 by faal-zub          #+#    #+#             */
/*   Updated: 2024/06/21 16:23:12 by faal-zub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	south_and_east(t_mlx *mlx, int north)
{
	if (north)
	{
		mlx->player.dir_x = -1;
		mlx->player.dir_y = 0;
		mlx->player.plane_x = 0;
		mlx->player.plane_y = 0.66;
	}
	else
	{
		mlx->player.dir_x = 1;
		mlx->player.dir_y = 0;
		mlx->player.plane_x = 0;
		mlx->player.plane_y = -0.66;
	}
}

void	west_and_east(t_mlx *mlx, int west)
{
	if (west)
	{
		mlx->player.dir_x = 0;
		mlx->player.dir_y = -1;
		mlx->player.plane_x = -0.66;
		mlx->player.plane_y = 0;
	}
	else
	{
		mlx->player.dir_x = 0;
		mlx->player.dir_y = 1;
		mlx->player.plane_x = 0.66;
		mlx->player.plane_y = 0;
	}
}

void	player_starting_point(t_mlx *mlx)
{
	if (mlx->map.map[(int)mlx->player.pos_x][(int)mlx->player.pos_y]
		== 'W')
		west_and_east(mlx, 1);
	else if (mlx->map.map[(int)mlx->player.pos_x][(int)mlx->player.pos_y]
		== 'E')
		west_and_east(mlx, 0);
	else if (mlx->map.map[(int)mlx->player.pos_x][(int)mlx->player.pos_y]
		== 'N')
		south_and_east(mlx, 1);
	else if (mlx->map.map[(int)mlx->player.pos_x][(int)mlx->player.pos_y]
		== 'S')
		south_and_east(mlx, 0);
}

void	player_initiate(t_mlx *mlx)
{
	int	x;
	int	y;

	player_starting_point(mlx);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			mlx->buf[y][x] = 0;
			++x;
		}
		++y;
	}
}
