#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char data;
    struct node* left;
    struct node* right;
} node;

void postOrder(node* root)
{
    if(root == NULL)
    {return;}
    postOrder(root->left);
    postOrder(root->right);
    printf("%c, ", root->data);

}

node* createNew(char value)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
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

    postOrder(root);

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