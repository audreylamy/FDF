/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 13:43:03 by alamy             #+#    #+#             */
/*   Updated: 2018/02/12 16:11:14 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// t_color ft_colorConverter(t_env *tmp, int hexValue)
// {
//     t_color rgbcolor;
  
//   if (tmp->color_red > 255 || tmp->color_green > 255 || tmp->color_blue > 255)
//   {
//       tmp->color_red -= 255;
//       tmp->color_green -= 255;
//       tmp->color_blue -= 255;
//   }
//   rgbcolor.r = ((hexValue >> 16) & 0xFF) + tmp->color_red;
//   rgbcolor.g = ((hexValue >> 8) & 0xFF) + tmp->color_green;
//   rgbcolor.b = ((hexValue) & 0xFF) + tmp->color_blue;

//   return (rgbcolor); 
// }

// void fill_pixel(t_env *tmp, int x, int y, int color)
// {
//     int     new_color;
//     t_color rgbcolor;
    
//     new_color = mlx_get_color_value(tmp->mlx, color);
//     rgbcolor = ft_colorConverter(tmp, new_color);
//     if (x >= 0 && y >= 0 && x < WINDOW_L && y < WINDOW_H)
//  	tmp->img.data[y * tmp->img.size_bits + x * tmp->img.bpp / 8] = rgbcolor.r;
//  	tmp->img.data[y * tmp->img.size_bits + x * tmp->img.bpp / 8 + 1] = rgbcolor.g; 
//  	tmp->img.data[y * tmp->img.size_bits + x * tmp->img.bpp / 8 + 2] = rgbcolor.b;
// }

void fill_pixel(t_env *tmp, int x, int y, int color)
 {	
	if (x >= 0 && y >= 0 && x < WINDOW_L && y < WINDOW_H)
 		((int*)tmp->img.data)[(y * WINDOW_L) + x] = color;
 }

 void ft_create_image(t_env *tmp)
 {
	int keycode;
	keycode = 0;

 	tmp->img.img_ptr = mlx_new_image(tmp->mlx, WINDOW_L, WINDOW_H);
 	tmp->img.data = (int*)mlx_get_data_addr(tmp->img.img_ptr, &tmp->img.bpp, &tmp->img.size_bits, &tmp->img.endian);
	ft_transform_map(tmp, keycode);
	//tmp->img.color = mlx_get_color_value(tmp->mlx, 0xFF00FF);
 	mlx_put_image_to_window(tmp->mlx, tmp->win, tmp->img.img_ptr, 0, 0);
 }

t_vecteur4 ft_create_transformation(int x, int y, int z, int w, int i, t_env *tmp)
{
	t_vecteur4 	vecteur_trans;
	
	matrix4_t 	m_translation;
	matrix4_t 	m_rotationX;
	matrix4_t 	m_rotationY;
	matrix4_t 	m_rotationZ;
	matrix4_t 	m_homo;
	t_vecteur4  vecteur_homo;
	// matrix4_t	m_projection;
	t_vecteur4 	resultat;

	 if (tmp->zoom< 0)
        tmp->zoom += 1;
    if (tmp->zoom < 0)
        tmp->zoom += 1;  
	 if (tmp->move_rotation_x >= 360.0)
        tmp->move_rotation_x -= 360.0;
    if (tmp->move_rotation_y >= 360.0)
        tmp->move_rotation_y -= 360.0;
    if (tmp->move_rotation_z >= 360.0)
        tmp->move_rotation_z -= 360.0;
	vecteur_trans = create_vecteur4((WINDOW_L / 2) - ((tmp->nb_col * TILE_WIDTH) / 2), 
	(WINDOW_H / 2) - ((tmp->nb_line * TILE_HEIGHT) / 2), 0.0, 1.0);
	m_translation = matrix_translation(vecteur_trans);
	vecteur_homo = create_vecteur4(1.0 + tmp->zoom, 1.0 + tmp->zoom, 1.0 + tmp->zoom_z , 1.0);
	m_homo = matrix_homothetie(vecteur_homo);
	m_rotationX = matrix_rotationX((45.0 + tmp->move_rotation_x) * PI / 180);
	m_rotationY = matrix_rotationY((45.0 + tmp->move_rotation_y) * PI / 180);
	m_rotationZ = matrix_rotationZ((0.0 + tmp->move_rotation_z) * PI / 180);
	// m_projection = matrix_projection(100.0 * PI / 180, WINDOW_L/WINDOW_H ,1.0, 100.0);

	resultat = create_vecteur4(x, y, z, w);

	resultat = ft_cal_homothetie(resultat, m_homo);
	resultat = ft_cal_rotationX(resultat, m_rotationX);
	resultat = ft_cal_rotationY(resultat, m_rotationY);
	resultat = ft_cal_rotationZ(resultat, m_rotationZ);
	resultat = ft_cal_translation(resultat, m_translation);
	// resultat = ft_cal_projection(resultat, m_projection);
	return(resultat);
}

t_vecteur4 ft_reset_transformation(int x, int y, int z, int w, int i, t_env *tmp)
{
	t_vecteur4 	vecteur_trans;
	matrix4_t 	m_translation;
	matrix4_t 	m_rotationX;
	matrix4_t 	m_rotationY;
	matrix4_t 	m_rotationZ;
	matrix4_t 	m_homo;
	t_vecteur4  vecteur_homo;
	// matrix4_t	m_projection;
	t_vecteur4 	resultat;

	tmp->move_rotation_x = 0;
	tmp->move_rotation_y = 0;
	tmp->move_rotation_z = 0;
	tmp->zoom = 0;
	tmp->zoom_z = 0;
	vecteur_trans = create_vecteur4((WINDOW_L / 2) - ((tmp->nb_col * TILE_WIDTH) / 2), 
	(WINDOW_H / 2) - ((tmp->nb_line * TILE_HEIGHT) / 2), 0, 1);
	vecteur_homo = create_vecteur4(1.0, 1.0, 1.0, 1.0);
	m_homo = matrix_homothetie(vecteur_homo);
	m_translation = matrix_translation(vecteur_trans);
	m_rotationX = matrix_rotationX(55.0 * PI / 180);
	m_rotationY = matrix_rotationY(0.0 * PI / 180);
	m_rotationZ = matrix_rotationZ(4.0 * PI / 180);
	//m_projection = matrix_projection(100.0 * PI / 180, WINDOW_L/WINDOW_H ,1.0, 100.0);

	resultat = create_vecteur4(x, y, z, w);

	resultat = ft_cal_rotationX(resultat, m_rotationX);
	resultat = ft_cal_rotationY(resultat, m_rotationY);
	resultat = ft_cal_rotationZ(resultat, m_rotationZ);
	resultat = ft_cal_homothetie(resultat, m_homo);
	resultat = ft_cal_translation(resultat, m_translation);
	// resultat = ft_cal_projection(resultat, m_projection);
	return(resultat);
}

void ft_transform_map(t_env *tmp, int keycode)
{
	int i;
	int j;
	int x0;
	int y0;
	int z0;
	int w0;
	// int color;
	t_vecteur4 	resultat;

	i = 0;
	while (i < tmp->nb_line)
	{
		j = 0;
		while (j < tmp->nb_col)
		{
			x0 = tmp->map[i][j][0];
			y0 = tmp->map[i][j][1];
			z0 = tmp->map[i][j][2];
			w0 = tmp->map[i][j][3];
			// color = tmp->map[i][j][4];
			if (keycode == RESET)
				resultat = ft_reset_transformation(x0, y0, z0, w0, i, tmp);
			else
				resultat = ft_create_transformation(x0, y0, z0, w0, i, tmp);
			tmp->map_buffer[i][j][0] = resultat.x1;
			tmp->map_buffer[i][j][1] = resultat.y1;
			tmp->map_buffer[i][j][2] = resultat.z1;
			tmp->map_buffer[i][j][3] = resultat.w1;
			tmp->map_buffer[i][j][3] = resultat.w1;
			// tmp->map_buffer[i][j][4] = color;
			j++;
		}
		i++;
	}
	ft_draw_line_horiz(tmp);
	ft_draw_line_vertical(tmp);
}
