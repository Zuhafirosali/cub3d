/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_analys.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faal-zub <faal-zub@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:25:28 by faal-zub          #+#    #+#             */
/*   Updated: 2024/06/21 16:16:53 by faal-zub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	read_north(t_mlx *mlx, char *str)
{
	if (!mlx->map.composition_of_north)
	{
		str += 2;
		while (*str == ' ')
			str++;
		mlx->map.n_comp = ft_strdup(str);
		mlx->img[NO].img_ptr = mlx_xpm_file_to_image(mlx,
				mlx->map.n_comp, &mlx->img[NO].width, &mlx->img[NO].height);
		if (!mlx->img[NO].img_ptr)
		{
			ft_putstr_fd("Error\n Texture file not found.\n", 2);
			return (1);
		}
		mlx->img[NO].data = (int *)mlx_get_data_addr(mlx->img[NO].img_ptr,
				&mlx->img[NO].bpp, &mlx->img[NO].size_l, &mlx->img[NO].endian);
		mlx->map.composition_of_north = 1;
	}
	else
	{
		ft_putstr_fd("Error\n Duplicates found.\n", 2);
		return (1);
	}
	return (0);
}

int	read_south(t_mlx *mlx, char *str)
{
	if (!mlx->map.composition_of_south)
	{
		str += 2;
		while (*str == ' ')
			str++;
		mlx->map.s_comp = ft_strdup(str);
		mlx->img[SO].img_ptr = mlx_xpm_file_to_image(mlx,
				mlx->map.s_comp, &mlx->img[SO].width, &mlx->img[SO].height);
		if (!mlx->img[SO].img_ptr)
		{
			ft_putstr_fd("Error\n Texture file not found.\n", 2);
			return (1);
		}
		mlx->img[SO].data = (int *)mlx_get_data_addr(mlx->img[SO].img_ptr,
				&mlx->img[SO].bpp, &mlx->img[SO].size_l, &mlx->img[SO].endian);
		mlx->map.composition_of_south = 1;
	}
	else
	{
		ft_putstr_fd("Error\n Duplicates found.\n", 2);
		return (1);
	}
	return (0);
}

int	read_west(t_mlx *mlx, char *str)
{
	if (!mlx->map.composition_of_west)
	{
		str += 2;
		while (*str == ' ')
			str++;
		mlx->map.w_comp = ft_strdup(str);
		mlx->img[WE].img_ptr = mlx_xpm_file_to_image(mlx,
				mlx->map.w_comp, &mlx->img[WE].width, &mlx->img[WE].height);
		if (!mlx->img[WE].img_ptr)
		{
			ft_putstr_fd("Error\n Texture file not found.\n", 2);
			return (1);
		}
		mlx->img[WE].data = (int *)mlx_get_data_addr(mlx->img[WE].img_ptr,
				&mlx->img[WE].bpp, &mlx->img[WE].size_l, &mlx->img[WE].endian);
		mlx->map.composition_of_west = 1;
	}
	else
	{
		ft_putstr_fd("Error\n Duplicates found.\n", 2);
		return (1);
	}
	return (0);
}

int	read_east(t_mlx *mlx, char *str)
{
	if (!mlx->map.composition_of_east)
	{
		str += 2;
		while (*str == ' ')
			str++;
		mlx->map.e_comp = ft_strdup(str);
		mlx->img[EA].img_ptr = mlx_xpm_file_to_image(mlx,
				mlx->map.e_comp, &mlx->img[EA].width, &mlx->img[EA].height);
		if (!mlx->img[EA].img_ptr)
		{
			ft_putstr_fd("Error\n Texture file not found.\n", 2);
			return (1);
		}
		mlx->img[EA].data = (int *)mlx_get_data_addr(mlx->img[EA].img_ptr,
				&mlx->img[EA].bpp, &mlx->img[EA].size_l, &mlx->img[EA].endian);
		mlx->map.composition_of_east = 1;
	}
	else
	{
		ft_putstr_fd("Error\n Duplicates found.\n", 2);
		return (1);
	}
	return (0);
}

int	ceiling_and_floor_analys(t_mlx *mlx, char *str)
{
	if (!ft_strncmp(str, "F ", 2))
	{
		if (set_floor_color(mlx, str))
			return (1);
	}
	else if (!ft_strncmp(str, "C ", 2))
	{
		if (set_ceiling_color(mlx, str))
			return (1);
	}
	return (0);
}
