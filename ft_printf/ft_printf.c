/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 16:52:43 by tgernez           #+#    #+#             */
/*   Updated: 2022/11/15 10:36:38 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int	ft_is_ph(char c)
{
	int		i;

	i = -1;
	while (LIST_PH[++i])
	{
		if (c == LIST_PH[i])
			return (1);
	}
	return (0);
}

static int	ft_find_len_placeholder(char c, va_list args)
{
	if (c == 'c')
		return (ft_printer_c(va_arg(args, int)));
	else if (c == 's')
		return (ft_printer_s(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_printer_p(va_arg(args, void *)));
	else if (c == 'd')
		return (ft_printer_d(va_arg(args, int)));
	else if (c == 'i')
		return (ft_printer_i(va_arg(args, int)));
	else if (c == 'u')
		return (ft_printer_u(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (ft_printer_x(va_arg(args, int)));
	else if (c == 'X')
		return (ft_printer_upperx(va_arg(args, int)));
	else if (c == '%')
		return (write(1, "%", 1));
	return (-1);
}

int	ft_printf(const char *ph_str, ...)
{
	va_list	args;
	int		i;
	int		len;

	len = 0;
	i = -1;
	va_start(args, ph_str);
	while (ph_str[++i])
	{
		if (ph_str[i] == '%' && ph_str[i + 1] && ft_is_ph(ph_str[i + 1]))
		{
			len += ft_find_len_placeholder(ph_str[i + 1], args);
			i++;
		}
		else
		{
			write(1, &(ph_str[i]), 1);
			len++;
		}
	}
	va_end(args);
	return (len);
}
