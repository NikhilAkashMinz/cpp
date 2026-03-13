#include<stdio.h>
#include<stdlib.h>
#define MAX 100

// typedef struct QUEUE{
//     int arr[MAX];
//     int front;
//     int rear;
// } *QUEUE;

// void initQUEUE(QUEUE q){
//     q->front = -1;
//     q->rear = -1;
// }
// int isFull(QUEUE q){
//     return (q->rear == MAX - 1);
// }

// int isEmpty(QUEUE q){
//     return (q->front == -1 || q->front > q->rear);
    
// }

// void enQUEUE(QUEUE q, int data){
//     if(isFull(q)){
//         printf("QUEUE Overflow\n");
//         return;
//     }
//     if(isEmpty(q)){
//         q->front = 0; // First element being enQUEUEd
//     }
//     q->arr[++(q->rear)] = data;
//     printf("EnQUEUEd: %d\n", data);
// }
// int deQUEUE(QUEUE q)
// {
//     if(isEmpty(q))
//     {
//         printf("QUEUE Underflow\n");
//         return -1; // Return -1 to indicate QUEUE is empty
//     }
//     int item = q->arr[q->front++];
//     if(q->front > q->rear)
//         initQUEUE(q); // Reset the QUEUE if it becomes empty after deQUEUE
//     printf("DeQUEUEd: %d\n", item);
//     return item;
// }

// int peek(QUEUE q){
//     if(isEmpty(q)){
//         printf("QUEUE is empty\n");
//         return -1; // Return -1 to indicate QUEUE is empty
//     }
//     return q->arr[q->front];
// }

// void display(QUEUE q){
//     if(isEmpty(q)){
//         printf("QUEUE is empty\n");
//         return;
//     }
//     printf("QUEUE elements: ");
//     for(int i = q->front; i <= q->rear; i++){
//         printf("%d ", q->arr[i]);
//     }
//     printf("\n");
// }

// int main()
// {
//     printf("QUEUE Implementation using Array\n");
//     QUEUE q = (QUEUE)malloc(sizeof(struct QUEUE));
//     initQUEUE(q);
//     enQUEUE(q, 10);
//     enQUEUE(q, 20); 
//     enQUEUE(q, 30);
//     enQUEUE(q, 40);
//     display(q);
//     printf("Front element: %d\n", peek(q));
//     deQUEUE(q);
//     display(q);
//     return 0;
// }

typedef struct QueueAdt{
    int *queue;
    int front;
    int rear;
    int capacity;
} *QUEUE;

QUEUE CreateQueue(int capacity)
{
    QUEUE q = (QUEUE)malloc(sizeof(struct QueueAdt));
    if(q == NULL){
        printf("Memory allocation failed\n");
        return NULL;
    }

    q->queue = (int *)malloc(capacity * sizeof(int));
    if(q->queue == NULL){
        printf("Memory allocation failed\n");
        free(q);
        return NULL;
    }

    q->capacity = capacity;
    q->front = -1;
    q->rear = -1;
    return q;
}

int ResizeQueue(QUEUE q, int new_capacity)
{
    int new_size = q->capacity + new_capacity;
    int *new_queue = (int *)realloc(q->queue, new_size * sizeof(int));
    if(new_queue == NULL){
        printf("Memory allocation failed\n");
        return -1; // Return the original queue if resizing fails
    }
    q->capacity = new_size;
    q->queue = new_queue;
    return 1;
}

void Enqueue(QUEUE q, int data)
{
    if(q->rear == q->capacity -1)
    {
        printf("Queue is full, resizing...\n");
        if(!ResizeQueue(q, 1)) // Increase capacity by 10
        {
            printf("Failed to resize the queue\n");
            return;
        }
    }

    if(q->front == -1) // First element being enqueued
        q->front = 0;
    q->queue[++(q->rear)] = data;
    printf("Enqueued: %d\n", data);
}

void Dequeue(QUEUE q)
{
    if(q->front == -1 || q->front > q->rear)
    {
        printf("Queue Underflow\n");
        return;
    }

    if(q->front >= q->rear)
    {
        q->front = -1; // Reset the queue if it becomes empty after dequeue
        q->rear = -1;
    }
    else
    {
        int item = q->queue[q->front++];
        printf("Dequeued: %d\n", item);
        ResizeQueue(q, -1); // Decrease capacity by 1
    }
}

void display(QUEUE q)
{
    if(q->front == -1 || q->front >= q->rear)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for(int i = q->front; i <= q->rear; i++)
    {
        printf("%d ", q->queue[i]);
    }
    printf("\n");
}

void DestroyQueue(QUEUE q)
{
    free(q->queue);
    free(q);
    printf("Queue destroyed successfully\n");
}

int main()
{
    QUEUE q = CreateQueue(5);
    Enqueue(q, 10);
    Enqueue(q, 20);
    Enqueue(q, 30);
    Enqueue(q, 40);
    display(q);
    Dequeue(q);
    display(q);
    DestroyQueue(q);
    return 0;
}