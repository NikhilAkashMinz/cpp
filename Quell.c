#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} *NODE;

typedef struct QueueAdt{
    NODE front;
    NODE rear;
} *QUEUE;

NODE createNode(int data)
{
    NODE newNode = (NODE)malloc(sizeof(struct Node));
    if(newNode == NULL){
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    else{
        newNode->data = data;
        newNode->next = NULL;
    }
    return newNode;
}
int isEmpty(QUEUE q)
{
    return (q->front == NULL && q->rear == NULL);
}

QUEUE createQueue()
{
    QUEUE q = (QUEUE)malloc(sizeof(struct QueueAdt));
    if(q == NULL){
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    q->front = NULL;
    q->rear = NULL;
    return q;
}

void Enqueue(QUEUE q, int data)
{
    NODE newNode = createNode(data);
    if(isEmpty(q))
    {
        q->front= q->rear = newNode;
       
    }
    q->rear->next = newNode;
    q->rear = newNode;
    printf("Enqueued: %d\n", data);
}

int Dequeue(QUEUE q)
{
    if(isEmpty(q))
    {
        printf("Queue Underflow\n");
        return 0;
    }
    NODE temp = q->front;
    int data = temp->data;
    printf("Dequeued: %d\n", temp->data);
    q->front = q->front->next;
    if(q->front == NULL) // If the queue becomes empty after dequeue
        q->rear = NULL;
    free(temp);
    return data;
}

void Display(QUEUE q)
{
    if(isEmpty(q))
    {
        printf("Queue is Empty\n");
        return;
    }
    NODE temp = q->front;
    printf("Queue Elements: ");
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    QUEUE q = createQueue();
    Enqueue(q, 10);
    Enqueue(q, 20);
    Enqueue(q, 30);
    Display(q);
    Dequeue(q);
    Display(q);
    Dequeue(q);
    Dequeue(q);
    Dequeue(q); // Attempt to dequeue from an empty queue
    return 0;
}