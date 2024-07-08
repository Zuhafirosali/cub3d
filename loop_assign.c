/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_assign.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faal-zub <faal-zub@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:01:30 by faal-zub          #+#    #+#             */
/*   Updated: 2024/06/21 16:19:33 by faal-zub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_behavior(t_mlx *mlx)
{
	if (mlx->key_a)
		go_left(mlx);
	if (mlx->key_d)
		go_right(mlx);
	if (mlx->key_w)
		go_up(mlx);
	if (mlx->key_s)
		go_down(mlx);
	if (mlx->key_left)
		left_turn(mlx);
	if (mlx->key_right)
		right_turn(mlx);
}

void	update_display(t_mlx *mlx)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			mlx->img[0].data[y * WIDTH + x] = mlx->buf[y][x];
			++x;
		}
		++y;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img[0].img_ptr, 0, 0);
}

void	action(t_mlx *mlx)
{
	int	x;

	x = 0;
	while (x < WIDTH)
	{
		mlx->ray.camera_x = 2 * x / (double)(WIDTH) - 1;
		setup_ray(mlx);
		steps_calculation(mlx);
		dda_algorithm(mlx);
		assign_walls(mlx, x);
		++x;
	}
}

int	loop_assign(t_mlx *mlx)
{
	action(mlx);
	update_display(mlx);
	key_behavior(mlx);
	return (0);
}
