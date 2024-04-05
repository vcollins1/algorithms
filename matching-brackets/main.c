#include <stdio.h>
#include "../stack/include/stack.h"
#include <string.h>

int matching_brackets(char* str)
{
    Stack* s = new_stack();


    int i;
    for (i = 0; i < strlen(str); ++i) {
        char* top;
        switch (str[i]) {
            case '{':
            case '[':
            case '(':
                s->push(s, &str[i]);
                break;
            case '}':
                top = s->pop(s);
                if (*top != '{') return 0;
                break;
            case ']':
                top = s->pop(s);
                if (*top != '[') return 0;
                break;
            case ')':
                top = s->pop(s);
                if (*top != '(') return 0;
                break;
            default:
                continue;
        } 
    }

    return 1;
}

int main(int argc, char* argv[])
{
    char* case1 = "({()[]})";
    printf("%s: ", case1);
    if (matching_brackets(case1)) {
        printf("Brackets Match\n");
    } else {
        printf("Brackets Don't Match\n");
    }

    char* case2 = "({()[)})";
    printf("%s: ", case2);
    if (matching_brackets(case2)) {
        printf("Brackets Match\n");
    } else {
        printf("Brackets Don't Match\n");
    }
    return 0;
}
