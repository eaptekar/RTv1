/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deg_to_rad.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 19:58:34 by eaptekar          #+#    #+#             */
/*   Updated: 2018/08/07 21:19:02 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define PI 		3.14159265359

double	deg_to_rad(double degree)
{
	double angle;

	angle = degree * PI / 180;
	return (angle);
}
