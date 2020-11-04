#include "malloc.h"

pthread_mutex_t g_mutex = PTHREAD_MUTEX_INITIALIZER;

static int		choose_pool(size_t size)
{
	if (size <= TINY_BLOCK)
		return (TINY);
	else if (size <= SMALL_BLOCK)
		return (SMALL);
	else
		return (LARGE);
}

static t_block	*alloc_large(size_t size)
{
	t_block		*block;
	size_t		pages;

	pages = align_size(size + header_size(),\
		getpagesize());
	block = request_memory(NULL, pages);
	block->size = pages - header_size();
	block->prev = NULL;
	block->next = NULL;
	insert_block_top(&g_heap[LARGE].in_use, block);
	mode_stat() ? stat_malloc(1) : 0;
	return (block);
}

void	*mem_alloc(size_t size)
{
	unsigned int	type;
	t_block			*block;

	pthread_mutex_lock(&g_mutex);
	size = align_size(size, 16);
	type = choose_pool(size);
	if (type == TINY || type == SMALL)
	{
		block = choose_free_block(type, size);
		if (!block)
			return (NULL);
		block->next = split_block(block, type, size);
		move_block_to_use(type, block);
	}
	else
		block = alloc_large(size);
	mode_log() ? log(MALLOC, block) : 0;
	pthread_mutex_unlock(&g_mutex);
	return ((void*)((char*)block + header_size()));
}
