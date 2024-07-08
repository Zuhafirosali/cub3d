/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faal-zub <faal-zub@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:45:10 by faal-zub          #+#    #+#             */
/*   Updated: 2024/06/24 17:41:50 by faal-zub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	printstr(char *str, char *fd)
{
	int		i;

	i = 0;
	if (str == NULL)
	{
		str = "(null)";
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	i = 0;
	while (fd[i])
	{
		write(1, &fd[i], 1);
		i++;
	}
	return (i);
}

int	open_and_validate_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		exit(printstr("Error\n could not open file ", filename));
	}
	if (is_cub_file(filename) == 1)
	{
		close(fd);
		exit(printstr("Error\n could not read file without .cub ", filename));
	}
	return (fd);
}

int	map_checking(char *map)
{
	if (!map)
	{
		ft_putstr_fd("Error\n Failed to read map.\n", 2);
		return (1);
	}
	if (new_line_analys(map))
	{
		free(map);
		ft_putstr_fd("Error\n Map has newline.\n", 2);
		return (1);
	}
	return (0);
}

char	*read_map(int fd)
{
	char	*str;
	char	buffer[42];
	int		bytes;
	char	*temp;

	str = malloc(1);
	if (!str)
		return (NULL);
	str[0] = '\0';
	bytes = read(fd, buffer, 41);
	while (bytes > 0)
	{
		buffer[bytes] = '\0';
		temp = ft_strjoin(str, buffer);
		free(str);
		if (!temp)
			return (NULL);
		str = temp;
		bytes = read(fd, buffer, 41);
	}
	if (bytes == -1)
		return (free(str), NULL);
	return (str);
}

char	**ft_read_map(char *filename)
{
	int		fd;
	char	*total;
	char	**x;

	fd = open_and_validate_file(filename);
	total = read_map(fd);
	if (!total)
	{
		printstr("Error\n reading map", filename);
		close(fd);
		return (NULL);
	}
	if (map_checking(total))
	{
		close(fd);
		printstr("Map checking failed\n", filename);
		exit(1);
	}
	x = ft_split(total, '\n');
	free(total);
	close(fd);
	if (x == NULL)
		return (printstr("Error splitting map\n", filename), NULL);
	return (x);
}
