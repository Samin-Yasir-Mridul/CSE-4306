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

int main()
{
    push(10);
    push(20);
    printf("Popped: %d\n", pop());
    return 0;
}