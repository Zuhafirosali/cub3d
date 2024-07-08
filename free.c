/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faal-zub <faal-zub@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:42:18 by faal-zub          #+#    #+#             */
/*   Updated: 2024/06/24 11:21:12 by faal-zub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_split(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
}

void	free_map(t_mlx *mlx)
{
	if (mlx->map.shade_of_ceiling)
		free(mlx->map.shade_of_ceiling);
	if (mlx->map.shade_of_floor)
		free(mlx->map.shade_of_floor);
	if (mlx->map.map != NULL)
		free_split(mlx->map.map);
	if (mlx->map.composition_of_west)
		free(mlx->map.w_comp);
	if (mlx->map.composition_of_south)
		free(mlx->map.s_comp);
	if (mlx->map.composition_of_east)
		free(mlx->map.e_comp);
	if (mlx->map.composition_of_north)
		free(mlx->map.n_comp);
}

void	memory_end(t_mlx *mlx)
{
	free_split(mlx->map.map);
	free(mlx->map.shade_of_ceiling);
	free(mlx->map.e_comp);
	free(mlx->map.n_comp);
	free(mlx->map.s_comp);
	free(mlx->map.shade_of_floor);
	free(mlx->map.w_comp);
}
