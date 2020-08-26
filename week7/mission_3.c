// infix to postfix
#include <stdio.h>
#include <string.h> 
#include <stdlib.h> 

// Stack definition
typedef struct stack
{
    int top;
    int capacity;
    int* array;
} Stack;

Stack* create_stack(int capacity)
{
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if(!stack) // if malloc is failed
        return NULL;
    stack -> capacity = capacity;
    stack -> top = -1;
    stack -> array = (int*)malloc(stack->capacity*sizeof(int));
    return stack;
}

int is_empty(Stack* stack)
{
    return stack->top == -1;
}

void push(Stack* stack, char operand)
{
    stack->array[++(stack->top)] = operand;
}

char pop(Stack* stack)
{
    if(!is_empty(stack))
        return stack->array[stack->top--];
    else
        return '#';
}

char peek(Stack* stack)
{
    return stack->array[stack->top];
}

int is_operand(char character) // check the character is an operand
{
    return ('a' <= character && character <= 'z') || ('A' <= character && character <= 'Z');
}

int priority(char character) // check the given operater's prioirty
{
    switch(character)
    {
        case '+':
        case '-':
            return 1; // lower priority

        case '*':
        case '/':
            return 2;

        case '^':
            return 3; // highest priority
    }
    return -1; // lowest priority == an operand
}

void print_all(char* infix_expression, Stack* stack, char* postfix_expression, int i, int k)
{
    printf("Current Token: %c \t\t Stack: ", infix_expression[i]);
    for(int i=0; i<=stack->top; i++)
    {
        printf("%c", stack->array[i]);
    }
    printf("\t\t Output: ");
    for(int i=0; i<=k; i++)
    {
        printf("%c", postfix_expression[i]);
    }
}

int infix_to_postfix(char* infix_expression)
{
    Stack* stack = create_stack(strlen(infix_expression));
    if(!stack) // if malloc is failed
        return -1;
    
    // create empty result expression
    char* postfix_expression = (char*)malloc(sizeof(char)*strlen(infix_expression));

    int i; // i for infix expression index
    int k; // k for postfix expression index
    for(i = 0, k = -1; infix_expression[i]; i++)
    {
        if(is_operand(infix_expression[i])) // go to postfix immediately
        {
            postfix_expression[++k] = infix_expression[i];
            print_all(infix_expression, stack, postfix_expression, i, k); printf(" << Token goes to Output immediately\n");
        }
        else if(infix_expression[i] == '(')
        {
            push(stack, infix_expression[i]);
            print_all(infix_expression, stack, postfix_expression, i, k); printf(" << Token Pushed to the Stack\n");
        }
        else if(infix_expression[i] == ')')
        {   // repeat until the stack is empty or peek encounters '('
            while(!is_empty(stack) && peek(stack) != '(')
            {
                postfix_expression[++k] = pop(stack);
                print_all(infix_expression, stack, postfix_expression, i, k); printf(" << Popped and Fixed\n");
            }

            // if expression has syntax error
            if(!is_empty(stack) && peek(stack) != '(')
                return -1;
            else
            {
                pop(stack);
                print_all(infix_expression, stack, postfix_expression, i, k); printf(" << '(' Popped\n"); // remove '(' in the stack
            }
        }
        else // when it's an operator
        {
            while(!is_empty(stack) && priority(infix_expression[i]) <= priority(peek(stack)))
            {
                postfix_expression[++k] = pop(stack);
                print_all(infix_expression, stack, postfix_expression, i, k); printf(" << Popped and Fixed\n");
            }
            push(stack, infix_expression[i]);
            print_all(infix_expression, stack, postfix_expression, i, k); printf(" << Token Pushed to the Stack\n");
        }

    }

    // pop all the operators from the stack
    while(!is_empty(stack))
    {
        postfix_expression[++k] = pop(stack);
        print_all(infix_expression, stack, postfix_expression, i, k); printf(" << Popped and Fixed\n");
    }
    postfix_expression[++k] = '\0'; // input null-terminated string
    printf("\nnow POST-FIX expression is ... %s\n", postfix_expression);

    return 0;
}

int main(void)
{
    // input
    char infix_expression[100] = "a+b*(c^d-e)^(f+g*h)-i";
    printf("IN-FIX expression was ... %s\n\n", infix_expression);

    // output
    infix_to_postfix(infix_expression);
    return 0;
}

// Reference: https://www.geeksforgeeks.org/stack-set-2-infix-to-postfix/