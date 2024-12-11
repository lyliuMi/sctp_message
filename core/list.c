#include <stdlib.h>
#include <stdio.h>
#include "list.h"

void* list_first(const struct list* list)
{
    return list->next;
}

void* list_last(const struct list* list)
{
    return list->prev;
}

void* list_next(void* lnode)
{
    struct list* node = (struct list*)lnode;
    return node->next;
}

void* list_prev(void* lnode)
{
    struct list* node = (struct list*)lnode;
    return node->prev;
}

void init_list(struct list* head)
{
    head->prev = head;
    head->next = head;
}   

#if 0
struct list* create_list_node(int val)
{
    struct list* node = (struct list*)malloc(sizeof(struct list));
    if(!node)
    {
        fprintf(stderr, "can't alloc memory from heap\n");
        return NULL;
    }

    node->prev = NULL;
    node->next = NULL;
    return node;
}
#endif

int head_insert_list(struct list* head, void* lnode)
{
    if(!lnode)
    {
        fprintf(stderr, "head_node is null or node is null\n");
        return 1;
    } 
    struct list* node = (struct list*)lnode;

    int ret;
    if((ret = find(head, node)))
    {
        fprintf(stderr, "this node is existed within list of %d\n", ret);
        return 1;
    } 

    struct list* last = head->next;
    while(last->next != head->next)
        last = last->next;

    last->next = node;
    node->prev = last;
    node->next = head->next;
    head->next->prev = node;
    head->next = node;
    
    return 0;
}

int tail_insert_list(struct list* head, void* lnode)
{
    if(!lnode)
    {
        fprintf(stderr, "head_node is null or node is null\n");
        return 1;
    }
    struct list* node = (struct list*)lnode;
    int ret;
    if((ret = find(head, node)))
    {
        fprintf(stderr, "this node is existed within list of %d\n", ret);
        return 1;
    }
    struct list* last = head->next;

    while(last->next != head->next)
    {
        last = last->next;
    }

    last->next = node;
    node->prev = last;
    head->next->prev = node;
    node->next = head->next;

    return 0;
}

int insert_list(struct list* head, int index, void* lnode)
{
    if(!lnode)
    {
        fprintf(stderr, "head_node is null or node is null\n");
        return 1;
    }
    struct list* node = (struct list*)lnode;
    int ret;
    if((ret = find(head, node)))
    {
        fprintf(stderr, "this node is existed within list of %d\n", ret);
        return 1;
    }
    if(index < 1)
    {
        fprintf(stderr, "index is not < 1\n");
        return 1;
    }
    else if(index == 1)
    {
        return head_insert_list(head, node);
    }

    struct list* p = head->next;
    int i = 1;
    while((i++ != index-1) && p->next != head->next)
    {
        p = p->next;
    }
    if(i < index)
    {
        fprintf(stderr, "the position is illegal\n");
        return 1;
    }
    else if(i == index)
    {
        node->next = p->next;
        p->next->prev = node;
        node->prev = p;
        p->next = node;
    }
    
    return 0;
}

int find(struct list* head, void* lnode)
{
    if(!lnode) return 0;
    struct list* node = (struct list*)lnode;

    int index = 1;
    struct list* first = head->next;
    struct list* p = head->next;
    while(p)
    {
        if(p == node)
            return index;
        index++;
        p = p->next;
        if(p == first)
            break;
    }
    return 0;
}

int destroy_list(struct list** head)
{
    struct list* first = (*head)->next;
    first->prev->next = NULL;
    struct list* p = first;
    struct list* n = NULL;
    while(p)
    {
        n = p->next;
        free(p);
        p = n;
    }
    *head = NULL;
    return 0;
}

int list_free_node(struct list* head, void* lnode)
{
    if(!lnode) 
        return -1;
    struct list* node = (struct list*)lnode;
    
    // when delete head_node
    if(head->next == node && node->next == node)
    {
        head->next = NULL;
        head->prev = NULL;
        return 0;
    }
    else if(head->next == node && node->next != node)
    {
        head->next = node->next;
        node->next->prev = node->prev;
        node->prev->next = node->next;
        return 0;
    }

    struct list* prev = node->prev;
    struct list* next = node->next;
    // others
    if (prev)
        prev->next = next;
    else
        head->next = next;

    if (next)
        next->prev = prev;
    else
        head->prev = prev;

    return 0;
}