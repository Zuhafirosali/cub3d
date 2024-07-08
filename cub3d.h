/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faal-zub <faal-zub@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:42:18 by faal-zub          #+#    #+#             */
/*   Updated: 2024/06/22 16:42:31 by faal-zub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 900
# define HEIGHT 500

# define NO 1
# define SO 2
# define WE 3
# define EA 4

typedef struct s_player
{
	double		pos_x;
	double		pos_y;
	double		dir_y;
	double		dir_x;
	double		plane_x;
	double		plane_y;
}				t_player;

typedef struct s_map
{
	char		**map;
	char		*w_comp;
	char		*n_comp;
	char		*e_comp;
	char		*s_comp;
	char		*shade_of_floor;
	char		*shade_of_ceiling;
	int			composition_of_west;
	int			composition_of_north;
	int			composition_of_south;
	int			composition_of_east;
	int			ceil_r;
	int			ceil_g;
	int			ceil_b;
	int			floor_r;
	int			floor_g;
	int			floor_b;
	int			max;
	int			size;
	int			color_of_floor;
	int			color_of_ceiling;
}				t_map;

typedef struct s_img
{
	void		*img_ptr;
	int			*data;
	int			width;
	int			height;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct s_ray
{
	double		camera_x;
	double		raydir_x;
	double		raydir_y;
	int			map_x;
	int			map_y;
	double		sidedist_x;
	double		sidedist_y;
	double		deltadist_x;
	double		deltadist_y;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			side;
	double		wallx;
	int			tex_x;
	double		step;
}				t_ray;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	int			buf[HEIGHT][WIDTH];
	int			key_a;
	int			key_d;
	int			key_s;
	int			key_w;
	int			key_right;
	int			key_left;
	int			texture[4][4096];
	t_map		map;
	t_img		img[5];
	t_player	player;
	t_ray		ray;
}				t_mlx;

//set_player
void			south_and_east(t_mlx *mlx, int north);
void			west_and_east(t_mlx *mlx, int west);
void			player_starting_point(t_mlx *mlx);
void			player_initiate(t_mlx *mlx);

//analys_map
int				analys_map(t_mlx *mlx);
int				spaces_analys(t_mlx *mlx);
int				bottom_and_top_analys(t_mlx *mlx);
int				sides_analys(t_mlx *mlx);
int				validate_starting_position(t_mlx *mlx);

//malloc_map
int				map_copy(t_mlx *mlx, char **strs, int max);
int				find_max(char **strs);
int				malloc_map(t_mlx *mlx, char **strs);

//key_press
int				stop_key_function(int keycode, t_mlx *mlx);
int				hook_end(t_mlx *mlx);
int				key_press(int keycode, t_mlx *mlx);
void			right_turn(t_mlx *mlx);
void			left_turn(t_mlx *mlx);

//move_player
void			go_left(t_mlx *mlx);
void			go_right(t_mlx *mlx);
void			go_up(t_mlx *mlx);
void			go_down(t_mlx *mlx);

//utils
int				set_ceiling_color(t_mlx *mlx, char *str);
int				set_floor_color(t_mlx *mlx, char *str);

//element_analys
int				read_north(t_mlx *mlx, char *str);
int				read_south(t_mlx *mlx, char *str);
int				read_west(t_mlx *mlx, char *str);
int				read_east(t_mlx *mlx, char *str);
int				ceiling_and_floor_analys(t_mlx *mlx, char *str);

//help_analys
int				locked(char **map, int row, int colum);
int				close_analys(t_mlx *mlx);
int				horizontal_analys(t_mlx *mlx, int row, int colum);
int				vertical_analys(t_mlx *mlx, int row, int colum);
int				not_in_border(t_mlx *mlx, char **map, int i, int z);

//verline
int				find_colour(t_mlx *mlx, int texy);
void			compositiones(t_mlx *mlx, int x, int assign_start,
					int assign_end);
int				get_hex(int r, int g, int b);
void			verline(t_mlx *mlx, int assign_start, int assign_end, int x);

//action
void			setup_ray(t_mlx *mlx);
void			steps_calculation(t_mlx *mlx);
void			dda_algorithm(t_mlx *mlx);
void			assign_walls(t_mlx *mlx, int x);

//loop_assign
void			update_display(t_mlx *mlx);
void			key_behavior(t_mlx *mlx);
void			action(t_mlx *mlx);
int				loop_assign(t_mlx *mlx);

//main
void			initiate_structure(t_mlx *mlx);
void			keys_initiate(t_mlx *mlx);
int				map_processing(t_mlx *mlx, char *file_name);
int				mlx_initiate(t_mlx *mlx);

//set_map
char			*ft_strjoin_cub3d(char *s1, char *s2);
int				printstr(char *str, char *fd);
int				open_and_validate_file(char *filename);
char			**ft_read_map(char *filename);
int				map_checking(char *map);

//start_map
int				validate_map(t_mlx *mlx, char **strs);
int				occurance_of_element(t_mlx *mlx);
int				element(char *str);
int				analyze_element(t_mlx *mlx, char *str);
int				start_map(t_mlx *mlx, char **strs, int i);

//free
void			free_split(char **strs);
void			free_map(t_mlx *mlx);
void			memory_end(t_mlx *mlx);

//map_validity_check
int				lower_col_check(t_mlx *mlx, char **strs);
int				upper_col_check(t_mlx *mlx, char **strs);
int				color_analys(t_mlx *mlx);
int				map_validity_check(t_mlx *mlx);
int				is_valid_number(const char *str);

//parsing
int				is_cub_file(char *filename);
int				parsing(t_mlx *mlx, char **strs);
int				is_map_valid(char *str);
int				new_line_analys(char *map);
int				new_line(char *str);

#endif
