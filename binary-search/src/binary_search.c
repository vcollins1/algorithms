#include "../include/binary_search.h"

int binary_search(int key, int* a, int sz)
{
    int low = 0, high = sz - 1, mid;
    
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (key < a[mid]) {
            high = mid - 1;
        } else if (key > a[mid]) {
            low = mid + 1;
        } else {
            return 1;
        }
    }

    return 0;
}
