#include "malloc.h"

int		mode_stat(void)
{
	char	*stat;

	if (g_heap[TINY].mode & GETENV_STAT)
	{
		return ((g_heap[TINY].mode & STAT) ? 1 : 0);
	}
	if ((stat = getenv(STAT_ENV)) != NULL)
	{
		g_heap[TINY].mode |= GETENV_STAT;
		if (stat[0] == '1')
		{
			g_heap[TINY].mode |= STAT;
			return (1);
		}
	}
	else
		g_heap[TINY].mode |= GETENV_STAT;
	return (0);
}

void	stat_malloc(int i)
{
	int	fd;

	fd = open(STAT_FILE, O_RDWR | O_APPEND | O_CREAT,\
		S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd == -1)
		return ;
	putstr_fd(fd, "malloc ");
	putnbr_fd(fd, i);
	putstr_fd(fd, "eol\n");
	close(fd);
}

void	stat_free(void)
{
	int	fd;

	fd = open(STAT_FILE, O_RDWR | O_APPEND | O_CREAT,\
		S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd == -1)
		return ;
	putstr_fd(fd, "free\n");
	close(fd);
}

void	stat_defrag(void)
{
	int	fd;

	fd = open(STAT_FILE, O_RDWR | O_APPEND | O_CREAT,\
		S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd == -1)
		return ;
	putstr_fd(fd, "defrag\n");
	close(fd);
}
