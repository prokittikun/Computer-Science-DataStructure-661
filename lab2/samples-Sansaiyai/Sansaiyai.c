#include <stdio.h>
#include <stdlib.h>

typedef struct nd
{
    struct nd *prev;
    struct nd *next;
    int sum;
} Node;

int calculateSum(Node *node)
{
    if (node == NULL)
        return 0;

    if (node->sum != 0)
        return node->sum;

    node->sum = 1 + calculateSum(node->prev);
    return node->sum;
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    Node *saiYai[n];

    for (int i = 0; i < n; i++)
    {
        saiYai[i] = (Node *)malloc(sizeof(Node));
        saiYai[i]->next = NULL;
        saiYai[i]->prev = NULL;
        saiYai[i]->sum = 0;
    }

    for (int i = 0; i < n; i++)
    {
        int left = 0, right = 0;
        scanf("%d %d", &left, &right);

        if (left == 0 && right == 0)
        {
            continue;
        }
        else if (left == 0)
        {
            saiYai[right - 1]->prev = saiYai[i];
            saiYai[i]->next = saiYai[right - 1];
        }
        else if (right == 0)
        {
            saiYai[left - 1]->next = saiYai[i];
            saiYai[i]->prev = saiYai[left - 1];
        }
        else
        {
            saiYai[left - 1]->next = saiYai[i];
            saiYai[right - 1]->prev = saiYai[i];
            saiYai[i]->prev = saiYai[left - 1];
            saiYai[i]->next = saiYai[right - 1];
        }
    }

    int max = 0;

    for (int i = 0; i < n; i++)
    {
        int sum = calculateSum(saiYai[i]);
        printf("saiYai[%d] = %d\n", i, sum);
        if (sum > max)
        {
            max = sum;
        }
    }

    printf("%d", max);
    for (int i = 0; i < n; i++)
    {
        free(saiYai[i]);
    }

    return 0;
}

// #include <stdio.h>
// #include <stdlib.h>
// typedef struct nd
// {
//     struct nd *prev;
//     struct nd *next;
// } Node;
// int main()
// {
//     int n = 0;
//     scanf("%d", &n);
//     Node *saiYai[n];
//     for (int i = 0; i < n; i++)
//     {
//         saiYai[i] = (Node *)malloc(sizeof(Node));
//         saiYai[i]->next = NULL;
//         saiYai[i]->prev = NULL;
//     }

//     for (int i = 0; i < n; i++)
//     {
//         int left = 0, right = 0;
//         scanf("%d %d", &left, &right);

//         if (left == 0 && right == 0)
//         {
//             continue;
//         }
//         else if (left == 0)
//         {
//             saiYai[right - 1]->prev = saiYai[i];
//             saiYai[i]->next = saiYai[right - 1];
//         }
//         else if (right == 0)
//         {
//             saiYai[left - 1]->next = saiYai[i];
//             saiYai[i]->prev = saiYai[left - 1];
//         }
//         else
//         {
//             saiYai[left - 1]->next = saiYai[i];
//             saiYai[right - 1]->prev = saiYai[i];
//             saiYai[i]->prev = saiYai[left - 1];
//             saiYai[i]->next = saiYai[right - 1];
//         }
//     }
//     int max = 0;

//     for (int i = 0; i < n; i++)
//     {
//         int sum = 1;
//         Node *person = saiYai[i]->prev;
//         while (person != NULL)
//         {
//             sum++;
//             person = person->prev;
//         }
//         if (sum > max)
//         {
//             max = sum;
//         }
//     }
//     // for (int i = 0; i < n; i++)
//     // {
//     //     // Node *ptr = saiYai[i];
//     //     int sum = 1;
//     //     // while (1)
//     //     // {
//     //     //     if (ptr->prev == NULL)
//     //     //     {
//     //     //         Node *ptr2 = saiYai[i];
//     //     //         while (1)
//     //     //         {
//     //     //             if (ptr2->next == NULL)
//     //     //                 break;
//     //     //             sum++;
//     //     //             ptr2 = ptr2->next;
//     //     //         }
//     //     //         break;
//     //     //     }
//     //     //     sum++;
//     //     //     ptr = ptr->prev;
//     //     // }
//     //     for (Node *person = saiYai[i]->prev; person != NULL; person = person->prev)
//     //     {
//     //         sum++;
//     //     }
//     //     if (sum > max)
//     //     {
//     //         max = sum;
//     //     }
//     // }
//     printf("%d", max);
//     for (int i = 0; i < n; i++)
//     {
//         free(saiYai[i]);
//     }
// }
