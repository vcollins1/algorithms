#include <stdio.h>
#include "../stack/include/stack.h"
#include <string.h>
#include <stdlib.h>

void infix_to_postfix(char*, char*);
int evaluate_postfix(char*);

int main(int argc, char* argv[])
{
    char* expression = "(2*(3+4)*5)";
    char postfix[strlen(expression + 1)];
    infix_to_postfix(expression, postfix);
    printf("postfix expression: %s\n", postfix);

    int result = evaluate_postfix(postfix);
    printf("%d\n", result);
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

int evaluate_postfix(char* postfix)
{
  // can  only evaluate expressions with single digit numbers
  
  Stack* stack = new_stack();
  const int max_expression = strlen(postfix);
  int expresstion_buffer[max_expression];
  /* expression index */
  int express = 0;

  /* index of current postfix char */
  int i;
  for (i = 0; i < strlen(postfix); ++i) {
    if (postfix[i] >= '0' && postfix[i] <= '9') {
      expresstion_buffer[express] = postfix[i] - '0';
      stack->push(stack, &expresstion_buffer[express]);
      ++express;
    } else {
      int result;
      int op2 = *(int*) stack->pop(stack);
      --express;
      int op1 = *(int*) stack->pop(stack);
      --express;

      switch (postfix[i])
      {
      case '+':
        result = op1 + op2;
        break;
      case '-':
        result = op1 - op2;
        break;
      case '*':
        result = op1 * op2;
        break;
      case '/':
        result = op1 / op2;
        break;    
      default:
        continue;
      }

      expresstion_buffer[express] = result;
      stack->push(stack, &expresstion_buffer[express++]);
    }
  }


  return *(int*) stack->pop(stack);
}
