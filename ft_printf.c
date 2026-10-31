/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenomar <abenomar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 14:16:16 by abenomar          #+#    #+#             */
/*   Updated: 2026/10/30 17:24:28 by abenomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(char c, va_list *args)
{
	if (c == 'c')
		return (ft_print_char(va_arg(*args, int)));
	else if (c == 's')
		return (ft_print_s(va_arg(*args, char *)));
	else if (c == 'p')
		return (ft_print_ptr(va_arg(*args, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_print_nums(va_arg(*args, int)));
	else if (c == 'u')
		return (ft_print_unsigned(va_arg(*args, unsigned int)));
	else if (c == 'x')
		return (ft_print_hex(va_arg(*args, unsigned int), "0123456789abcdef"));
	else if (c == 'X')
		return (ft_print_hex(va_arg(*args, unsigned int), "0123456789ABCDEF"));
	else if (c == '\0')
		return (-1);
	else if (c == '%')
		return (write(1, "%", 1));
	if (write(1, "%", 1) == -1)
		return (-1);
	if (write(1, &c, 1) == -1)
		return (-1);
	return (2);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	int		ret;
	va_list	args;

	if (!format)
		return (-1);
	count = 0;
	va_start(args, format);
	while (count != -1 && *format)
	{
		if (*format == '%')
		{
			ret = ft_format(*(format + 1), &args);
			format++;
		}
		else
			ret = write(1, format, 1);
		if (ret == -1)
			count = -1;
		else
			count += ret;
		format++;
	}
	va_end(args);
	return (count);
}
