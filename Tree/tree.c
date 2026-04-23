#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    char data;
    struct node *left;
    struct node *right;
}Node;

Node* createNode(char data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void preOrder(Node* root)
{
    if (root == NULL) return;

    printf("%c " , root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node* root)
{
    if (root == NULL) return;

    inOrder(root->left);
    printf("%c ", root->data);
    inOrder(root->right);
}

void postOrder(Node* root)
{
    if (root == NULL) return;

    postOrder(root->left);
    postOrder(root->right);
    printf("%c ", root->data);
}

int main()
{
    Node* root = createNode('R');
    Node* nodeA = createNode('A');
    Node* nodeB = createNode('B');
    Node* nodeC = createNode('C');
    Node* nodeD = createNode('D');
    Node* nodeE = createNode('E');
    Node* nodeF = createNode('F');
    Node* nodeG = createNode('G');

    root->left = nodeA;
    root->right = nodeB;

    nodeA->left = nodeC;
    nodeA->right = nodeD;

    nodeB->left = nodeE;

    nodeE->left = nodeF;
    nodeE->right = nodeG;

    printf("Pre-order traversal : ");
    preOrder(root);

    printf("\nIn-order traversal  : ");
    inOrder(root);

    printf("\nPost-order traversal: ");
    postOrder(root);

    free(nodeG);
    free(nodeF);
    free(nodeE);
    free(nodeB);
    free(nodeC);
    free(nodeD);
    free(nodeA);
    free(root);
}