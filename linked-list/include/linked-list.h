#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

typedef struct ListNode
{
    void* data;
    struct ListNode* __next;
} ListNode;

typedef struct List
{
    ListNode* __head;
    ListNode* __tail;
    unsigned __count;


    void (*insert_head)(struct List* self, void* data);
    void (*insert_tail)(struct List* self, void* data);
    void (*print)(struct List* self);
    unsigned (*count)(struct List* self);
} List;

typedef struct ListIterator
{
    ListNode* __current;
    ListNode* (*next)(struct ListIterator* self);
} ListIterator;

List* new_list();
void __list_insert_head(List*, void* data);
void __list_insert_tail(List*, void* data);
void __list_print(List* self);
unsigned __list_count(List* self);

ListIterator* new_list_iterator(List* lst);
ListNode* __list_iterator_next(ListIterator* self);

#endif
