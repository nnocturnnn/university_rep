#include "malloc.h"

static size_t	strlen(const char *s)
{
	char const *temp;

	temp = s;
	while (*temp)
		temp++;
	return (temp - s);
}

void			putchar(char c)
{
	write(1, &c, 1);
}

void			putchar_fd(int fd, char c)
{
	write(fd, &c, 1);
}

void			putstr(char const *str)
{
	if (str)
		write(1, str, strlen(str));
}

void			putstr_fd(int fd, char const *str)
{
	if (str)
		write(fd, str, strlen(str));
}
