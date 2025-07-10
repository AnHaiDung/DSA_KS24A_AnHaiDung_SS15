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

void serveCustomer(Queue* queueOld, Queue* queueNormal) {
    if (!isEmptyQueue(queueOld)) {
        printf("%s",queueOld->name[queueOld->front]);
        queueOld->front++;
    }else if(!isEmptyQueue(queueNormal)) {
        printf("%s",queueNormal->name[queueNormal->front]);
        queueNormal->front++;
    }else {
        printf("hang doi rong\n");
    }
}

void displayQueue(Queue* queue) {
    if (isEmptyQueue(queue)) {
        printf("hang doi rong\n");
        return;
    }
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%s\n",queue->name[i]);
    }
}

int main(void) {
    Queue queueOld;
    Queue queueNormal;
    initQueue(&queueOld);
    initQueue(&queueNormal);
    int choose;
    int age;
    char name[30];
    do {
        printf("1. Them khach hang\n"
               "2. Phuc vu \n"
               "3. Hien thi hang doi \n"
               "4. thoat chuong trinh\n"
               "nhap lua chon: ");
        scanf("%d", &choose);
        getchar();
        switch (choose) {
            case 1:
                printf("nhap ten khach");
                fgets(name, 30, stdin);
                name[strlen(name)-1] = '\0';
                printf("nhap tuoi");
                scanf("%d", &age);
                getchar();
                if (age >= 60) {
                    enQueue(&queueOld, name);
                }else{
                    serveCustomer(&queueOld, &queueNormal);
                }
                break;
            case 2:
                serveCustomer(&queueOld, &queueNormal);
                break;
            case 3:
                displayQueue(&queueOld);
                displayQueue(&queueNormal);
                break;
            case 4:
                break;
            default:
                printf("khong thuoc chuong trinh\n");
        }
    }while (choose!=4);
    return 0;
}