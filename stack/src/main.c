#include "../include/stack.h"
#include <stdio.h>
#include <string.h>

void str_to_arr(char* s, char s_arr[50][10], int* count)
{
    char c[10];

    int i = 0, j = 0, k = 0;
    *count = 0;
    while (s[i] != '\0') {
        if (s[i] == ' ') {
            c[j] = '\0';
            j = 0;
            strcpy(s_arr[k], c);
            ++k;
            ++i;
            ++(*count);
            continue;
        }
        c[j++] = s[i++];
    }
    ++(*count);

    c[j] = '\0';
    strcpy(s_arr[k], c);
}

int main(int argc, char* argv[])
{
    Stack* stack = new_stack();
    char* str = "to be or not to - be - - that - - - is";

    char s_arr[50][10];
    int count = 0;
    str_to_arr(str, s_arr, &count);
    int i;
    for (i = 0; i < count; ++i) {
        if (strcmp(s_arr[i], "-") != 0) {
            stack->push(stack, (char**) s_arr[i]);
        } else if (!stack->is_empty(stack)) {
            char* value = stack->pop(stack);
            printf("%s ", value);
        }
    }

    printf("(%d left on stack)\n", stack->size(stack));

    stack->destroy(stack);
    return 0;
}
