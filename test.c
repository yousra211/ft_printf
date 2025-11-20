#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
// void	ft_putnbrhex(unsigned long s)
// {
// 	char *hex;
	
// 	hex = "0123456789abcdef";
// 	while (s != 0)
// 	{
// 		// ft_putchar(hex[s % 16]);
// 		printf("%d", hex[s % 16]);
// 		s = s / 16;
// 	}
// }

void	ft_putnbrhex(unsigned long s)
{
	char *hex;
	
	hex = "0123456789abcdef";
	if (s >= 16)
		ft_putnbrhex(s / 16);
	ft_putchar(hex[s % 16]);
}

void	ft_putadress(void *str)
{
	unsigned long s = (unsigned long)str;
	char *hex;
	
	write(1, "0x", 2);
	ft_putnbrhex(s);
}


void	ft_printf_unsigned(unsigned int n)
{
	if (n > 9)
		ft_printf_unsigned(n / 10);
	ft_putchar((n % 10) + '0');
}

void	ft_putnbr(int nbr)
{
	long x;
	// int c;
	
	x = nbr;
	// c = 0;
	if (x < 0)
	{
		x = -x;
		write(1, "-", 1);
	}
	if (x > 9)
		ft_putnbr(x / 10);
	ft_putchar (x % 10 + '0');
	// c++;
	// return (c);
}

int main()

{
	// char *str = "hello";

	// unsigned long s = (unsigned long)str;
	// printf("\nhere :\n");
	// printf("\n%p\n", str);
	// printf("\n0x%lx\n", s);

	// printf("\n%lu\n", str);
	// printf("\n%lu\n", s);
	// ft_putadress(str);

	// printf("%u", -2147483648);
	// ft_printf_unsigned(-22);
	ft_putnbr(123);
	// int i = ft_putnbr(123);
	// printf ("%d", i);
}


