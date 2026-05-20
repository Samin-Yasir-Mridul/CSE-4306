#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char data;
    struct node *left;
    struct node *right;
} Node;

Node *createNode(char data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void preOrder(Node* root)
{
    if(root == NULL)
    {return;}
    printf("%c, ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

int main()
{
    Node *root = createNode('R');
    Node *nodeA = createNode('A');
    Node *nodeB = createNode('B');
    Node *nodeC = createNode('C');
    Node *nodeD = createNode('D');
    Node *nodeE = createNode('E');
    Node *nodeF = createNode('F');
    Node *nodeG = createNode('G');

    root->left = nodeA;
    root->right = nodeB;

    nodeA->left = nodeC;
    nodeA->right = nodeD;

    nodeB->left = nodeE;

    nodeE->left = nodeF;
    nodeE->right = nodeG;

    preOrder(root);

    free(nodeG);
    free(nodeF);
    free(nodeE);
    free(nodeB);
    free(nodeC);
    free(nodeD);
    free(nodeA);
    free(root);
}