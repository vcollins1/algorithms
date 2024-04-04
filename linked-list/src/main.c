#include <stdio.h>
#include "../include/linked-list.h"
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[])
{
    srand(time(NULL));
    List* lst = new_list();
    int i, n[10];

    for (i = 0; i < 10; ++i) {
        n[i] = 10 + rand() % 91;
        lst->insert_tail(lst, &n[i]);
    }

    int a = 5;
    lst->insert_head(lst, &a);

    int b = 808;
    lst->insert_tail(lst, &b);

    ListIterator* iter = new_list_iterator(lst);

    ListNode* cur = iter->next(iter);
    while (cur) {
        printf("%d ",*((int *) cur->data));
        cur = iter->next(iter);
    }
    printf("\n");

    return 0;
}
