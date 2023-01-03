/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ui.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 21:06:49 by tgernez           #+#    #+#             */
/*   Updated: 2022/11/08 11:54:08 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	ft_putnbr_ui(unsigned int nb, int *len)
{
	char	int_char;
	char	last_digit;

	last_digit = (nb % 10) + '0';
	if (nb < 10)
	{
		int_char = nb + '0';
		*len += write(1, &int_char, 1);
	}
	else
	{
		ft_putnbr_ui(nb / 10, len);
		*len += write(1, &last_digit, 1);
	}
}
