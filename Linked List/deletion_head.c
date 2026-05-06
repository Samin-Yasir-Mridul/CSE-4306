#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

Node *insertAtHead(Node *head, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;

    return head;
}

Node* deleteAtHead(Node* head)
{
    if(head == NULL)
    {
        printf("List is empty!\n");
        return NULL;
    }
    Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

void display(Node* head)
{
    Node* temp = head;
    printf("Linked list: ");
    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

int main()
{
    Node* head = NULL;

    head = insertAtHead(head, 10);
    head = insertAtHead(head, 20);
    head = insertAtHead(head, 30);
    head = insertAtHead(head, 40);
    head = insertAtHead(head, 50);

    printf("Before deletion:\n");
    display(head);

    head = deleteAtHead(head);

    printf("\nAfter deletion:\n");
    display(head);

    return 0;
}