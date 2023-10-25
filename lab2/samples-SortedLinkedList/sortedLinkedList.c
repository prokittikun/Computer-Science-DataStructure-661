#include <stdio.h>
#include <stdlib.h>

typedef struct nd
{
    int value;
    struct nd *next;

} Node;

int main()
{
    Node *head = NULL;
    int count = 0;
    while (1)
    {
        int value;
        scanf("%d", &value);
        if (value == -1)
            break;
        count++;
        if (head == NULL)
        {
            Node *tmp = (Node *)malloc(sizeof(Node));
            tmp->value = value;
            tmp->next = NULL;
            head = tmp;
        }
        else
        {
            Node *ptr = head;
            if (value > ptr->value)
            {
                while (1)
                {

                    if (ptr->next == NULL)
                    {
                        Node *tmp = (Node *)malloc(sizeof(Node));
                        tmp->value = value;
                        tmp->next = NULL;
                        ptr->next = tmp;
                        break;
                    }
                    else if (ptr->next->value > value)
                    {
                        Node *tmp = (Node *)malloc(sizeof(Node));
                        tmp->value = value;
                        tmp->next = ptr->next;
                        ptr->next = tmp;
                        break;
                    }

                    ptr = ptr->next;
                }
            }
            else
            {
                Node *tmp = (Node *)malloc(sizeof(Node));
                tmp->value = value;
                tmp->next = ptr;
                head = tmp;
            }
        }
    }
    

    Node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d\n", ptr->value);
        ptr = ptr->next;
    }
}