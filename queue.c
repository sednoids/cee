#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

typedef struct Queue {
  char items[MAX_SIZE];
  int size,
      frontPointer,
      rearPointer;
} tQueue;

void len(tQueue *queue) {
  printf("%d\n",queue->size);
}

void initialiseQueue(tQueue *queue) {
  queue->frontPointer = 0;
  queue->rearPointer = -1;
}

void enqueue(tQueue *queue, char item) {
  // Check if the queue is full, if it is stop and report an error.
  if (queue->size == MAX_SIZE) {
    printf("ERROR: Queue already full.");
    return;
  }
  // Increase the position of the rear pointer by 1.
  queue->rearPointer++;
  // Enqueue the item at the position indicated by the rear pointer.
  queue->items[queue->rearPointer] = item;
  // Add 1 to the queue size.
  queue->size++;
}

void dequeue(tQueue *queue) {
  if (queue->size == 0) {
    // Check if the queue is empty, if it is stop and report an error.
    printf("ERROR: Queue already empty.");
    return;
  }
  // Dequeue the item at the position indicated by the front pointer;
  queue->items[queue->frontPointer] = '\0';
  // Increase the position of the front pointer by 1.
  queue->frontPointer++;
  // Remove 1 from the queue size;
  queue->size--;
}

void displayQueue(tQueue *queue) {
  for (int i = 0; i < MAX_SIZE; i++) {
    if (queue->items[i] == '\0') continue;

    if (queue->items[queue->rearPointer] == queue->items[i]) {
      printf("rear -> %c\n", queue->items[i]);
    } else if (queue->items[queue->frontPointer] == queue->items[i]) {
      printf("front -> %c\n", queue->items[i]);
    } else {
      printf("%c\n", queue->items[i]);
    }
  }
  printf("-----------\n");
}

int main() {
  // tQueue queue;
  // initialiseQueue(&queue);
  // enqueue(&queue, 'A');
  // displayQueue(&queue);
  // enqueue(&queue, 'B');
  // displayQueue(&queue);
  // len(&queue);

  tQueue *queue = (tQueue *) malloc(sizeof(tQueue));

  if (queue == NULL) {
    printf("malloc() failed.\n");
  }
  initialiseQueue(queue);
  enqueue(queue, 'A');
  displayQueue(queue);
  enqueue(queue, 'B');
  displayQueue(queue);
  enqueue(queue, 'C');
  displayQueue(queue);
  dequeue(queue);
  displayQueue(queue);
  free(queue);

  queue = NULL;

  return 0;
  
}
