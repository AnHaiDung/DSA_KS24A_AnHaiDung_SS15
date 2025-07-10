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
    return queue->rear == -1 || queue->front > queue->rear;
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
    int n;
    int value;
    printf("nhap so luong phan tu: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("nhap phan tu %d: ",i);
        scanf("%d", &value);
        enQueue(&queue, value);
    }
    if (isEmptyQueue(&queue)) {
        printf("True\n");
    }else {
        printf("False\n");
    }
    return 0;
}