#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_putadress(void *str);
int		ft_putnbrhex_low(unsigned long s);
int		ft_putnbrhex_up(unsigned long s);
int		ft_putnbr(int nbr);
int		ft_printf_unsigned(unsigned int n);
int		ft_strlen(char *str);

// int	ft_printf(const char *str, ...);

#endif