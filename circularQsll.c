#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} *NODE;

typedef struct Queue{
    NODE front, rear;
} *QUEUE;


NODE createNode(int data)
{
    NODE newNode = (NODE)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


QUEUE createQueue()
{
    QUEUE q = (QUEUE)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

int isEmpty(QUEUE q)
{
    return (q == NULL || q->front == NULL);
}

void enqueue(QUEUE q, int data)
{
    NODE newNode = createNode(data);
    if(isEmpty(q))
    {
        q->front = q->rear = newNode;
        q->rear->next = q->front; // Point rear to front to make it circular
    }
    else{
        newNode->next = q->front; // Point new node to front
        q->rear->next = newNode;
        q->rear = newNode; // Update rear to new node
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
        int data = q->front->data;
        if(q->front == q->rear)
        {
            free(q->front);
            q->front = q->rear = NULL;
        }else{
            NODE temp = q->front;
            q->front = q->front->next;
            q->rear->next = q->front; // Update rear's next to new front
            free(temp);
        }
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
        NODE temp = q->front;
        do{
            printf("%d ", temp->data);
            temp = temp->next;
        }while(temp != q->front);
        printf("\n");
    }
}

int main()
{
    QUEUE q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    
    Display(q);
    Dequeue(q);
    Display(q);
    
    // Attempt to dequeue from empty queue
    return 0;
}