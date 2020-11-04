#ifndef MALLOC_H
# define MALLOC_H

# include <unistd.h>
# include <sys/mman.h>
# include <sys/resource.h>
# include <pthread.h>
# include <fcntl.h>
# include <stdlib.h>

# define NB_BLOCKS		100
# define TINY_BLOCK		256
# define SMALL_BLOCK	4096

# define GETENV_STAT	0b1
# define GETENV_LOG		0b10
# define STAT			0b100
# define LOG			0b1000

# define STAT_FILE		"data"
# define LOG_FILE		"logs"

# define STAT_ENV		"MALLOC_STAT"
# define LOG_ENV		"MALLOC_LOG"

typedef struct			s_block
{
	size_t				size;
	struct s_block		*prev;
	struct s_block		*next;
}						t_block;

typedef struct			s_heap
{
	t_block				*in_use;
	t_block				*free;
	int					mode;
}						t_heap;

t_heap					g_heap[2];
extern pthread_mutex_t	g_mutex;

enum					e_heap
{
	TINY,
	SMALL,
	LARGE
};

enum					e_lib
{
	MALLOC,
	FREE,
	REALLOC,
	CALLOC
};

void					*mem_alloc(size_t size);
void					mem_free(void *ptr);
void					*mem_realloc(void *ptr, size_t size);






void					*calloc(size_t count, size_t size);
void					show_alloc_mem(void);
void					show_alloc_mem_hex(void);
t_block					*choose_free_block(int type, size_t size);
t_block					*add_free_block(t_block *last, int type,\
							size_t size);
t_block					*extend_free_pool(void *last, int type, size_t size);
t_block					*request_memory(void *last, size_t size);
void					move_block_to_use(int type, t_block *block);
int						find_used_block(void *ptr, t_block **block);
void					move_block_to_free(int type, t_block *block);
void					free_block(int type, t_block *block);
void					defragmentation(int type);
t_block					*split_block(t_block *block, int type, size_t size);
void					delete_block(t_block **start, t_block *block);
void					insert_block_top(t_block **start, t_block *block);
void					insert_block_top_defrag(t_block **start,\
							t_block *block);
int						insert_block_addr(t_block **start,\
							t_block *new_block);
size_t					align_size(size_t size, size_t multiple);
size_t					header_size(void);
void					bzero(void *s, size_t n);
void					*memset(void *b, int c, size_t len);
int						mode_stat(void);
void					stat_malloc(int i);
void					stat_free(void);
void					stat_defrag(void);
int						mode_log(void);
void					log(int f, t_block *block);
void					print_memory(const void *addr, size_t size);
void					putnbr(int n);
void					putnbr_fd(int fd, int n);
void					putnbr_str(char *str, int n);
void					putchar(char c);
void					putchar_fd(int fd, char c);
void					putstr(char const *s);
void					putstr_fd(int fd, char const *s);
void					putaddr(unsigned long long p);
void					putaddr_fd(int fd, unsigned long long p);
void					putaddr_endl(unsigned long long p);

#endif
