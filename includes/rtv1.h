/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 15:20:52 by eaptekar          #+#    #+#             */
/*   Updated: 2018/09/05 21:28:59 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <mlx.h>
# include <math.h>
# include "libft.h"
# include "mlx_keys_linux.h"

# define WIN_W	860
# define WIN_H	860

# define VW_W	1.0
# define VW_H	1.0
# define DIST	1.0

# define T_MIN	1.0
# define T_MAX	1000.0

typedef struct	s_roots
{
	double		t1;
	double		t2;
}				t_roots;

typedef struct	s_vector
{
	double		x;
	double		y;
	double		z;
}				t_vector;

typedef struct	s_sphere
{
	t_vector	center;
	int			radius;
	int			color;
}				t_sphere;

typedef struct	s_window
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*image;
	int			bpp;
	int			size_line;
	int			endian;
}				t_window;

int				key_hook(int kcode, t_window *win);
int				pixel2image(t_window *win, int x, int y, int color);
void			draw_sphere(t_window *win);


double			mult_vect(t_vector v1, t_vector v2);
t_vector		sub_vect(t_vector v1, t_vector v2);
t_vector		num_mult_vec(double num, t_vector v);

#endif
