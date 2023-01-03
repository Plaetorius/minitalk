/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 21:06:49 by tgernez           #+#    #+#             */
/*   Updated: 2022/11/08 13:24:15 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	ft_putnbr_int(int nb, int *len)
{
	char	int_char;
	char	last_digit;

	if (nb == -2147483648)
		*len += write(1, "-2147483648", 11);
	else
	{
		if (nb < 0)
		{	
			*len += write(1, "-", 1);
			nb = -nb;
		}
		last_digit = (nb % 10) + '0';
		if (nb < 10)
		{
			int_char = nb + '0';
			*len += write(1, &int_char, 1);
		}
		else
		{
			ft_putnbr_int(nb / 10, len);
			*len += write(1, &last_digit, 1);
		}
	}
}
