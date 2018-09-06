/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 18:38:42 by eaptekar          #+#    #+#             */
/*   Updated: 2018/09/05 21:52:19 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		key_hook(int kcode, t_window *win)
{
	if (kcode == K_ESC)
	{
		mlx_clear_window(win->mlx_ptr, win->win_ptr);
		mlx_destroy_image(win->mlx_ptr, win->img_ptr);
		mlx_destroy_window(win->mlx_ptr, win->win_ptr);
		exit(1);
	}
	return (0);
}
