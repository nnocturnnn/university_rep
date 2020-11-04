#include "malloc.h"

t_block			*choose_free_block(int type, size_t size)
{
	t_block		*block;
	t_block		*last;
	int			i;

	i = 0;
	block = g_heap[type].free;
	last = NULL;
	while (block)
	{
		i++;
		last = block;
		if (block->size >= size)
		{
			mode_stat() ? stat_malloc(i) : 0;
			return (block);
		}
		block = block->next;
	}
	mode_stat() ? stat_malloc(++i) : 0;
	return (add_free_block(last, type, size));
}

t_block			*add_free_block(t_block *last, int type, size_t size)
{
	if (last)
	{
		last->next = extend_free_pool(last, type, size);
		return (last->next);
	}
	else
	{
		g_heap[type].free = extend_free_pool(last, type, size);
		return (g_heap[type].free);
	}
}

t_block			*extend_free_pool(void *last, int type, size_t size)
{
	t_block		*block;
	size_t		pages;

	if (type == TINY)
	{
		pages = align_size((TINY_BLOCK + header_size() * NB_BLOCKS),\
			getpagesize());
	}
	else if (type == SMALL)
	{
		pages = align_size((SMALL_BLOCK + header_size() * NB_BLOCKS),\
			getpagesize());
	}
	else
		pages = align_size(size + header_size(), getpagesize());
	block = request_memory(last + header_size(), pages);
	block->size = pages - header_size();
	block->prev = last;
	block->next = NULL;
	return (block);
}

t_block			*request_memory(void *last, size_t size)
{
	t_block *tmp;

	if ((tmp = mmap(last, size, PROT_READ | PROT_WRITE | PROT_EXEC,\
		MAP_ANON | MAP_PRIVATE, -1, 0)) == MAP_FAILED)
	{
		return (NULL);
	}
	return (tmp);
}

void			move_block_to_use(int type, t_block *block)
{
	delete_block(&g_heap[type].free, block);
	insert_block_top(&g_heap[type].in_use, block);
}
