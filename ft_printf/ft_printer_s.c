/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:42:14 by tgernez           #+#    #+#             */
/*   Updated: 2022/11/10 11:40:05 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include "includes/libft.h"

int	ft_printer_s(char *str)
{
	if (str)
		return (write(1, str, ft_strlen(str)));
	return (write(1, "(null)", 6));
}
