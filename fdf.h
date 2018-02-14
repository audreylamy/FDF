/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 11:49:43 by alamy             #+#    #+#             */
/*   Updated: 2018/02/14 12:50:45 by alamy            ###   ########.fr       */
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

# include "minilibx/mlx.h"
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include "libft/libft.h"

/*DEFINE EVENTS KEY FUNCT*/
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
# define ZOOM_Z_UP 24
# define ZOOM_Z_DOWN 27
# define ALL_COLOR 8
# define COLOR_RED 15
# define COLOR_BLUE 5
# define COLOR_GREEN 11

# define PROJECTION_PLUS 258
# define PROJECTION_MOINS 36

/*DEFINE EVENTS MOUSE FUNCT*/
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define CLIC_RIGHT 2
# define CLIC_LEFT 1
# define CLIC_MIDDLE 3

typedef struct s_color
{
	unsigned int r;
	unsigned int g;
	unsigned int b;
}				t_color;

typedef struct	s_val
{
	int			i;
	int			ret;
	char		*tmp;
}				t_val;

typedef struct	s_algob
{
	float ex;
	float ey;
	float dx;
	float dy;
	float Dx;
	float Dy;
	float i;
	float Xincr;
	float Yincr;
}				t_algob;

typedef struct	s_img
{
	void 	*img_ptr;
	char 	*data;
	int 	bpp;
	int 	size_bits;
	int 	endian;
	unsigned int color;
}				t_img;

typedef struct	s_env
{
	void *mlx;
	void *win;
	t_img img;
	int	***map;
	int	***map_buffer;
	int new_move_y;
	int new_move_x;
	int move_rotation_x;
	int move_rotation_y;
	int move_rotation_z;
	int zoom;
	int zoom_z;
	int color_red;
	int color_green;
	int color_blue;
	float projection;
	int clic_proj;
	int scroll;
	int nb_line;
	int nb_col;
}				t_env;

int		main(int argc, char **argv);

/*CHECKS*/
int		ft_checks(char **argv, t_env *tmp);
int		ft_check_name_file(char *str);
int		ft_empty_file(char *str);
int		ft_check_map_rec(char *str1, t_env *tmp);
int		ft_check_data(char **argv);
int		ft_isxdigit(char *str);
int		ft_isnumber(char *str);

/*PARSING*/
int		ft_nb_line(char **argv);
int		ft_getnbr(char *str);
int 	ft_lenght(char **str);
int 	ft_nb_col(char **argv);
void	ft_print_tab(t_env *tmp);
void  	ft_parse_map(char **argv, t_env *tmp);
void  	ft_get_coord(char *line, t_env *tmp);

/*IMAGE*/
void	ft_create_image(t_env *tmp);
void	ft_create_new_image(t_env *tmp, int keycode);
void	fill_pixel(t_env *tmp, int x, int y, int color);

/*BRESENHAM*/
void	ft_transform_map(t_env *tmp, int keycode);
void	ft_draw_line_horiz(t_env *tmp);
void	ft_draw_line_vertical(t_env *tmp);
void	print_horiz_line(t_env *tmp, int i, int j);
void	print_vertical_line(t_env *tmp, int i, int j);
void	ft_bresenham(int x0, int y0, int x1, int y1, t_env *tmp, int color);
void	ft_bre_1(t_algob *b, t_env *tmp, int x0, int y0, int color);
void	ft_bre_2(t_algob *b, t_env *tmp, int x0, int y0, int color);

/*EVENT*/
int		my_key_funct(int keycode, t_env *tmp);
int		my_mouse_funct(int button, int x, int y, t_env *tmp);
void	event_translation(int keycode, t_env *tmp);
void	event_rotation(int keycode, t_env *tmp);
void	event_zoom(int keycode, t_env *tmp);
void	event_color(int keycode, t_env *tmp);
void	event_projection(int keycode, t_env *tmp);
void	event_clic(int button, t_env *tmp);

/*COLOR*/
t_color	ft_colorConverter(t_env *tmp, int hexValue);

/*STRING*/
void	ft_create_string(t_env *tmp);

/*MATRIX*/
typedef struct s_vecteur4
{
	float x1;
	float y1;
	float z1;
	float w1;
}				t_vecteur4;

typedef struct s_matrix t_matrix;
typedef union 
{
	float m[4][4];
    struct	s_matrix
    {
		float a1;
		float a2; 
		float a3;
		float a4;
		float b1;
		float b2; 
		float b3; 
		float b4;
		float c1;
		float c2;
		float c3;
		float c4;
		float d1;
		float d2;
		float d3;
		float d4;
	}	   	t_matrix;
} t_matrix4;

t_matrix4 	matrix_translation(t_vecteur4 vecteur);
t_matrix4	matrix_homothetie(t_vecteur4 homo);
t_matrix4	matrix_rotationX(float alpha);
t_matrix4	matrix_rotationY(float alpha);
t_matrix4	matrix_rotationZ(float alpha);
t_matrix4	matrix_projection(float angle, float ratio, float near, float far); 
t_vecteur4	create_vecteur4(int x, int y, int z, int w);
t_vecteur4	ft_create_transformation(int x, int y, int z, int w, t_env *tmp);
t_vecteur4	ft_reset_transformation(int x, int y, int z, int w, t_env *tmp);
t_vecteur4	ft_cal_translation(t_vecteur4 vecteur2, t_matrix4 matrix_translation);
t_vecteur4	ft_cal_rotationX(t_vecteur4 vecteur, t_matrix4 matrix_rotationX);
t_vecteur4	ft_cal_rotationY(t_vecteur4 vecteur, t_matrix4 matrix_rotationY);
t_vecteur4	ft_cal_rotationZ(t_vecteur4 vecteur, t_matrix4 matrix_rotationZ);
t_vecteur4	ft_cal_homothetie(t_vecteur4 vecteur, t_matrix4 matrix_homothetie);
t_vecteur4	ft_cal_projection(t_vecteur4 vecteur, t_matrix4 matrix_homothetie);
//void ft_print_matrix(t_matrix4 matrix);

#endif
