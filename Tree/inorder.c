#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char data;
    struct node* left;
    struct node* right;
} node;

node* createNew(char value)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
}

void inOrder(node* root)
{
    if(root == NULL)
    {return;}
    inOrder(root->left);
    printf("%c, ", root->data);
    inOrder(root->right);
}

int main()
{
    node* root = createNew('R');
    node* nodeA = createNew('A');
    node* nodeB = createNew('B');
    node* nodeC = createNew('C');
    node* nodeD = createNew('D');
    node* nodeE = createNew('E');
    node* nodeF = createNew('F');
    node* nodeG = createNew('G');

    root->left = nodeA;
    root->right = nodeB;

    nodeA->left = nodeC;
    nodeA->right = nodeD;

    nodeB->left = nodeE;

    nodeE->left = nodeF;
    nodeE->right = nodeG;

    inOrder(root);

    free(nodeG);
    free(nodeF);
    free(nodeE);
    free(nodeB);
    free(nodeC);
    free(nodeD);
    free(nodeA);
    free(root);

    return 0;
}