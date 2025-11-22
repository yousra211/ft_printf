/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhamdaou <yhamdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:18:10 by yhamdaou          #+#    #+#             */
/*   Updated: 2025/11/20 15:55:37 by yhamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_putnbrhex_low(unsigned int s)
{
	char	*hex;
	int		count;

	hex = "0123456789abcdef";
	count = 0;
	if (s >= 16)
		count += ft_putnbrhex_low(s / 16);
	ft_putchar(hex[s % 16]);
	count++;
	return (count);
}

int	ft_putnbrhex_up(unsigned int s)
{
	char	*hex;
	int		count;

	hex = "0123456789ABCDEF";
	count = 0;
	if (s >= 16)
		count += ft_putnbrhex_up(s / 16);
	ft_putchar(hex[s % 16]);
	count++;
	return (count);
}

int	ft_putadress(void *str)
{
	unsigned long	s;
	int				count;

	count = 2;
	s = (unsigned int)str;
	write(1, "0x", 2);
	count += ft_putnbrhex_low(s);
	return (count);
}
