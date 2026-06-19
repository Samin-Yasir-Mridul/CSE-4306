#include <stdio.h>

#define MAX 5

int stack[MAX];
int top = -1;

void push(int value)
{
    if (top >= MAX - 1)
    {
        printf("Stack Overflow! Cannot push %d\n", value);
    }
    else
    {
        top++;
        stack[top] = value;
        printf("Pushed %d\n", value);
    }
}

int pop()
{
    if (top < 0)
    {
        printf("Stack Underflow! Nothing to pop.\n");
        return -1;
    }
    else
    {
        int value = stack[top];
        top--;
        return value;
    }
}

int peek()
{
    if (top < 0)
    {
        printf("Stack is empty. Cannot peek.\n");
        return -1;
    }
    else
    {
        return stack[top];
    }
}

int isEmpty()
{
    return (top < 0);
}

void printStack()
{
    if (isEmpty())
    {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack (top -> bottom): ");
    for (int i = top; i >= 0; --i)
    {
        printf("%d", stack[i]);
        if (i > 0)
            printf(" -> ");
    }
    printf("\n");
}

int main()
{
    push(10);
    push(20);
    push(30);
    printStack();

    printf("Peek: %d\n", peek());

    printf("Popped: %d\n", pop());
    printStack();

    printf("Is empty: %s\n", isEmpty() ? "Yes" : "No");

    // Empty the stack
    printf("Popped: %d\n", pop());
    printf("Popped: %d\n", pop());

    printStack();
    printf("Is empty: %s\n", isEmpty() ? "Yes" : "No");

    return 0;
}
