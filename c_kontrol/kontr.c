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
  
    /* Checking for empty list */
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
    struct node* list = NULL;
    struct node* list2 = NULL;
    if (fp == NULL && fp2 == NULL)
        exit(EXIT_FAILURE);
    char* line = NULL;
    size_t len = 0;
    while ((getdelim(&line, &len, ' ' , fp)) != -1) {
        insert(&list,atoi(line));
    }
    while ((getdelim(&line, &len, ' ' , fp2)) != -1) {
        insert(&list2,atoi(line));
    }
    fclose(fp);
    fclose(fp2);
    printf("list 1: ");
    print_list(list);
    printf("\n");
    printf("list 2: ");
    print_list(list2);
    struct node* list3 = concatenate(list,list2);
    bubbleSort(list3);
    printf("\nlist 3: ");
    print_list(list3);
}