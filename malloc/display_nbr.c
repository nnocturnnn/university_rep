#include "malloc.h"

void	putnbr(int n)
{
	long int	nb;
	int			len;
	char		s[10];

	nb = (long int)n;
	if (nb == 0)
		putchar('0');
	if (nb < 0)
	{
		nb = -nb;
		putchar('-');
	}
	len = 0;
	while (nb > 0)
	{
		s[len++] = nb % 10 + 48;
		nb = nb / 10;
	}
	while (len-- > 0)
		putchar(s[len]);
}

void	putnbr_fd(int fd, int n)
{
	long int	nb;
	int			len;
	char		s[10];

	nb = (long int)n;
	if (nb == 0)
		putchar_fd(fd, '0');
	if (nb < 0)
	{
		nb = -nb;
		putchar_fd(fd, '-');
	}
	len = 0;
	while (nb > 0)
	{
		s[len++] = nb % 10 + 48;
		nb = nb / 10;
	}
	while (len-- > 0)
		putchar_fd(fd, s[len]);
}

void	putnbr_str(char *str, int n)
{
	putstr(str);
	putchar(' ');
	putnbr(n);
	putchar('\n');
}
