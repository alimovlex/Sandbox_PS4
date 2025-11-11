#include <unistd.h>
#define MKSTR( x ) #x

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static void	ft_putstr(const char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

static void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(-nb);
	}
	else if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		ft_putchar(nb + '0');
	}
}

void ft_logger(char* LOG_LEVEL, void(*func)())
{
	ft_putstr("EXECUTING:");
	ft_putstr(MKSTR(func));
	func();
	char LINE[] = {__LINE__ + '0'};
 	const char *messages[] = {
		LOG_LEVEL,
    __DATE__,
    __TIME__,
    __FILE__,
		__PRETTY_FUNCTION__
	};

	int i, n; 
	n = sizeof(messages) / sizeof(messages[0]);
	ft_putstr(LOG_LEVEL);
	for (i = 0; i < n; ++i) {
		ft_putchar('[');
    ft_putstr(messages[i]);
		ft_putchar(']');					          
	}
	ft_putnbr(__LINE__);
	ft_putchar('\n');
}