#include <unistd.h>
#include <stdarg.h>

int g_var = 0;

void ft_itoa_base(long digit,int length,char *base)
{
	if (digit >= length)
		ft_itoa_base(digit/length, length, base);
	g_var += write(1, &base[digit % length], 1);
}

int ft_printf(const char *str, ...)
{
	g_var = 0;
	va_list va;
	va_start(va, str);
	int i = 0;
	while(str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 's')
			{
				char *string = va_arg(va, char *);
				int string_count = 0;
				while (string[string_count])
				{
					g_var += write(1, &string[string_count], 1);
					string_count++;
				}
			}
			if (str[i] == 'd')
			{
				long long decimal = va_arg(va, int);
				if (decimal < 0)
				{
					g_var += write(1, "-", 1);
					decimal = -decimal;
				}
				ft_itoa_base(decimal, 10, "0123456789");
			}
			if (str[i] == 'x')
			{
				long long hexa = va_arg(va, unsigned int);
				ft_itoa_base(hexa, 16, "0123456789abcdef");
			}
		}
		else
			g_var += write(1, &str[i], 1);
		i++;
	}
	va_end(va);
	return (g_var);
}

#include <stdio.h>
#include <limits.h>
int main()
{
	int i = ft_printf("--\nft_printf_exam = %x\n--\n", INT_MAX);
	printf("res = %d\n", i);
	int j = printf("--\n   printf      = %x\n--\n", INT_MAX);
	printf("res = %d\n", j);
}