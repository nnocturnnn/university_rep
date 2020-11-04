#include "malloc.h"

static void		*memmove(void *dst, const void *src, size_t n)
{
	unsigned char *temp_dst;
	unsigned char *temp_src;

	temp_dst = (unsigned char*)dst;
	temp_src = (unsigned char*)src;
	if (dst <= src)
	{
		while (n-- > 0)
			*temp_dst++ = *temp_src++;
	}
	else
	{
		temp_src = temp_src + n - 1;
		temp_dst = temp_dst + n - 1;
		while (n-- > 0)
			*temp_dst-- = *temp_src--;
	}
	return (dst);
}

static void		*do_realloc(int type, t_block *block, size_t size)
{
	void	*new_data;

	new_data = malloc(size);
	memmove(new_data, (char*)block + header_size(), block->size);
	free_block(type, block);
	return (new_data);
}

void			*mem_realloc(void *ptr, size_t size)
{
	t_block		*block;
	int			type;

	mode_log() ? log(REALLOC, NULL) : 0;
	if (!ptr)
		return (malloc(size));
	pthread_mutex_lock(&g_mutex);
	type = find_used_block(ptr, &block);
	pthread_mutex_unlock(&g_mutex);
	if (type == -1 || !block)
		return (NULL);
	if (size <= block->size)
		return (ptr);
	else
		return (do_realloc(type, block, size));
	return (NULL);
}
