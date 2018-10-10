/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 18:27:14 by eaptekar          #+#    #+#             */
/*   Updated: 2018/10/10 20:00:27 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vector	get_viewport(int x, int y, int width)
{
	t_vector	ray;

	ray.x = (x * 1.0) / width;
	ray.y = (y * 1.0) / width;
	ray.z = DIST;
	return (ray);
}

int			pixel_to_image(t_window *win, int x, int y, int color)
{
	int		i;

	i = -1;
	if (x >= win->win_w || x < 1 || y >= win->win_h || y < 1)
		return (1);
	while (++i < win->bpp)
	{
		if (!(win->end))
			win->image[y * win->size_line + x * win->bpp + i] = \
		color >> (i << 3) & 0xFF;
		else
			win->image[y * win->size_line + x * win->bpp + i] = \
		color >> (win->bpp - ((i + 1) << 3)) & 0xFF;
	}
	return (0);
}

int			main(int argc, char **argv)
{
	t_window	win;
	t_scene		*scene;

	if (argc != 2)
		ERROR("usage: ./RTv1 <scene_file>");
	scene = parse_file(argv[1]);
	if (!(win.mlx_ptr = mlx_init()))
		ERROR(strerror(errno));
	if (!(win.win_ptr = mlx_new_window(win.mlx_ptr, scene->win_w, \
		scene->win_h, "RTv1")))
		ERROR(strerror(errno));
	if (!(win.img_ptr = mlx_new_image(win.mlx_ptr, scene->win_w, scene->win_h)))
		ERROR(strerror(errno));
	win.image = mlx_get_data_addr(win.img_ptr, &(win.bpp), \
		&(win.size_line), &(win.end));
	win.bpp = win.bpp >> 3;
	draw_scene(&win, *scene);
	mlx_hook(win.win_ptr, 17, (1L << 17), free_exit, &win);
	mlx_hook(win.win_ptr, 12, (1L << 15), expose_hook, &win);
	mlx_hook(win.win_ptr, 2, (1L << 0), key_hook, &win);
	mlx_loop(win.mlx_ptr);
	return (0);
}
