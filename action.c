/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faal-zub <faal-zub@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:00:48 by faal-zub          #+#    #+#             */
/*   Updated: 2024/06/24 12:46:14 by faal-zub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	setup_ray(t_mlx *mlx)
{
	mlx->ray.raydir_x = mlx->player.dir_x + mlx->player.plane_x
		* mlx->ray.camera_x;
	mlx->ray.raydir_y = mlx->player.dir_y + mlx->player.plane_y
		* mlx->ray.camera_x;
	mlx->ray.map_x = (int)mlx->player.pos_x;
	mlx->ray.map_y = (int)mlx->player.pos_y;
	mlx->ray.deltadist_x = fabs(1 / mlx->ray.raydir_x);
	mlx->ray.deltadist_y = fabs(1 / mlx->ray.raydir_y);
}

void	steps_calculation(t_mlx *mlx)
{
	if (mlx->ray.raydir_x < 0)
	{
		mlx->ray.step_x = -1;
		mlx->ray.sidedist_x = (mlx->player.pos_x - mlx->ray.map_x)
			* mlx->ray.deltadist_x;
	}
	else
	{
		mlx->ray.step_x = 1;
		mlx->ray.sidedist_x = (mlx->ray.map_x + 1.0 - mlx->player.pos_x)
			* mlx->ray.deltadist_x;
	}
	if (mlx->ray.raydir_y < 0)
	{
		mlx->ray.step_y = -1;
		mlx->ray.sidedist_y = (mlx->player.pos_y - mlx->ray.map_y)
			* mlx->ray.deltadist_y;
	}
	else
	{
		mlx->ray.step_y = 1;
		mlx->ray.sidedist_y = (mlx->ray.map_y + 1.0 - mlx->player.pos_y)
			* mlx->ray.deltadist_y;
	}
}

//Digital Differential Analyzer (DDA) algorithm

void	dda_algorithm(t_mlx *mlx)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (mlx->ray.sidedist_x < mlx->ray.sidedist_y)
		{
			mlx->ray.sidedist_x += mlx->ray.deltadist_x;
			mlx->ray.map_x += mlx->ray.step_x;
			mlx->ray.side = 0;
		}
		else
		{
			mlx->ray.sidedist_y += mlx->ray.deltadist_y;
			mlx->ray.map_y += mlx->ray.step_y;
			mlx->ray.side = 1;
		}
		if (mlx->map.map[mlx->ray.map_x][mlx->ray.map_y] == '1')
			hit = 1;
	}
}

void	assign_walls(t_mlx *mlx, int x)
{
	int	line_height;
	int	assign_start;
	int	assign_end;

	if (mlx->ray.side == 0)
		mlx->ray.perp_wall_dist = mlx->ray.sidedist_x - mlx->ray.deltadist_x;
	else
		mlx->ray.perp_wall_dist = mlx->ray.sidedist_y - mlx->ray.deltadist_y;
	line_height = (int)(HEIGHT / mlx->ray.perp_wall_dist);
	assign_start = -line_height / 2 + HEIGHT / 2;
	if (assign_start < 0)
		assign_start = 0;
	assign_end = line_height / 2 + HEIGHT / 2;
	if (assign_end >= HEIGHT)
		assign_end = HEIGHT - 1;
	verline(mlx, assign_start, assign_end, x);
}
