#ifndef __COUNTER_H__
#define __COUNTER_H__

typedef struct Counter
{
    char* __id;
    int __count;

    void (*increment)(struct Counter* self);
    int (*tally)(struct Counter* self);
    void (*print)(struct Counter* self);
    void (*clean_up)(struct Counter* self);
} Counter;


Counter* new_counter(char* id);
void __counter_increment(Counter* self);
int __counter_tally(Counter* self);
void __counter_print(Counter* self);
void __counter_clean_up(Counter* self);

#endif
