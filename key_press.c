/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faal-zub <faal-zub@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:01:37 by faal-zub          #+#    #+#             */
/*   Updated: 2024/06/21 16:18:22 by faal-zub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	stop_key_function(int keycode, t_mlx *mlx)
{
	if (keycode == 0)
		mlx->key_a = 0;
	else if (keycode == 1)
		mlx->key_s = 0;
	else if (keycode == 13)
		mlx->key_w = 0;
	else if (keycode == 2)
		mlx->key_d = 0;
	else if (keycode == 53)
		hook_end(mlx);
	else if (keycode == 123)
		mlx->key_left = 0;
	else if (keycode == 124)
		mlx->key_right = 0;
	return (0);
}

int	hook_end(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img[0].img_ptr);
	mlx_destroy_image(mlx->mlx, mlx->img[1].img_ptr);
	mlx_destroy_image(mlx->mlx, mlx->img[2].img_ptr);
	mlx_destroy_image(mlx->mlx, mlx->img[3].img_ptr);
	mlx_destroy_image(mlx->mlx, mlx->img[4].img_ptr);
	mlx_destroy_window(mlx->mlx, mlx->win);
	memory_end(mlx);
	write(1, "close game window success\n", 26);
	exit(0);
}

int	key_press(int keycode, t_mlx *mlx)
{
	if (keycode == 0)
		mlx->key_a = 1;
	else if (keycode == 1)
		mlx->key_s = 1;
	else if (keycode == 13)
		mlx->key_w = 1;
	else if (keycode == 2)
		mlx->key_d = 1;
	else if (keycode == 53)
		hook_end(mlx);
	else if (keycode == 123)
		mlx->key_left = 1;
	else if (keycode == 124)
		mlx->key_right = 1;
	return (0);
}

void	left_turn(t_mlx *mlx)
{
	double	olddir_x;
	double	oldplane_x;

	olddir_x = mlx->player.dir_x;
	mlx->player.dir_x = mlx->player.dir_x
		* cos(0.05) - mlx->player.dir_y * sin(0.05);
	mlx->player.dir_y = olddir_x
		* sin(0.05) + mlx->player.dir_y * cos(0.05);
	oldplane_x = mlx->player.plane_x;
	mlx->player.plane_x = mlx->player.plane_x
		* cos(0.05) - mlx->player.plane_y * sin(0.05);
	mlx->player.plane_y = oldplane_x
		* sin(0.05) + mlx->player.plane_y * cos(0.05);
}

void	right_turn(t_mlx *mlx)
{
	double	olddir_x;
	double	oldplane_x;

	olddir_x = mlx->player.dir_x;
	mlx->player.dir_x = mlx->player.dir_x
		* cos(-0.05) - mlx->player.dir_y * sin(-0.05);
	mlx->player.dir_y = olddir_x * sin(-0.05) + mlx->player.dir_y * cos(-0.05);
	oldplane_x = mlx->player.plane_x;
	mlx->player.plane_x = mlx->player.plane_x
		* cos(-0.05) - mlx->player.plane_y * sin(-0.05);
	mlx->player.plane_y = oldplane_x
		* sin(-0.05) + mlx->player.plane_y * cos(-0.05);
}
