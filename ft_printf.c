/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhamdaou <yhamdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:16:41 by yhamdaou          #+#    #+#             */
/*   Updated: 2025/11/19 12:01:23 by yhamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"


int	ft_printf(const char *str, ...)
{
	int	i;
	int count;
	va_list args;
	va_start(args, str);

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] == 'c')
		{
			ft_putchar(va_arg(args, int));
			i++;
			count++;
		}
		else if (str[i] == '%' && str[i + 1] == 's')
		{
			char *string = va_arg(args, char *);
			ft_putstr(string);
			count += ft_strlen(string);
			i++;
		}
		else if (str[i] == '%' && str[i + 1] == 'p')
		{
			count += ft_putadress(va_arg(args, void *));
			i++;
		}
		else if (str[i] == '%' && (str[i + 1] == 'd' || str[i + 1] == 'i'))
		{
			count += ft_putnbr(va_arg(args, int));
			i++;
		}
		else if (str[i] == '%' && str[i + 1] == 'u')
		{
			count += ft_printf_unsigned(va_arg(args,unsigned int));
			i++;
		}
		else if (str[i] == '%' && str[i + 1] == 'x')
		{
			count += ft_putnbrhex_low(va_arg(args, int));
			i++;
		}
		else if (str[i] == '%' && str[i + 1] == 'X')
		{
			count += ft_putnbrhex_up(va_arg(args, int));
			i++;
		}
		else if (str[i] == '%' && str[i + 1] == '%')
		{
			write(1, "%%", 1);
			count++;
			i++;
		}
		else
		{
			ft_putchar(str[i]);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}

#include <stdio.h>
int main()
{
	char *str = "hello";
	printf("mine\n");
	int i = ft_printf("le mot est %s", str);
	printf("\n%d", i);
	printf("original\n");
	int j = printf("le mot est %s", str);
	printf("\n%d", j);
}