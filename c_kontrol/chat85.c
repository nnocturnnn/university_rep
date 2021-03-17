#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

struct node {
    int data;
    struct node* next;
};
 
void insert(struct node** head, int key);
void print_list(struct node* head);

struct node *concatenate(struct node *head1,struct node *head2)
{
    struct node *p;
    if (head1==NULL)                            //if the first linked
                    return (head2);
    if (head2==NULL)                            //if second linked
                    return (head1);
    p=head1;                             //place p on the first
    while (p->next!=NULL)                 //move p to the last node
                    p=p->next;
    p->next=head2;                           //address
    return (head1);
}

void insert(struct node** head, int key)
{
    struct node** current = head;
 
    while (*current != NULL)
    {
        current = &((*current)->next);
    }
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data = key;
    new->next = *current;
    *current = new;
}       
 
void print_list(struct node* head)
{
    while (head != NULL)
    {
        printf("%d ",head->data);
        head = head->next;
    }
    return;
}

static char** _strsplit( const char* s, const char* delim, size_t* nb ) {
	void* data;
	char* _s = ( char* )s;
	const char** ptrs;
	size_t
		ptrsSize,
		nbWords = 1,
		sLen = strlen( s ),
		delimLen = strlen( delim );

	while ( ( _s = strstr( _s, delim ) ) ) {
		_s += delimLen;
		++nbWords;
	}
	ptrsSize = ( nbWords + 1 ) * sizeof( char* );
	ptrs =
	data = malloc( ptrsSize + sLen + 1 );
	if ( data ) {
		*ptrs =
		_s = strcpy( ( ( char* )data ) + ptrsSize, s );
		if ( nbWords > 1 ) {
			while ( ( _s = strstr( _s, delim ) ) ) {
				*_s = '\0';
				_s += delimLen;
				*++ptrs = _s;
			}
		}
		*++ptrs = NULL;
	}
	if ( nb ) {
		*nb = data ? nbWords : 0;
	}
	return data;
}

char** strsplit( const char* s, const char* delim ) {
	return _strsplit( s, delim, NULL );
}

char** strsplit_count( const char* s, const char* delim, size_t* nb ) {
	return _strsplit( s, delim, nb );
}

void swap(struct node *a, struct node *b) 
{ 
    int temp = a->data; 
    a->data = b->data; 
    b->data = temp; 
} 

void bubbleSort(struct node *start) 
{ 
    int swapped, i; 
    struct node *ptr1; 
    struct node *lptr = NULL; 
    if (start == NULL) 
        return; 
    do
    { 
        swapped = 0; 
        ptr1 = start; 
  
        while (ptr1->next != lptr) 
        { 
            if (ptr1->data < ptr1->next->data) 
            {  
                swap(ptr1, ptr1->next); 
                swapped = 1; 
            } 
            ptr1 = ptr1->next; 
        } 
        lptr = ptr1; 
    } 
    while (swapped); 
} 


int main() {
    FILE* fp = fopen("1.txt", "r");
    FILE* fp2 = fopen("2.txt", "r");
    if (fp == NULL && fp2 == NULL)
        exit(EXIT_FAILURE);
    char* line = NULL;
    char* line2 = NULL;
    size_t len = 0;
    getline(&line, &len, fp);
    getline(&line2, &len, fp2);
    fclose(fp);
    fclose(fp2);
    char **arr_line = strsplit(line," ");
    char **arr_line2 = strsplit(line2," ");
    struct node* list = NULL;
    struct node* list2 = NULL;
    for(int i = 0; arr_line[i] != NULL; i++) {
        insert(&list,atoi(arr_line[i]));
        insert(&list2,atoi(arr_line2[i]));
    }
    printf("First list : ");
    print_list(list);
    printf("\n");
    printf("Second list : ");
    print_list(list2);
    printf("\nConcat list : ");
    struct node* list3 = concatenate(list,list2);
    print_list(list3);
    bubbleSort(list3);
    printf("\nSorted Concat list : ");
    print_list(list3);
}