#include "malloc.h"

static void		fusion_blocks(t_block *block1,\
	t_block *block2)
{
	block1->size += block2->size + header_size();
	block1->next = block2->next;
	if (block2->next)
		block2->next->prev = block1;
}

void			defragmentation(int type)
{
	t_block		*block;

	block = g_heap[type].free;
	while (block)
	{
		if (block->next && (char*)block->next\
			== ((char*)block + header_size() + block->size))
		{
			fusion_blocks(block, block->next);
			mode_stat() ? stat_defrag() : 0;
		}
		else
			block = block->next;
	}
}
