/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faal-zub <faal-zub@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:01:59 by faal-zub          #+#    #+#             */
/*   Updated: 2024/06/12 16:02:01 by faal-zub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	go_left(t_mlx *mlx)
{
	double	pos_y;
	double	pos_x;
	double	dir_y;
	double	dir_x;

	dir_x = mlx->player.dir_x;
	dir_y = mlx->player.dir_y;
	pos_y = mlx->player.pos_y;
	pos_x = mlx->player.pos_x;
	if (mlx->map.map[(int)(pos_x - dir_y * 0.05)][(int)pos_y] != '1')
		mlx->player.pos_x -= dir_y * 0.05;
	pos_x = mlx->player.pos_x;
	if (mlx->map.map[(int)pos_x][(int)(pos_y + dir_x * 0.05)] != '1')
		mlx->player.pos_y += dir_x * 0.05;
}

void	go_right(t_mlx *mlx)
{
	double	pos_y;
	double	pos_x;
	double	dir_y;
	double	dir_x;

	dir_x = mlx->player.dir_x;
	dir_y = mlx->player.dir_y;
	pos_y = mlx->player.pos_y;
	pos_x = mlx->player.pos_x;
	if (mlx->map.map[(int)(pos_x + dir_y * 0.05)][(int)pos_y] != '1')
		mlx->player.pos_x += dir_y * 0.05;
	pos_x = mlx->player.pos_x;
	if (mlx->map.map[(int)pos_x][(int)(pos_y - dir_x * 0.05)] != '1')
		mlx->player.pos_y -= dir_x * 0.05;
}

void	go_up(t_mlx *mlx)
{
	double	pos_y;
	double	pos_x;
	double	dir_y;
	double	dir_x;

	dir_x = mlx->player.dir_x;
	dir_y = mlx->player.dir_y;
	pos_y = mlx->player.pos_y;
	pos_x = mlx->player.pos_x;
	if (mlx->map.map[(int)(pos_x + dir_x * 0.05)][(int)pos_y] != '1')
		mlx->player.pos_x += dir_x * 0.05;
	pos_x = mlx->player.pos_x;
	if (mlx->map.map[(int)pos_x][(int)(pos_y + dir_y * 0.05)] != '1')
		mlx->player.pos_y += dir_y * 0.05;
}

void	go_down(t_mlx *mlx)
{
	double	pos_y;
	double	pos_x;
	double	dir_y;
	double	dir_x;

	dir_x = mlx->player.dir_x;
	dir_y = mlx->player.dir_y;
	pos_y = mlx->player.pos_y;
	pos_x = mlx->player.pos_x;
	if (mlx->map.map[(int)(pos_x - dir_x * 0.05)][(int)pos_y] != '1')
		mlx->player.pos_x -= dir_x * 0.05;
	pos_x = mlx->player.pos_x;
	if (mlx->map.map[(int)pos_x][(int)(pos_y - dir_y * 0.05)] != '1')
		mlx->player.pos_y -= dir_y * 0.05;
}
