#include <stdio.h>
#include "../include/counter.h"


int main(int argc, char* argv[])
{
    Counter* apple = new_counter("apples");
    Counter* banana = new_counter("bananas");

    int count;

    for (count = 0; count < 10; ++count) {
        apple->increment(apple);
    }

    for (count = 0; count < 15; ++count) {
        banana->increment(banana);
    }

    printf("Furit Counts:\n");
    apple->print(apple);
    banana->print(banana);


    apple->clean_up(apple);
    banana->clean_up(banana);
    return 0;
}
