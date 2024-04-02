#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/counter.h"

void __counter_increment(Counter* self)
{
    ++self->__count;
}

int __counter_tally(Counter* self)
{
    return self->__count;
}

void __counter_print(Counter* self)
{
    printf("%d %s\n", self->__count, self->__id);
}

void __counter_clean_up(Counter* self)
{
    free(self->__id);
    free(self);
}

Counter* new_counter(char* id)
{
    Counter* c = malloc(sizeof(Counter));
    c->__count = 0;
    c->__id = strdup(id);

    c->increment = &__counter_increment;
    c->tally = &__counter_tally;
    c->print = &__counter_print;
    c->clean_up = &__counter_clean_up;

    return c;
}
