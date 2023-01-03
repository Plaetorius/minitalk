/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:43:51 by tgernez           #+#    #+#             */
/*   Updated: 2022/11/08 14:14:28 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_printer_p(void *addr)
{
	if (addr)
		return (write(1, "0x", 2) + ft_putnbr_ul_hexa((unsigned long) addr));
	return (write(1, "(nil)", 5));
}
