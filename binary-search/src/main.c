#include <stdio.h>
#include <stdlib.h>
#include "../include/binary_search.h"

int ase(const void * a, const void * b);

int main(int argc, char* argv[])
{
    int whitelist[500], sz = 0, x;
    FILE* fptr = fopen(argv[1], "r");

    while (fscanf(fptr, "%d ", &x) != EOF) {
        whitelist[sz++] = x;
    }

    qsort(whitelist, sz, sizeof(int), ase);
    
    while (scanf("%d ", &x) != EOF) {
        if (binary_search(x, whitelist, sz)) {
            printf("%d\n", x);
        }
    }

    return 0;
}

int ase(const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}
