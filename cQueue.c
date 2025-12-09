#include<stdio.h>
#include<stdlib.h>
#define Max 20

typedef struct crQueue {
    int arr[Max];
    int front, rear;
} *CrQueue;

void Initialize(CrQueue cr)
{
    cr->front = cr->rear = -1;
}

int isEmpty(CrQueue cr)
{
    return (cr->front == -1);
}

int isFull(CrQueue cr)
{
    return ((cr->rear + 1) % Max == cr->front);
}

void Enqueue(CrQueue cr, int val)
{
    if (isFull(cr)) return;

    if (cr->front == -1)
        cr->front = cr->rear = 0;
    else
        cr->rear = (cr->rear + 1) % Max;

    cr->arr[cr->rear] = val;
}

int Dequeue(CrQueue q)
{
    if (isEmpty(q)) return -1;

    int ele = q->arr[q->front];

    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front = (q->front + 1) % Max;

    return ele;
}

void DisplayQueue(CrQueue q)
{
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }

    int i = q->front;
    printf("Queue: ");
    while (1) {
        printf("%d ", q->arr[i]);
        if (i == q->rear) break;
        i = (i + 1) % Max;
    }
    printf("\n");
}

int main()
{
    CrQueue q = (CrQueue)malloc(sizeof(struct crQueue));
    Initialize(q);

    Enqueue(q, 1);
    Enqueue(q, 2);
    Enqueue(q, 3);
    Enqueue(q, 4);

    DisplayQueue(q);
    
    printf("Dequeued: %d\n", Dequeue(q));
    DisplayQueue(q);

    return 0;
}
