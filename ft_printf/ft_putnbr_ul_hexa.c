/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ul_hexa.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 16:52:59 by tgernez           #+#    #+#             */
/*   Updated: 2022/11/08 14:08:23 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static void	ft_hexa_writer(unsigned long nb, int i, int *len)
{
	char	c;

	if (nb >= 16)
	{
		ft_hexa_writer(nb / 16, i - 1, len);
		c = HEXA_LOW[nb % 16];
		*len += write(1, &c, 1);
	}
	else
	{
		c = HEXA_LOW[nb];
		*len += write(1, &c, 1);
	}
}

int	ft_putnbr_ul_hexa(unsigned long nb)
{
	int	len;

	len = 0;
	ft_hexa_writer(nb, ft_len_nb_hexa(nb) - 1, &len);
	return (len);
}
