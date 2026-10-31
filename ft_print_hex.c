/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenomar <abenomar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 13:32:48 by abenomar          #+#    #+#             */
/*   Updated: 2026/10/28 10:41:59 by abenomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned long n, char *base)
{
	int	count;

	count = 0;
	if (n >= 16)
	{
		count = ft_print_hex(n / 16, base);
		if (count == -1)
			return (-1);
	}
	if (write(1, &base[n % 16], 1) == -1)
		return (-1);
	return (count + 1);
}
