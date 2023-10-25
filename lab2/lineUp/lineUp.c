#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int value;
  struct Node* next;
} Node;

typedef struct Queue {
  Node* front;
  Node* rear;
} Queue;

Node* createNode(int value) {
  Node* node = (Node*)malloc(sizeof(Node));
  node->value = value;
  node->next = NULL;
  return node;
}

Queue* createQueue() {
  Queue* queue = (Queue*)malloc(sizeof(Queue));
  queue->front = NULL;
  queue->rear = NULL;
  return queue;
}

void enqueue(Queue* queue, int value) {
  Node* node = createNode(value);
  if (queue->rear == NULL) {
    queue->front = queue->rear = node;
    return;
  }

  queue->rear->next = node;
  queue->rear = node;
}

int dequeue(Queue* queue) {
  if (queue->front == NULL)
    return -1;

  int value = queue->front->value;
  Node* temp = queue->front;
  queue->front = queue->front->next;

  if (queue->front == NULL)
    queue->rear = NULL;

  free(temp);
  return value;
}

int main() {
  int n, value;
  scanf("%d", &n);

  Queue* rows[n];
  for (int i = 0; i < n; i++) {
    rows[i] = createQueue();
  }

  // First student goes to the first row
  scanf("%d", &value);
  enqueue(rows[0], value);

  for (int i = 1; i < n; i++) {
    scanf("%d", &value);
    int added = 0;
    
    // Check if the student should be placed at the end of the current row
    if (value > rows[i - 1]->rear->value) {
      enqueue(rows[i - 1], value);
      added = 1;
    }

    // Check if the student should be placed at the beginning of any previous row
    for (int j = i - 2; j >= 0 && !added; j--) {
      if (value < rows[j]->front->value) {
        enqueue(rows[j], value);
        added = 1;
        break;
      }
    }

    // If the student hasn't been added to any previous row, create a new row
    if (!added) {
      enqueue(rows[i], value);
    }
  }

  // Output the arrangement of students in each row
  printf("There are %d lines in total\n", n);
  for (int i = 0; i < n; i++) {
    Node* current = rows[i]->front;
    while (current != NULL) {
      printf("%d", current->value);
      current = current->next;
      if (current != NULL) {
        printf(" ");
      }
    }
    printf("\n");
  }

  // Free allocated memory
  for (int i = 0; i < n; i++) {
    Node* current = rows[i]->front;
    while (current != NULL) {
      Node* temp = current;
      current = current->next;
      free(temp);
    }
    free(rows[i]);
  }

  return 0;
}
