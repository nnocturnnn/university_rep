#include "malloc.h"

static void		dump_hexa(const void *addr)
{
	const char	hex[16] = "0123456789abcdef";
	int			temp;

	temp = *(char*)addr >> 4 & 0x0F;
	write(1, &hex[temp], 1);
	temp = *(char*)addr & 0x0F;
	write(1, &hex[temp], 1);
}

static void		print_last_line(int i, char s[16])
{
	size_t	a;

	if (i % 16 != 0)
	{
		a = i;
		while (a % 16 != 0)
		{
			write(1, "  ", 2);
			if (a % 2 == 0)
				write(1, " ", 1);
			a++;
		}
		if (i % 2 == 1)
			write(1, " ", 1);
		write(1, s, i % 16);
		write(1, "\n", 1);
	}
	write(1, "\n", 1);
}

void			print_memory(const void *addr, size_t size)
{
	char	s[16];
	size_t	i;

	bzero(s, 16);
	i = 0;
	while (i < size)
	{
		dump_hexa(addr);
		s[i % 16] = *(char*)addr;
		if (s[i % 16] < 32 || s[i % 16] > 126)
			s[i % 16] = '.';
		i++;
		if (i % 2 == 0)
			write(1, " ", 1);
		if (i % 16 == 0)
		{
			write(1, s, 16);
			write(1, "\n", 1);
			bzero(s, 16);
		}
		addr++;
	}
	print_last_line(i, s);
}
