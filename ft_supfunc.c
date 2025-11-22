/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_supfunc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhamdaou <yhamdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 15:54:19 by yhamdaou          #+#    #+#             */
/*   Updated: 2025/11/20 15:57:54 by yhamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nbr)
{
	long	x;
	int		c;

	x = nbr;
	c = 0;
	if (x < 0)
	{
		x = -x;
		write(1, "-", 1);
	}
	if (x > 9)
		c += ft_putnbr(x / 10);
	ft_putchar ((x % 10) + '0');
	c++;
	return (c);
}

int	ft_printf_unsigned(unsigned int n)
{
	int	c;

	c = 0;
	if (n > 9)
		c += ft_printf_unsigned(n / 10);
	ft_putchar((n % 10) + '0');
	c++;
	return (c);
}
