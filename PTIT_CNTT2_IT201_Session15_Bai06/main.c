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

int checkArray(Queue* queue) {
    for (int i = queue->front; i < queue->rear; i++) {
        if (queue->data[i+1] - queue->data[i] != 1) {
            return 0;
        }
    }
    return 1;
}

int main(void) {
    Queue queue;
    initQueue(&queue);
    int n;
    int value;
    printf("nhap so luong phan tu: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("nhap phan tu %d: ",i);
        scanf("%d", &value);
        enQueue(&queue, value);
    }
    int result = checkArray(&queue);
    if (result == 1) {
        printf("True\n");
    }else {
        printf("False\n");
    }
    return 0;
}