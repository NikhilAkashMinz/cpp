#include<stdio.h>
#include<stdlib.h>

#define MAX 100
typedef struct Queue{
    int arr[MAX];
    int front ,rear;
} *QUEUE;


QUEUE initiQueue(QUEUE q)
{
    q->front = q->rear = -1;
}

int isEmpty(QUEUE q)
{
    return (q->front == -1 && q->rear == -1);
}

int isFull(QUEUE q)
{
    return (q->rear + 1) % MAX == q->front;
}

void Enqueue(QUEUE q,int data)
{
    if(isFull(q))
    {
        printf("Queue is full\n");
        return;
    }
    else{
        if(q->front == -1)
        {
            q->front = 0;
        }
        q->rear = (q->rear + 1) % MAX;
        q->arr[q->rear] = data;
    }
}

void Dequeue(QUEUE q)
{
    if(isEmpty(q))
    {
        printf("Queue is empty\n");
        return ;
    }
    else{
        int data = q->arr[q->front];
        if(q->front >= q->rear) 
        {
            q->front = q->rear = -1;
        }
        else{
            q->front = (q->front + 1) % MAX;
        }
        printf("Dequeued data: %d\n", data);
    }
}

void Display(QUEUE q)
{
    if(isEmpty(q))
    {
        printf("Queue is empty\n");
        return;
    }
    else{
        for(int i=q->front; i != q->rear; i = (i + 1) % MAX)
        {
            printf("%d ", q->arr[i]);
        }
        printf("%d\n", q->arr[q->rear]);
    }
}

int main()
{
    QUEUE q = (QUEUE)malloc(sizeof(struct Queue));
    initiQueue(q);
    Enqueue(q, 10);
    Enqueue(q, 20);
    Enqueue(q, 30);
    Display(q);
    Dequeue(q);
    Display(q);
    return 0;
}

