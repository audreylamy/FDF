/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 11:49:43 by alamy             #+#    #+#             */
/*   Updated: 2018/02/15 17:51:55 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define BUFF_SIZE 32
# define WINDOW_L 1500
# define WINDOW_H 1000
# define TILE_WIDTH 25
# define TILE_HEIGHT 25
# define PI 3.14159265359

# include <mlx.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include "libft/libft.h"

# define EXIT 53
# define RESET 49
# define RIGHT 124
# define LEFT 123
# define UP 126
# define DOWN 125
# define ROTATION_X_UP 91
# define ROTATION_X_DOWN 84
# define ROTATION_Z_RIGHT 88
# define ROTATION_Z_LEFT 86
# define ROTATION_Y_A 0
# define ROTATION_Y_W 13
# define ZOOM_UP 69
# define ZOOM_DOWN 78
# define ZOOM_Z_UP 92
# define ZOOM_Z_DOWN 85
# define ALL_COLOR 8
# define COLOR_RED 15
# define COLOR_BLUE 5
# define COLOR_GREEN 11

# define PROJECTION_UP 258
# define PROJECTION_DOWN 36

# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define CLIC_RIGHT 2
# define CLIC_LEFT 1
# define CLIC_MIDDLE 3

typedef struct	s_data
{
	int		x;
	int		y;
	int		x0;
	int		y0;
	int		z0;
	int		w0;
	int		color;
}				t_data;

typedef struct	s_color
{
	int		r;
	int		g;
	int		b;
}				t_color;

typedef struct	s_algob
{
	float	nb_pix_x;
	float	nb_pix_y;
	float	dx;
	float	dy;
	float	px;
	float	py;
	float	i;
	float	xincr;
	float	yincr;
}				t_algob;

typedef struct	s_img
{
	void	*img_ptr;
	char	*data;
	int		bpp;
	int		size_bits;
	int		endian;
	int		color;
}				t_img;

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	t_img	img;
	int		***map;
	int		***map_buffer;
	int		move_y;
	int		move_x;
	int		move_rotation_x;
	int		move_rotation_y;
	int		move_rotation_z;
	int		zoom;
	int		zoom_z;
	int		color_red;
	int		color_green;
	int		color_blue;
	float	projection;
	int		clic_proj;
	int		nb_line;
	int		nb_col;
}				t_env;

int				main(int argc, char **argv);

/*
**CHECKS
*/
int				ft_checks(char **argv, t_env *tmp);
int				ft_check_name_file(char *str);
int				ft_empty_file(char *str);
int				ft_check_map_rec(char *str1, t_env *tmp);
int				ft_check_data(char *str);
int				ft_isxdigit(char *str);
int				ft_open_failed(int fd);
int				ft_close_failed(int fd);

/*
**PARSING
*/
int				ft_nb_line(char **argv);
int				ft_getnbr(char *str);
int				ft_lenght(char **str);
int				ft_nb_col(char **argv);
void			ft_print_tab(t_env *tmp);
void			ft_parse_map(char **argv, t_env *tmp);
void			ft_get_coord(char *line, t_env *tmp);

/*
**IMAGES
*/
void			ft_create_image(t_env *tmp);

/*
**MAP TRANSFORMATIONS
*/
void			ft_transform_map(t_env *tmp, int keycode);
void			ft_if_error_map(t_env *tmp);
void			ft_reset_event(t_env *tmp);

/*
**BRESENHAM
*/
void			ft_draw_line_horiz(t_env *tmp);
void			ft_draw_line_vertical(t_env *tmp);
void			print_horiz_line(t_env *tmp, int i, int j);
void			print_vertical_line(t_env *tmp, int i, int j);
void			ft_bresenham(t_data *data, t_env *tmp);
void			ft_bre_1(t_algob *b, t_env *tmp, t_data *data, int color);
void			ft_bre_2(t_algob *b, t_env *tmp, t_data *data, int color);
void			fill_pixel(t_env *tmp, int x, int y, int color);

/*
**EVENTS
*/
void 			ft_free_map(t_env *tmp);
void			ft_redraw_image(t_env *tmp, int keycode);
int				my_key_funct(int keycode, t_env *tmp);
int				my_mouse_funct(int button, int x, int y, t_env *tmp);
void			event_translation(int keycode, t_env *tmp);
void			event_rotation(int keycode, t_env *tmp);
void			event_zoom_projection(int keycode, t_env *tmp);
void			event_color(int keycode, t_env *tmp);
void			event_clic(int button, t_env *tmp);

/*
**COLOR
*/
t_color			ft_color_converter(t_env *tmp, int hexvalue);

/*
**CREATE STRING
*/
void			ft_create_string(t_env *t);

typedef struct	s_vector4
{
	float	x1;
	float	y1;
	float	z1;
	float	w1;
}				t_vector4;

typedef struct	s_matrix
{
	float	m[4][4];
}				t_matrix4;

/*
**TRANSFORMATIONS
*/
t_vector4		ft_two_transformations(t_data *data, t_env *tmp, int keycode);
t_vector4		ft_create_transformation(t_data *data, t_env *tmp);
t_vector4		ft_create_rot_zoom(t_vector4 vec_h, t_vector4 result, t_env *t);
t_vector4		ft_reset_transformation(t_data *data, t_env *tmp);
t_vector4		ft_reset_rot_zoom(t_vector4 vec_h, t_vector4 result, t_env *t);

/*
**MATRIX
*/
t_matrix4		matrix_identity(void);
t_matrix4		matrix_translation(t_vector4 vector);
t_matrix4		matrix_homothetie(t_vector4 homo);
t_matrix4		matrix_rotation_x(float alpha);
t_matrix4		matrix_rotation_y(float alpha);
t_matrix4		matrix_rotation_z(float alpha);
t_matrix4		matrix_proj(float angle, float ratio, float near, float far);
t_vector4		create_vector4(int x, int y, int z, int w);
t_vector4		ft_cal_translation(t_vector4 vector2, t_matrix4 m_trans);
t_vector4		ft_cal_rotation_x(t_vector4 vector, t_matrix4 m_rotation_x);
t_vector4		ft_cal_rotation_y(t_vector4 vector, t_matrix4 m_rotation_y);
t_vector4		ft_cal_rotation_z(t_vector4 vector, t_matrix4 m_rotation_z);
t_vector4		ft_cal_homothetie(t_vector4 vector, t_matrix4 m_homothetie);
t_vector4		ft_cal_projection(t_vector4 vector, t_matrix4 m_homothetie);

#endif
