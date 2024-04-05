#include "../include/stack.h"
#include <stdlib.h>


Stack* new_stack()
{
    Stack* s = malloc(sizeof(Stack));
    s->__count = 0;
    s->__top = NULL;

    s->push = &__stack_push;
    s->pop = &__stack_pop;
    s->is_empty = &__stack_is_empty;
    s->size = &__stack_size;
    s->destroy = &__stack_destroy;
    return s;
}

StackNode* create_stack_node(void* data)
{
    StackNode* item = malloc(sizeof(StackNode));
    item->data = data;
    item->__next = NULL;
    return item;
}

void __stack_push(Stack* self, void* data)
{
    ++self->__count;
    StackNode* item = create_stack_node(data);
    
    if (!self->__top) {
        self->__top = item;
        return;
    }

    item->__next = self->__top;
    self->__top = item;
}

void* __stack_pop(Stack* self)
{
    --self->__count;
    StackNode* item = self->__top;
    void* value = item->data;
    self->__top = self->__top->__next;
    free(item);
    return value;
}

short __stack_is_empty(Stack* self)
{
    return self->__count == 0;
}

unsigned __stack_size(Stack* self)
{
    return self->__count;
}

void __stack_destroy(Stack* self)
{
    while (!self->is_empty(self)) {
        self->pop(self);
    }

    free(self);
}
