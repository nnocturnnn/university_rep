#include "malloc.h"

static void		show_block_hex(t_block *block)
{
	putaddr((unsigned long long)((char*)block + header_size()));
	putstr(" - ");
	putaddr((unsigned long long)((char*)block + header_size()\
		+ block->size));
	putstr(" : ");
	putnbr(block->size);
	putstr(" octets");
	putchar('\n');
	print_memory((void*)block, block->size);
}

static void		show_heap_hex(t_block *blocks)
{
	t_block		*block;
	t_block		*last;

	last = NULL;
	block = blocks;
	while (block)
	{
		last = block;
		block = block->next;
	}
	block = last;
	while (block)
	{
		show_block_hex(block);
		block = block->prev;
	}
}

void			show_alloc_mem_hex(void)
{
	pthread_mutex_lock(&g_mutex);
	putstr("TINY : ");
	putaddr_endl((unsigned long long)g_heap[TINY].in_use);
	show_heap_hex(g_heap[TINY].in_use);
	putstr("SMALL : ");
	putaddr_endl((unsigned long long)g_heap[SMALL].in_use);
	show_heap_hex(g_heap[SMALL].in_use);
	putstr("LARGE : ");
	putaddr_endl((unsigned long long)g_heap[LARGE].in_use);
	show_heap_hex(g_heap[LARGE].in_use);
	pthread_mutex_unlock(&g_mutex);
}
