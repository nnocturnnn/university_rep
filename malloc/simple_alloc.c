#include "stdlib.h"
#include "stdio.h"
#include "unistd.h"

void    bzero(void  *s, size_t n)
{
    unsigned char *ptr;
    
    ptr = (unsigned char *) s;
    while (n > 0)
    {
        *ptr = '\0';
        ptr++;
        n--;
    }
}

void    *mem_alloc(size_t size)
{
    void    *mem;

    mem = malloc(sizeof(mem) * size);
    if (mem == NULL)
        return (NULL);
    bzero(mem, size);
    return (mem);
}

void    mem_free(void **ap) {
    if (ap != NULL)
    {
        free(*ap);
        *ap = NULL;
    }
}

void *mem_realloc(void *ptr, size_t size) {
	void *p;
	if (ptr == NULL) {
        return p = mem_alloc(size);
    }
    else {
		p = mem_alloc(size);
		if (p == NULL) return NULL;
		memcpy(p, ptr, size);
		mem_free(ptr);
	}
	return p;
}

void *mem_dump(void *ptr) {
    if (ptr != NULL) {
        printf("MEMORY CONTENTS:\n");
        printf("SIZE : %lu ADDR : %p CONTENT : %s\n",sizeof(ptr),ptr,&ptr);
    }
}

int main() {
    void *p = mem_alloc(15);
    mem_dump(p);
    mem_free(&p);
    mem_dump(p);
    p = realloc(p, 15);
    mem_dump(p);
}