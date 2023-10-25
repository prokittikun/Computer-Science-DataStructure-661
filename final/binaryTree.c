#include <stdio.h>
#include <stdlib.h>

typedef struct Node_
{
    int key;
    struct Node_ *parent;
    struct Node_ *left;
    struct Node_ *right;
} Node;

// Node * createRoot(int key){
//     Node *root = (Node *)calloc(sizeof(Node),1);
//     root->key = key;
//     return root;
// }

Node *createNode(int key)
{
    Node *newNode = (Node *)calloc(sizeof(Node), 1);
    newNode->key = key;
    return newNode;
}

Node *createLeft(int key, Node *parent)
{
    Node *newNode = createNode(key);
    newNode->parent = parent;
    parent->left = newNode;
    return newNode;
}

Node *createRight(int key, Node *parent)
{
    Node *newNode = createNode(key);
    newNode->parent = parent;
    parent->right = newNode;
    return newNode;
}

int isRoot(Node *node)
{
    return node->parent == NULL ? 1 : 0;
}

int isExternal(Node *node)
{
    return node->left == NULL && node->right == NULL ? 1 : 0;
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

void preOrder(Node *node){
    printf("%d ", node->key);
    if(node->left != NULL){
        preOrder(node->left);
    }
    if(node->right != NULL){
        preOrder(node->right);
    }
}
void postOrder(Node *node){
    if(node->left != NULL){
        postOrder(node->left);
    }
    if(node->right != NULL){
        postOrder(node->right);
    }
    printf("%d ", node->key);
}

void inOrder(Node *node){
    if(node->left != NULL){
        inOrder(node->left);
    }
    printf("%d ", node->key);
    if(node->right != NULL){
        inOrder(node->right);
    }
}
int main()
{
    Node *root = createNode(20);
    Node *node1 = createLeft(10, root);
    Node *node2 = createRight(5, root);
    Node *node3 = createLeft(10, node1);
    Node *node4 = createRight(5, node2);
    Node *node5 = createLeft(1, node2);
    // printf("%d", dept(node3));
    preOrder(root);
    printf("\n");
    postOrder(root);
    printf("\n");
    inOrder(root);
}