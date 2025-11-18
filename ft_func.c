/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhamdaou <yhamdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:18:10 by yhamdaou          #+#    #+#             */
/*   Updated: 2025/11/18 19:05:43 by yhamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

int	ft_putnbrhex_low(unsigned long s)
{
	char *hex;
	int	count;
	
	hex = "0123456789abcdef";
	count = 0;
	if (s >= 16)
		count += ft_putnbrhex_low(s / 16);
	ft_putchar(hex[s % 16]);
	count++;
	return (count);
}

int	ft_putnbrhex_up(unsigned long s)
{
	char *hex;
	int count;
	
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
	unsigned long s;
	int count;
	
	s = (unsigned long)str;
	write(1, "0x", 2);
	count = ft_putnbrhex_low(s);
	return (count);
}

int	ft_putnbr(int nbr)
{
	long x;
	int c;
	
	x = nbr;
	c = 0;
	if (x < 0)
	{
		x = -x;
		write(1, "-", 1);
	}
	if (x > 9)
		c += ft_putnbr(x / 10);
	ft_putchar (x % 10);
	c++;
	return (c);
}

int	ft_printf_unsigned(unsigned int n)
{
	int c;

	c = 0;
	if (n > 9)
		c += ft_printf_unsigned(n / 10);
	ft_putchar((n % 10) + '0');
	c++;
	return(c);
}

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return(i);
}
