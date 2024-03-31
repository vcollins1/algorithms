#include <stdio.h>
#include "../include/gcd.h"

int main(int argc, char* argv[])
{
    int x, y;
    while (fscanf(stdin, "%d %d ", &x, &y) != EOF) {
        printf("gcd(%d, %d): %d\n", x, y, gcd(x, y));
    }
    return 0;
}


