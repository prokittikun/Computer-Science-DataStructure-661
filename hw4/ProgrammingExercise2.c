#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char name[100];           // for file or folder name
    int size;                 // for file or folder size in kb
    int type;                 // e.g. type=0 for file, or type=1 for folder
    int total_size;           // for the total size of the directory
    struct node *parent;      // for link to the node’s parent
    struct node *firstChild;  // for link to the node’s first child
    struct node *nextSibling; // for link to the node’s next sibling
} Node;

Node *createNode(char *name, int size, int type, Node *parent)
{
    Node *node = (Node *)malloc(sizeof(Node));
    strcpy(node->name, name);
    node->size = size;
    node->type = type;
    node->parent = parent;
    node->firstChild = NULL;
    node->nextSibling = NULL;
    if (node->parent != NULL)
    {
        if (node->parent->firstChild != NULL)
        {
            Node *child = node->parent->firstChild;
            while (child->nextSibling != NULL)
            {
                child = child->nextSibling;
            }
            child->nextSibling = node;
        }
        else
        {
            node->parent->firstChild = node;
        }
    }
    return node;
}

void postorderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorderTraversal(root->firstChild);
    postorderTraversal(root->nextSibling);

    root->total_size = root->size;

    Node *child = root->firstChild;
    while (child != NULL)
    {
        root->total_size += child->total_size;
        child = child->nextSibling;
    }
}

void preorderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("Name: %s, total size: %d\n", root->name, root->total_size);
    preorderTraversal(root->firstChild);
    preorderTraversal(root->nextSibling);
}

int main()
{
    Node *tree = createNode("/user/rt/courses", 1000, 1, NULL);
    Node *node1 = createNode("cs016/", 2000, 1, tree);
    Node *node2 = createNode("cs252/", 1000, 1, tree);
    Node *node3 = createNode("grades", 8000, 0, node1);
    Node *node4 = createNode("homeworks/", 1000, 1, node1);
    Node *node5 = createNode("programs/", 1000, 1, node1);
    Node *node6 = createNode("hw1", 3000, 0, node4);
    Node *node7 = createNode("hw2", 2000, 0, node4);
    Node *node8 = createNode("hw3", 4000, 0, node4);
    Node *node9 = createNode("pr1", 57000, 0, node5);
    Node *node10 = createNode("pr2", 97000, 0, node5);
    Node *node11 = createNode("pr3", 74000, 0, node5);
    Node *node12 = createNode("projects/", 1000, 1, node2);
    Node *node13 = createNode("grades", 3000, 0, node2);
    Node *node14 = createNode("papers/", 1000, 1, node12);
    Node *node15 = createNode("demos/", 1000, 1, node12);
    Node *node16 = createNode("buylow", 26000, 0, node14);
    Node *node17 = createNode("sellhigh", 55000, 0, node14);
    Node *node18 = createNode("market", 4786000, 0, node15);
    postorderTraversal(tree);
    preorderTraversal(tree);
}