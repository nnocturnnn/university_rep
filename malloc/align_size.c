#include "malloc.h"

size_t		header_size(void)
{
	return (align_size(sizeof(t_block), 16));
}

size_t		align_size(size_t size, size_t multiple)
{
	if (size == 0)
		return (multiple);
	return (((((size) - 1) / multiple) * multiple) + multiple);
}
