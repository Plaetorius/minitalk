/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:09:14 by tgernez           #+#    #+#             */
/*   Updated: 2022/11/08 14:08:42 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_printer_u(unsigned int nb)
{
	int	len;

	len = 0;
	ft_putnbr_ui(nb, &len);
	return (len);
}
