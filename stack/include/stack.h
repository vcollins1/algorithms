#ifndef __STACK_H__
#define __STACK_H__

typedef struct StackNode
{
    void* data;
    struct StackNode* __next;
} StackNode;

typedef struct Stack
{
    StackNode* __top;
    unsigned __count;

    void (*push)(struct Stack* self, void* data);
    void* (*pop)(struct Stack* self);
    short (*is_empty)(struct Stack* self);
    unsigned (*size)(struct Stack* self);
    void (*destroy)(struct Stack* self);
} Stack;

Stack* new_stack();
void __stack_push(struct Stack* self, void* data);
void* __stack_pop(struct Stack* self);
short __stack_is_empty(struct Stack* self);
unsigned __stack_size(struct Stack* self);
void __stack_destroy(struct Stack*);

#endif
