#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct {
    char name[MAX][30];
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

void enQueue(Queue* queue, char name[]) {
    if (isFullQueue(queue)) {
        printf("hang doi day\n");
        return;
    }
    queue->rear++;
    strcpy(queue->name[queue->rear], name);
}

void serveCustomers(Queue* queue) {
    if (isEmptyQueue(queue)) {
        printf("hang doi rong\n");
        return;
    }
    printf("%s\n", queue->name[queue->front]);
    queue->front++;
}

void displayQueue(Queue* queue) {
    if (isEmptyQueue(queue)) {
        printf("hang doi rong\n");
        return;
    }
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%s\n", queue->name[i]);
    }
}

int main(void) {
    Queue queue;
    initQueue(&queue);
    int choose;
    char name[30];
    do {
        printf("1.Them khach hang\n"
               "2. Phuc vu\n"
               "3. Hien thi danh sach cho\n"
               "4.Thoat\n "
               "Nhap chuc nang: ");
        scanf("%d", &choose);
        getchar();
        switch (choose) {
            case 1:
                printf("nhap ten khach");
                fgets(name, 30, stdin);
                name[strlen(name) - 1] = '\0';
                enQueue(&queue, name);
                break;
            case 2:
                serveCustomers(&queue);
                break;
            case 3:
                displayQueue(&queue);
                break;
            case 4:
                break;
            default:
                printf("khong thuoc cac chuc nang\n");
        }
    }while (choose !=4);
    return 0;
}