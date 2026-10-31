/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nums.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenomar <abenomar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 14:16:25 by abenomar          #+#    #+#             */
/*   Updated: 2026/10/28 10:41:16 by abenomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nums(int n)
{
	int		count;
	int		ret;
	long	nb;
	char	c;

	nb = n;
	count = 0;
	if (nb < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		nb = -nb;
		count++;
	}
	if (nb > 9)
	{
		ret = ft_print_nums(nb / 10);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	c = (nb % 10) + '0';
	if (write(1, &c, 1) == -1)
		return (-1);
	return (count + 1);
}
