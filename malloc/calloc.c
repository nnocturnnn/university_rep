#include "malloc.h"

void			*memset(void *b, int c, size_t len)
{
	char *temp;

	temp = (char*)b;
	while (len-- > 0)
	{
		*temp++ = (unsigned char)c;
	}
	return (b);
}

void			bzero(void *s, size_t n)
{
	memset(s, 0, n);
}

void			*calloc(size_t count, size_t size)
{
	void	*data;

	data = malloc(count * size);
	if (data)
		bzero(data, count * size);
	mode_log() ? log(CALLOC, NULL) : 0;
	return (data);
}
