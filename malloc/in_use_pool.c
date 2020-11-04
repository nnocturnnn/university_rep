#include "malloc.h"

static t_block		*search_heap(t_block *blocks, void *ptr, int *i)
{
	t_block		*block;

	block = blocks;
	while (block)
	{
		if ((char*)block + header_size() == (char*)ptr)
			return (block);
		*i += 1;
		block = block->next;
	}
	return (NULL);
}

int					find_used_block(void *ptr, t_block **block)
{
	int		i;

	i = 0;
	if ((*block = search_heap(g_heap[LARGE].in_use, ptr, &i)))
		return (LARGE);
	else if ((*block = search_heap(g_heap[SMALL].in_use, ptr, &i)))
		return (SMALL);
	else if ((*block = search_heap(g_heap[TINY].in_use, ptr, &i)))
		return (TINY);
	return (-1);
}

void				move_block_to_free(int type, t_block *block)
{
	delete_block(&g_heap[type].in_use, block);
	if (!insert_block_addr(&g_heap[type].free, block))
		insert_block_top(&g_heap[type].free, block);
}
