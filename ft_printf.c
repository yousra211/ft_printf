/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhamdaou <yhamdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:16:41 by yhamdaou          #+#    #+#             */
/*   Updated: 2025/11/20 16:06:56 by yhamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_func(char spec, va_list args)
{
	char	*string;

	if (spec == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (spec == 's')
	{
		string = va_arg(args, char *);
		return (ft_putstr(string));
	}
	else if (spec == '%')
		return (write(1, "%%", 1));
	else if (spec == 'p')
		return (ft_putadress(va_arg(args, void *)));
	else if (spec == 'd' || spec == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (spec == 'u')
		return (ft_printf_unsigned(va_arg(args, unsigned int)));
	else if (spec == 'x')
		return (ft_putnbrhex_low(va_arg(args, unsigned int)));
	else if (spec == 'X')
		return (ft_putnbrhex_up(va_arg(args, unsigned int)));
	return (0);
}

static int	handle_format(const char *str, int *i, va_list args)
{
	int	count;

	count = 0;
	if (str[*i] == '%' && str[*i + 1])
	{
		count = ft_func(str[*i + 1], args);
		(*i)++;
	}
	else
	{
		ft_putchar(str[*i]);
		count = 1;
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	args;

	va_start(args, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		count += handle_format(str, &i, args);
		i++;
	}
	va_end(args);
	return (count);
}

// #include <stdio.h>
// int main()
// {
// 	// char *str = "hello";
// 	// int n = -1238997987;
// 	printf("mine\n");
// 	int i = ft_printf("le mot est le %s", NULL);
// 	printf("\n%d\n", i);
// 	printf("original\n");
// 	int j = printf("le mot est le %s", NULL);
// 	printf("\n%d", j);
// }