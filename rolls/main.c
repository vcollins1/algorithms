#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../counter/include/counter.h"

const int SIZE = 6;

int main(int argc, char* argv[])
{
    srand(time(NULL));
    int n = atoi(argv[1]);
    Counter* rolls[SIZE + 1];

    int i, index;
    for (i = 1; i < SIZE + 1; ++i) {
        char id[10];
        snprintf(id, 10, "%d's", i);
        rolls[i] = new_counter(id);
    }

    for (i = 0; i < n; ++i) {
        index = 1 + rand() % SIZE;
        rolls[index]->increment(rolls[index]);
    }

    for (i = 1; i < SIZE + 1; ++i) {
        rolls[i]->print(rolls[i]);
    }
    return 0;
}
