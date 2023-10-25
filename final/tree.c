#include <stdio.h>
#include <stdlib.h>

typedef struct node_
{
    int key;
    int totalSize;
    struct node_ *parent;
    struct node_ *leftChild;
    struct node_ *rightSibling;

} Node;

Node *createdRoot(int key)
{
    Node *root = (Node *)calloc(sizeof(Node), 1);
    root->key = key;
    return root;
}

Node *createdNode(Node *parent, int key)
{
    Node *newNode = (Node *)calloc(sizeof(Node), 1);
    newNode->key = key;
    newNode->parent = parent;
    if (parent->leftChild == NULL)
    {
        parent->leftChild = newNode;
    }
    else
    {
        Node *tmp = parent->leftChild;
        while (tmp->rightSibling != NULL)
        {
            tmp = tmp->rightSibling;
        }
        tmp->rightSibling = newNode;
    }
    return newNode;
}

Node *getParent(Node *node)
{
    return node->parent;
}

Node *getChild(Node *node, int k)
{
    Node *kChild = node->leftChild;
    for (int i = 1; i < k; i++)
    {
        kChild = kChild->rightSibling;
    }
    return kChild;
}

int isExternal(Node *node)
{
    return node->leftChild == NULL ? 1 : 0;
}

int dept(Node *node)
{
    int count = 0;
    while (node->parent != NULL)
    {
        node = node->parent;
        count++;
    }
    return count;
}

void preOrder(Node *tree)
{
    printf("%d", tree->key);
    Node *currentChild = tree->leftChild;
    while (currentChild != NULL)
    {
        preOrder(currentChild);
        currentChild = currentChild->rightSibling;
    }
}

void postOrder(Node *tree)
{
    Node *currentChild = tree->leftChild;
    while (currentChild != NULL)
    {
        postOrder(currentChild);
        currentChild = currentChild->rightSibling;
    }
    printf("%d ", tree->key);
}

void findTotalSize(Node *node)
{
    Node *currentChild = node->leftChild;
    while (currentChild != NULL)
    {
        findTotalSize(currentChild);
        node->totalSize += currentChild->totalSize;
        currentChild = currentChild->rightSibling;
    }
    if (!isExternal(node))
    {
        node->totalSize += node->key;
    }else{
        node->totalSize = node->key;
    }
}
int main()
{
    Node *root = createdRoot(0);
    Node *node1 = createdNode(root, 1);
    Node *node2 = createdNode(root, 2);
    Node *node3 = createdNode(root, 3);
    Node *node4 = createdNode(node1, 4);
    Node *node5 = createdNode(node1, 5);
    Node *node6 = createdNode(node2, 6);
    Node *node7 = createdNode(node2, 7);
    Node *node8 = createdNode(node3, 8);
    Node *node9 = createdNode(node3, 9);
    // preOrder(root);
    // printf("\n");
    // postOrder(root);
    // findTotalSize(root);
    postOrder(root);
}