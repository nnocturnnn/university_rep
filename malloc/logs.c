#include "malloc.h"

int			mode_log(void)
{
	char	*log;

	if (g_heap[TINY].mode & GETENV_LOG)
	{
		return ((g_heap[TINY].mode & LOG) ? 1 : 0);
	}
	if ((log = getenv(LOG_ENV)) != NULL)
	{
		g_heap[TINY].mode |= GETENV_LOG;
		if (log[0] == '1')
		{
			g_heap[TINY].mode |= LOG;
			return (1);
		}
	}
	else
		g_heap[TINY].mode |= GETENV_LOG;
	return (0);
}

static void	print_log_line(int fd, char *s, t_block *block)
{
	putstr_fd(fd, s);
	putstr_fd(fd, "\t- ");
	putaddr_fd(fd, (unsigned long long)block);
	if (block)
	{
		putstr_fd(fd, " ** ");
		putaddr_fd(fd, (unsigned long long)((char*)block\
			+ header_size()));
		putstr_fd(fd, " - ");
		putaddr_fd(fd, (unsigned long long)((char*)block\
			+ header_size() + block->size));
		putstr_fd(fd, " : ");
		putnbr_fd(fd, block->size);
		putstr_fd(fd, " octets -");
		putstr_fd(fd, " prev : ");
		putaddr_fd(fd, (unsigned long long)block->prev);
		putstr_fd(fd, " next : ");
		putaddr_fd(fd, (unsigned long long)block->next);
	}
	putchar_fd(fd, '\n');
}

void		log(int f, t_block *block)
{
	int	fd;

	fd = open(LOG_FILE, O_RDWR | O_APPEND | O_CREAT,\
		S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd == -1)
		return ;
	if (f == REALLOC)
		putstr_fd(fd, "realloc: ");
	else if (f == CALLOC)
		putstr_fd(fd, "calloc: ");
	else if (f == MALLOC)
		print_log_line(fd, "malloc", block);
	else if (f == FREE)
		print_log_line(fd, "free", block);
	close(fd);
}
