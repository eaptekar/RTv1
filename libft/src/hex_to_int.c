/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_to_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 16:00:44 by eaptekar          #+#    #+#             */
/*   Updated: 2018/08/07 14:34:03 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		nibble_to_num(const char nibble)
{
	if (nibble >= '0' && nibble <= '9')
		return (nibble - '0');
	if (nibble >= 'a' && nibble <= 'f')
		return (nibble - 'a' + 0xa);
	if (nibble >= 'A' && nibble <= 'F')
		return (nibble - 'A' + 0xa);
	return (0);
}

int		hex_to_int(const char *str)
{
	int	output;
	int			digit;

	output = 0;
	digit = nibble_to_num(*str);
	while (*str && *str != ' ')
	{
		output = output << 4 | digit;
		str++;
		digit = nibble_to_num(*str);
	}
	return (output);
}
