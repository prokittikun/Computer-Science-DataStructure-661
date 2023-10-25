#include <stdio.h>
#include <stdlib.h>

typedef struct node_
{
    int key;
    struct node_ *parent;
    struct node_ *leftChild;
    struct node_ *sibling;
} Node;

Node *createRoot(int key)
{
    Node *newNode = (Node *)calloc(sizeof(Node), 1);
    newNode->key = key;
    return newNode;
}

int isRoot(Node *node)
{
    return node->parent == NULL ? 1 : 0;
}

int isExternal(Node *node)
{
    return node->leftChild == NULL ? 1 : 0;
}

int depth(Node *node)
{
    int dept = 0;
    while (node->parent != NULL)
    {
        node = node->parent;
        dept++;
    }
    return dept;
}

Node *createNode(Node *parent, int key)
{
    Node *newNode = (Node *)calloc(sizeof(Node), 1);
    newNode->key = key;
    newNode->parent = parent;
    return newNode;
}

Node *addNode(Node *parent, int key)
{
    Node *leftChild = parent->leftChild;
    Node *node = createNode(parent, key);
    if (leftChild == NULL)
    {
        parent->leftChild = node;
    }
    else
    {
        while (leftChild->sibling != NULL)
        {
            leftChild = leftChild->sibling;
        }
        leftChild->sibling = node;
    }
    return node;
}

void preOrder(Node *root)
{
    printf("%d", root->key);
    Node *leftChild = root->leftChild;
    while (leftChild != NULL)
    {
        preOrder(leftChild);
        leftChild = leftChild->sibling;
    }
}

void postOrder(Node *root)
{
    Node *leftChild = root->leftChild;
    while (leftChild != NULL)
    {
        postOrder(leftChild);
        leftChild = leftChild->sibling;
    }
    printf("%d", root->key);
}

int main()
{
    Node *root = createRoot(0);
    Node *node1 = addNode(root, 1);
    Node *node2 = addNode(root, 2);
    Node *node3 = addNode(root, 3);
    Node *node4 = addNode(node1, 4);
    Node *node5 = addNode(node1, 5);
    Node *node6 = addNode(node2, 6);
    Node *node7 = addNode(node2, 7);
    Node *node8 = addNode(node3, 8);
    Node *node9 = addNode(node3, 9);
    // preOrder(root);
    postOrder(root);
}