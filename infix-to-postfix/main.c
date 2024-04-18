#include <stdio.h>
#include "../stack/include/stack.h"
#include <string.h>

void infix_to_postfix(char*, char*);

int main(int argc, char* argv[])
{
    char* expression = "(a + b / c * (d + c) - f)";
    char postfix[strlen(expression + 1)];
    infix_to_postfix(expression, postfix);

    printf("postfix expression: %s\n", postfix);

    return 0;
}

void infix_to_postfix(char* infix, char* buffer)
{
    int count = 0;
    Stack* stack = new_stack();

    int i;
    for (i = 0; i < strlen(infix); ++i) {
      char* top;
      char current = infix[i];
      switch(current) {
        case ' ':
          continue;
        case '(':
          stack->push(stack, &infix[i]);
          break;
        case '+':
        case '-':
          top = stack->pop(stack);
          while (*top == '+' || *top == '-' || *top == '*' || *top == '/') {
            buffer[count++] = *top;
            top = stack->pop(stack);
          }
          
          stack->push(stack, top);
          stack->push(stack, &infix[i]);
          break;
        case '*':
        case '/':
          top = stack->pop(stack);
          while (*top == '*' || *top == '/') {
            buffer[count++] = *top;
            top = stack->pop(stack);
          }
          
          stack->push(stack, top);
          stack->push(stack, &infix[i]);
          break;
        case ')':
          top = stack->pop(stack);
          while (*top != '(') {
            buffer[count++] = *top;
            top = stack->pop(stack);
          }
          
          break;
        default:
          buffer[count++] = current; 
                    
      }
    }

    buffer[count] = '\0';
}
