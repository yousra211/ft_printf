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
	ft_printf_unsigned(-22);
}


