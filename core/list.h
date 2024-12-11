#ifndef __LIST_H
#define __LIST_H

#ifdef __cplusplus
extern "C"{
#endif

struct list{
    struct list* prev;
    struct list* next;
};

void* list_first(const struct list* list);

void* list_last(const struct list* list);

void* list_next(void* lnode);

void* list_prev(void* lnode);
/*
    @description: initial an head_node whose prev and next are assigned this.    
*/
void init_list(struct list* head);

/*
    @head: head_node of ptr.
    @lnode: to be inserted node of ptr
    @description: insert the node into list of front.
    @ret: [0 : success],  [1 : fail].    
*/
int head_insert_list(struct list* head, void* lnode);

/*
    @head: head_node of ptr.
    @lnode: to be inserted node of ptr
    @description: insert the node into list of back.
    @ret: [0 : success],  [1 : fail].    
*/
int tail_insert_list(struct list* head, void* lnode);

/*
    @head: head_node of ptr.
    @index: when [index < 1] or [index > (len+1 of list)] fail.
    @lnode: to be inserted node of ptr
    @description: insert the node into list in the posintion.
    @ret: [0 : success],  [1 : fail].    
*/
int insert_list(struct list* head, int index, void* lnode);

/*
    @val: the val of node.
    @description: create an new list_node.
    @ret: [list* : success],  [NULL : fail].    
*/
//struct list* create_list_node(int val);

/*
    @head: head_node of ptr of ptr.
    @description: pointing the list to be destroyed, this head_ptr is assigned NULL.
    @ret: [0 : success],  [1 : fail].
*/
int destroy_list(struct list** head);

/*
    @head: head_node of ptr.
    @lnode: to be deleted node of ptr
    @description: this head_ptr is pointing the list, whose lnode has deleted.
    @ret: [0 : success],  [1 : fail].
*/
int list_free_node(struct list* head, void* lnode);


/*
    @head: head_node of ptr.
    @lnode: to be finded node of ptr
    @description: find the index of this node in list.
    @ret: [0 : fail],  [index : success].
*/
int find(struct list* head, void* lnode);


#ifdef __cplusplus
}
#endif

#endif