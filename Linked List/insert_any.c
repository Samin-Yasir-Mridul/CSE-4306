#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *insertAtPosition(Node *head, int value, int position)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (position == 1)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }

    Node *temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Position out of bounds!\n");
        free(newNode);
        return head;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

void display(Node *head)
{
    Node *temp = head;
    printf("Linked list: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

int main()
{
    Node *head = NULL;

    head = insertAtPosition(head, 10, 1);
    head = insertAtPosition(head, 20, 2);
    head = insertAtPosition(head, 30, 3);
    head = insertAtPosition(head, 25, 3); // Insert at position 3
    head = insertAtPosition(head, 5, 1);   // Insert at position 1

    display(head);
    return 0;
}
