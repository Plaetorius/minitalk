/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 16:52:51 by tgernez           #+#    #+#             */
/*   Updated: 2022/11/10 14:48:21 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# define LIST_PH "cspdiuxX%"
# define HEXA_LOW "0123456789abcdef"
# define HEXA_UP "0123456789ABCDEF"

int		ft_printf(const char *placeholders, ...);

/*PRINTERS*/
int		ft_printer_c(int c);
int		ft_printer_d(int nb);
int		ft_printer_i(int nb);
int		ft_printer_p(void *addr);
int		ft_printer_s(char *str);
int		ft_printer_u(unsigned int nb);
int		ft_printer_x(int nb);
int		ft_printer_upperx(int nb);

/*STRINGS*/
char	*ft_strupper(char *str);
char	*ft_str_maker(int nb);

/*NUMBERS*/
void	ft_putnbr_int(int nb, int *len);
void	ft_putnbr_ui(unsigned int nb, int *len);

/*HEXADECIMAL*/
int		ft_len_nb_hexa(long nb);
int		ft_putnbr_ul_hexa(unsigned long nb);
int		ft_putnbr_ui_hexa_low(unsigned int nb, int *len);
int		ft_putnbr_ui_hexa_up(unsigned int nb, int *len);

#endif
