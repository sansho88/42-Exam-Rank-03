#include <unistd.h>
#include <stdarg.h>

int g_var = 0;

/*char *ft_itoa_base(int digit,int length,char *base)
{

}*/

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
				//ft_itoa_base(decimal, 10, "0123456789");
			}
			if (str[i] == 'x')
			{
				long long hexa = va_arg(va, int);
				//ft_itoa_base(hexa, 16, "0123456789abcdef");
			}
		}
		else
			g_var += write(1, &str[i], 1);
		i++;
	}
	return (g_var);
}

#include <stdio.h>
int main()
{
	int i = ft_printf("--\nft_printf_exam = %s\n--\n", "test");
	printf("res = %d\n", i);
	int j = printf("--\n   printf      = %s\n--\n", "test");
	printf("res = %d\n", j);
}