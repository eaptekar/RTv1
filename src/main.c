/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 18:27:14 by eaptekar          #+#    #+#             */
/*   Updated: 2018/09/23 15:53:21 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "parser.h"

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

void		choose_scene(char c, t_window *win)
{
	if (c == '1')
		scene1(win);
	else if (c == '2')
		scene2(win);
	else if (c == '3')
		scene3(win);
	else if (c == '4')
		scene4(win);
	else if (c == '5')
		scene5(win);
	else if (c == '6')
		scene6(win);
	else if (c == '7')
		scene7(win);
	else if (c == '8')
	{
		ft_putendl("Set WIN_W to 1920 for better view.");
		scene8(win);
	}
	else	
	{
		ft_putendl("Scene is missing");
		free_exit(win);
	}
}

int			main(/*int argc, char **argv*/void)
{
	t_window	win;

//	if (argc != 2)
//		ERROR("usage: ./RTv1 <num>");
	if (!(win.mlx_ptr = mlx_init()))
		ERROR(strerror(errno));
	if (!(win.win_ptr = mlx_new_window(win.mlx_ptr, WIN_W, WIN_H, "RTv1")))
		ERROR(strerror(errno));
	if (!(win.img_ptr = mlx_new_image(win.mlx_ptr, WIN_W, WIN_H)))
		ERROR(strerror(errno));
	win.image = mlx_get_data_addr(win.img_ptr, &(win.bpp), \
		&(win.size_line), &(win.end));
	win.bpp = win.bpp >> 3;

    t_scene *scene = parse_file("scenes/demo"); 
    print_scene(scene);
    draw_scene(&win,*parse_file("scenes/demo"));

	mlx_hook(win.win_ptr, 17, (1L << 17), free_exit, &win);
	mlx_hook(win.win_ptr, 12, (1L << 15), expose_hook, &win);
	mlx_hook(win.win_ptr, 2, (1L << 0), key_hook, &win);
	mlx_loop(win.mlx_ptr);
    free(scene);
	return (0);
}
