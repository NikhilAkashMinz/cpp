#include<stdio.h>
#include<stdlib.h>
#define Max 20


typedef struct{
    int items[Max];
    int rear,front;
}*Queue;

Queue CreateQueue() {
    Queue q = (Queue)malloc(sizeof(*q));
    q->front = q->rear = -1;
    return q;
}

void Initilize(Queue q)
{
    q->front = q->rear = -1;
}

int IsEmpty(Queue q)
{
    return (q->front==-1 && q->rear == -1);
}

int IsFull(Queue q)
{
    return q->rear == Max-1;
}

void Enqueue(Queue q,int value){
    if(IsFull(q)) return;

    if(IsEmpty(q)) q->front = 0;

    q->items[++q->rear] = value;
    printf("Enqueued %d\n",value);
}

int Dequeue(Queue q)
{
    if(IsEmpty(q)) return -1;

    int item = q->items[q->front++];
    if(q->front > q->rear) Initilize(q);

    return item;
}

int Peek(Queue q)
{
    if(IsEmpty(q)) return -1;

    return q->items[q->front];
}

void Display(Queue q)
{
    if(IsEmpty(q))return;

    for(int i=q->front;i<=q->rear;i++)
        printf("| %d |",q->items[i]);
    printf("\n");
}

int main(){
        Queue q = CreateQueue();

    Enqueue(q, 10);
    Enqueue(q, 20);
    Enqueue(q, 30);

    Display(q);

    printf("Dequeued: %d\n", Dequeue(q));
    printf("Peek: %d\n", Peek(q));

    Display(q);
    return 0;
}