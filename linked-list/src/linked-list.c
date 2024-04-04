#include "../include/linked-list.h"
#include <stdlib.h>
#include <stdio.h>

List* new_list()
{
    List* list = malloc(sizeof(List));
    list->__head = NULL;
    list->__tail = NULL;
    list->__count = 0;

    list->insert_head = &__list_insert_head;
    list->insert_tail = &__list_insert_tail;
    list->count = &__list_count;

    return list;
}

ListNode* __create_list_node(void* data)
{
    ListNode* node = malloc(sizeof(ListNode));
    node->data = data;
    node->__next = NULL;

    return node;
}

void __list_insert_head(List* self, void* data)
{
    ++self->__count;
    ListNode* node = __create_list_node(data);
    if (!self->__head) {
        self->__head = self->__tail = node;
        return;
    }

    node->__next = self->__head;
    self->__head = node;
}

void __list_insert_tail(List* self, void* data)
{
    ++self->__count;
    ListNode* node = __create_list_node(data);
    if (!self->__tail) {
        self->__head = self->__tail = node;
        return;
    }

    self->__tail->__next = node;
    self->__tail = node;
}

unsigned __list_count(List* self)
{
    return self->__count;
}

ListIterator* new_list_iterator(List* lst)
{
    ListIterator* iter = malloc(sizeof(ListIterator));
    iter->__current = lst->__head;
    iter->next = &__list_iterator_next;

    return iter;
}

ListNode* __list_iterator_next(ListIterator* self)
{
    if (self->__current == NULL) return NULL;
    ListNode* cur = self->__current;
    self->__current = self->__current->__next;

    return cur;
}
