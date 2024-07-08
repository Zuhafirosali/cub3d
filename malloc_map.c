/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faal-zub <faal-zub@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:01:22 by faal-zub          #+#    #+#             */
/*   Updated: 2024/06/21 16:21:30 by faal-zub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	map_copy(t_mlx *mlx, char **strs, int max)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		if (!is_map_valid(strs[i]))
			return (1);
		ft_strlcpy(mlx->map.map[i], strs[i], max);
		++i;
	}
	return (0);
}

int	find_max(char **strs)
{
	int		i;
	int		max;
	int		z;

	i = 0;
	while (strs[i])
	{
		z = 0;
		while (strs[i][z])
			++z;
		if (z > max)
			max = z;
		++i;
	}
	return (max);
}

int	malloc_map(t_mlx *mlx, char **strs)
{
	int	i;
	int	max;

	i = 0;
	while (strs[i])
		++i;
	mlx->map.size = i;
	mlx->map.map = malloc(sizeof(char *) * (i + 1));
	if (!mlx->map.map)
		return (1);
	max = find_max(strs);
	mlx->map.max = max;
	i = 0;
	while (strs[i])
	{
		mlx->map.map[i] = malloc(sizeof(char) * (max + 1));
		if (!mlx->map.map[i])
			return (1);
		++i;
	}
	mlx->map.map[i] = 0;
	if (map_copy(mlx, strs, max))
		return (1);
	return (0);
}
