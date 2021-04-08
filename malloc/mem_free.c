#include "malloc.h"

static void		munmap_large(t_block *block)
{
	if ((munmap(block, block->size + header_size())) != 0)
		putstr_fd(2, "munmap error\n");
}

void			free_block(int type, t_block *block)
{
	pthread_mutex_lock(&g_mutex);
	mode_stat() ? stat_free() : 0;
	mode_log() ? log(FREE, block) : 0;
	if (type == TINY || type == SMALL)
	{
		move_block_to_free(type, block);
		defragmentation(type);
	}
	else if (type == LARGE)
	{
		delete_block(&g_heap[LARGE].in_use, block);
		munmap_large(block);
	}
	pthread_mutex_unlock(&g_mutex);
}

void			mem_free(void *ptr)
{
	t_block		*block;
	int			type;

	block = NULL;
	if (!ptr)
		return ;
	pthread_mutex_lock(&g_mutex);
	type = find_used_block(ptr, &block);
	pthread_mutex_unlock(&g_mutex);
	if (type > -1)
		free_block(type, block);
}
