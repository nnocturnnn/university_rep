#include "malloc.h"

static int		get_min_size(int type)
{
	return (type == TINY ? TINY_BLOCK : SMALL_BLOCK);
}

t_block			*split_block(t_block *block, int type, size_t size)
{
	t_block		*new_block;
	int			min_size;

	min_size = get_min_size(type);
	if ((block->size - size) >= (min_size + header_size()))
	{
		new_block = (t_block*)((char*)block + header_size() + size);
		new_block->size = block->size - size - header_size();
		new_block->prev = block;
		new_block->next = block->next;
		block->size = size;
		if (block->next)
			block->next->prev = new_block;
		block->next = new_block;
		return (new_block);
	}
	return (block->next);
}

void			delete_block(t_block **start, t_block *block)
{
	if (block->next)
		block->next->prev = block->prev;
	if (block->prev)
		block->prev->next = block->next;
	if (*start == block)
		*start = block->next;
}

void			insert_block_top(t_block **start, t_block *block)
{
	if (!*start)
	{
		*start = block;
		block->next = NULL;
		block->prev = NULL;
	}
	else
	{
		block->next = *start;
		block->prev = NULL;
		(*start)->prev = block;
		*start = block;
	}
}

int				insert_block_addr(t_block **start, t_block *new_block)
{
	t_block		*block;

	if (!*start)
	{
		insert_block_top(start, new_block);
		return (1);
	}
	block = *start;
	while (block)
	{
		if ((char*)new_block == ((char*)block + header_size()\
			+ block->size))
		{
			new_block->next = block->next;
			new_block->prev = block;
			if (block->next)
				block->next->prev = new_block;
			block->next = new_block;
			return (1);
		}
		block = block->next;
	}
	return (0);
}
