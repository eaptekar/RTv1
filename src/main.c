/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 18:27:14 by eaptekar          #+#    #+#             */
/*   Updated: 2018/09/19 16:17:04 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vector	get_viewport(int x, int y)
{
	t_vector	ray;

	ray.x = (x * VW_W) / WIN_W;
	ray.y = (y * VW_H) / WIN_H;
	ray.z = DIST;
	return (ray);
}

int			pixel_to_image(t_window *win, int x, int y, int color)
{
	int		i;

	i = -1;
	if (x >= WIN_W || x < 1 || y >= WIN_H || y < 1)
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

	if (argc != 2)
		ERROR("usage: ./RTv1 <num>");
	if (!(win.mlx_ptr = mlx_init()))
		ERROR(strerror(errno));
	if (!(win.win_ptr = mlx_new_window(win.mlx_ptr, WIN_W, WIN_H, "RTv1")))
		ERROR(strerror(errno));
	if (!(win.img_ptr = mlx_new_image(win.mlx_ptr, WIN_W, WIN_H)))
		ERROR(strerror(errno));
	win.image = mlx_get_data_addr(win.img_ptr, &(win.bpp), \
		&(win.size_line), &(win.end));
	win.bpp = win.bpp >> 3;
	if (*argv[1] == '1')
		scene1(&win);
	else if (*argv[1] == '2')
		scene2(&win);
	else
		ERROR("Scene is missing");
	mlx_hook(win.win_ptr, 17, (1L << 17), exit_redcross, &win);
	mlx_hook(win.win_ptr, 12, (1L << 15), expose_hook, &win);
	mlx_hook(win.win_ptr, 2, (1L << 0), key_hook, &win);
	mlx_loop(win.mlx_ptr);
	return (0);
}
