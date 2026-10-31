/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenomar <abenomar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 14:16:46 by abenomar          #+#    #+#             */
/*   Updated: 2026/10/31 18:37:18 by abenomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_printf(const char *format, ...);
int	ft_print_s(char *s);
int	ft_print_ptr(void *ptr);
int	ft_print_hex(unsigned long n, char *base);
int	ft_print_char(int c);
int	ft_print_nums(int n);
int	ft_print_unsigned(unsigned int n);

#endif