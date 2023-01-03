/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer_xX.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:13:04 by tgernez           #+#    #+#             */
/*   Updated: 2022/11/08 14:06:14 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_printer_upperx(int nb)
{
	int	len;

	len = 0;
	ft_putnbr_ui_hexa_up(nb, &len);
	return (len);
}
