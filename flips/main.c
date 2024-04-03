#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../counter/include/counter.h"

int main(int argc, char* argv[])
{   
    srand(time(NULL));
    int n = atoi(argv[1]);
    Counter* heads = new_counter("heads");
    Counter* tails = new_counter("tails");
    int i;
    for (i = 0; i < n; ++i) {
        if (rand() % 2)
            heads->increment(heads);
        else
            tails->increment(tails);
    }

    heads->print(heads);
    tails->print(tails);

    int diff = abs(heads->tally(heads) - tails->tally(tails));
    printf("delta: %d\n", diff);
    return 0;
}
