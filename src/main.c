/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 18:27:14 by eaptekar          #+#    #+#             */
/*   Updated: 2018/09/15 20:26:35 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

// strerror(errno) instead -1

t_vector	get_viewport(int x, int y)
{
	t_vector	ray;

	ray.x = (x * VW_W) / WIN_W;
	ray.y = (y * VW_H) / WIN_H;
	ray.z = DIST;
	return (ray);
}

int		main(void)
{
	t_window	win;

	if (!(win.mlx_ptr = mlx_init()))
		return (-1);
	if (!(win.win_ptr = mlx_new_window(win.mlx_ptr, WIN_W, WIN_H, "RTv1")))
		return (-1);
	parse_figures(&win);
	mlx_hook(win.win_ptr, 17, (1L << 17), exit_redcross, &win);
	mlx_hook(win.win_ptr, 2, (1L << 0), key_hook, &win);
	mlx_loop(win.mlx_ptr);
	return (0);
}
