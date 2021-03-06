/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 18:38:42 by eaptekar          #+#    #+#             */
/*   Updated: 2018/10/08 15:38:12 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		free_exit(t_window *win)
{
	mlx_clear_window(win->mlx_ptr, win->win_ptr);
	mlx_destroy_image(win->mlx_ptr, win->img_ptr);
	mlx_destroy_window(win->mlx_ptr, win->win_ptr);
	exit(1);
	return (0);
}

int		expose_hook(t_window *win)
{
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr, 0, 0);
	return (0);
}

int		key_hook(int kcode, t_window *win)
{
	if (kcode == K_ESC)
		free_exit(win);
	return (0);
}
