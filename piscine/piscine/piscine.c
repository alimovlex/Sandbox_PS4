#include <unistd.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div;
	int	mod;

	if (b != NULL && *b != 0)
	{
		div = *a / *b;
		mod = *a % *b;
	}
	else
		return ;
}

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	if (b != 0)
	{
		*div = a / b;
		*mod = a % b;
	}
	else
		return ;
}

void	ft_swap(int *a, int *b)
{
	int	temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_ultimate_ft(int *********nbr)
{
	*********nbr = 42;
}

void	ft_ft(int *nbr)
{
	*nbr = 42;
}

void	ft_is_negative(int n)
{
	if (n >= 0)
		write(1, "P", 1);
	else
		write(1, "N", 1);
}

void	ft_print_numbers(void)
{
	char	c[1];

	c[0] = '0';
	while (c[0] <= '9')
	{
		write(1, c, 1);
		c[0]++;
	}
}

void	ft_print_reverse_alphabet(void)
{
	char	character;

	character = 'z';
	while (character >= 'a')
	{
		write(1, &character, 1);
		character--;
	}
}

void	ft_print_alphabet(void)
{
	char	character;

	character = 'a';
	while (character <= 'z')
	{
		write(1, &character, 1);
		character++;
	}
}

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

void test() 
{
  ft_putstr("*****HELLO WORLD HERE*****");
  int num = 55, a = 11, b = 12;
	int *div = &a;
	int *mod = &b;
	
	int *first_ptr = &num;
	int **second_ptr = &first_ptr;
	int ***third_ptr = &second_ptr;
	int ****fourth_ptr = &third_ptr;
	int *****fifth_ptr = &fourth_ptr;
	int ******sixth_ptr = &fifth_ptr;
	int *******seventh_ptr = &sixth_ptr;
	int ********eighth_ptr = &seventh_ptr;
	int *********nineth_ptr = &eighth_ptr;

	ft_putchar('\n');
  ft_print_numbers();
	ft_putchar('\n');
  ft_print_alphabet();
	ft_putchar('\n');
  ft_print_reverse_alphabet();
	ft_putchar('\n');
  ft_is_negative(-1);
	ft_is_negative(10);
	ft_ft(&num);
  ft_swap(&a, &b);
	ft_div_mod(a, b, div, mod);
	ft_ultimate_div_mod(&a, &b);
}