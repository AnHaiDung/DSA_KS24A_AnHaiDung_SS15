#include <stdio.h>
#define MAX 100

typedef struct {
    int data[MAX];
    int front;
    int rear;
}Queue;

void initQueue(Queue* queue) {
    queue->front = 0;
    queue->rear = -1;
}

int isEmptyQueue(Queue* queue) {
    return queue->front > queue->rear;
}

int isFullQueue(Queue* queue) {
    return queue->rear == MAX - 1;
}

void enQueue(Queue* queue, int value) {
    if (isFullQueue(queue)) {
        printf("da day\n");
        return;
    }
    queue->rear++;
    queue->data[queue->rear] = value;
}

int main(void) {
    Queue queue;
    initQueue(&queue);
    enQueue(&queue, 10);
    enQueue(&queue, 20);
    enQueue(&queue, 30);
    enQueue(&queue, 40);
    enQueue(&queue, 50);
    return 0;
}