#include <stdio.h>
#define MAX 10

typedef struct tower {
    int stack[MAX];
    int top;
    char name;
} Tower;

void initStack(Tower *tower, char name) {
    tower->name = name;
    tower->top = -1;
}

void push(Tower *tower, int data) {
    if (tower->top < MAX - 1) {
        tower->top++;
        tower->stack[tower->top] = data;
    }
}

int pop(Tower *tower) {
    if (tower->top > -1) {
        int data = tower->stack[tower->top];
        tower->top--;
        return data;
    }
    return -1;
}

void printStack(Tower tower) {
    printf("Tower %c: ", tower.name);
    for (int i = 0; i <= tower.top; i++) {
        printf("%d ", tower.stack[i]);
    }
    printf("\n");
}

void towerOfHanoi(int n, Tower *source, Tower *target, Tower *auxiliary, int *moveCount) {
    if (n == 1) {
        push(target, pop(source));
        (*moveCount)++;
        printf("Move #%d: From %c to %c\n", *moveCount, source->name, target->name);
        printStack(*source);
        printStack(*auxiliary);
        printStack(*target);
        return;
    }
    
    towerOfHanoi(n - 1, source, auxiliary, target, moveCount);
    push(target, pop(source));
    (*moveCount)++;
    printf("Move #%d: From %c to %c\n", *moveCount, source->name, target->name);
    printStack(*source);
    printStack(*auxiliary);
    printStack(*target);
    towerOfHanoi(n - 1, auxiliary, target, source, moveCount);
}

int main() {
    int n = 3;
    Tower A, B, C;
    initStack(&A, 'A');
    initStack(&B, 'B');
    initStack(&C, 'C');
    
    int moveCount = 0;
    towerOfHanoi(n, &A, &C, &B, &moveCount);
    printf("Total moves: %d\n", moveCount);

    return 0;
}
