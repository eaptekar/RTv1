/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 18:42:50 by eaptekar          #+#    #+#             */
/*   Updated: 2018/09/05 22:05:32 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

#include <stdio.h>

int			pixel2image(t_window *win, int x, int y, int color)
{
	if (x >= WIN_W || x < 1 || y >= WIN_H || y < 1)
		return (1);
	printf("%d %d %X\n", x, y, color);
	win->image = mlx_get_data_addr(win->img_ptr, &(win->bpp), &(win->size_line), &(win->endian));
	ft_memmove((void*)(&(win->image)[y * win->size_line + \
		x * (win->bpp / 8)]), (void*)&color, 4);
	return (0);
}

t_vector	get_viewport(int x, int y)
{
	t_vector	ray;

	ray.x = (x * VW_W) / WIN_W;
	ray.y = (y * VW_H) / WIN_H;
	ray.z = DIST;
	return (ray);
}

t_roots		get_roots(t_vector cam, t_vector ray, t_sphere s)
{
	double		a;
	double		b;
	double		c;
	double		discr;
	t_roots		t;

	a = mult_vect(ray, ray);
	b = 2 * mult_vect(sub_vect(cam, s.center), ray);
	c = mult_vect(sub_vect(cam, s.center), sub_vect(cam, s.center)) - s.radius * s.radius;
	discr = b * b - 4 * a * c;
	if (discr < 0)
	{
		t.t1 = T_MAX;
		t.t2 = T_MAX;
		return (t);
	}
	t.t1 = (-b + sqrt(discr)) / (2 * a);
	t.t2 = (-b - sqrt(discr)) / (2 * a);
	return (t);
}

int			raytrace(t_vector cam, t_vector ray, int i)
{
	t_sphere	s[3];
	t_roots		t;
	double		closest_t;
	int			closest_sphere;
	int			color;

	s[0].center.x = 0;
	s[0].center.y = 0;
	s[0].center.z = 3;
	s[0].radius = 1;
	s[0].color = 0xFF0000;
	s[1].center.x = 2;
	s[1].center.y = 0;
	s[1].center.z = 4;
	s[1].radius = 1;
	s[1].color = 0x0000FF;
	s[2].center.x = -2;
	s[2].center.y = 0;
	s[2].center.z = 4;
	s[2].radius = 1;
	s[2].color = 0x00FF00;
	closest_t = T_MAX;
	closest_sphere = -1;
	i = 0;
	while (i < 3)
	{
		t = get_roots(cam, ray, s[i]);
		if (t.t1 < closest_t && t.t1 < T_MAX && t.t1 > T_MIN)
		{
			closest_t = t.t1;
			closest_sphere = i;
		}
		else if (t.t2 < closest_t && t.t2 < T_MAX && t.t2 > T_MIN)
		{
			closest_t = t.t2;
			closest_sphere = i;
		}
		i++;
	}
	// printf("%d %lf", closest_sphere, closest_t);
	if (closest_sphere == -1)
		color = 0xFFFFFF;
	else
		color = s[closest_sphere].color;
	return (color);
}

void		draw_sphere(t_window *win)
{
	t_vector	cam;
	t_vector	ray;
	int			x;
	int			y;
	int			color;
	int			scr_x;
	int			scr_y;

	scr_y = 0;
	cam.x = 0;
	cam.y = 0;
	cam.z = 0;
	y = -(WIN_H / 2);
	while (y < (WIN_H / 2))
	{
		x = -(WIN_W / 2);
		scr_x = 0;
		while (x < (WIN_W / 2))
		{
			ray = get_viewport(x, y);
			printf("%f %f %f\n", ray.x, ray.y, ray.z);
			color = raytrace(cam, ray, 0);
//			pixel2image(win, scr_x, scr_y, color);
			mlx_pixel_put(win->mlx_ptr, win->win_ptr, scr_x, scr_y, color);
			x++;
			scr_x++;
		}
		scr_y++;
		y++;
	}	
}
