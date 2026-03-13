#include<stdlib.h>
#include<stdio.h>
#define MAX 100

typedef struct Node{
    int data;
    int priority;
} *NODE;

typedef struct Queue{
    NODE arr[MAX];
    int size;
} *QUEUE;


void initiQueue(QUEUE q)
{
    q->size = 0;
}

int isEmpty(QUEUE q)
{
    return (q->size == 0);
}
int size(QUEUE q)
{
    return q->size;
}

void enqueu(QUEUE q, int data, int priority)
{
    if(q->size == MAX)
    {
        printf("is full\n");
        return;
    }
    else
    {
        NODE newNode = (NODE)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->priority = priority;
        int i;
        for(i =q->size - 1; i>=0 && q->arr[i]->priority > priority; i--)
        {
            q->arr[i+1] = q->arr[i];
        }
        q->arr[i+1] = newNode;
        q->size++;
    }
}

void pop(QUEUE q)
{
    if(isEmpty(q))
    {
        printf("Queue is empty\n");
        return;
    }
    else
    {
        NODE temp = q->arr[0];
        for(int i=0; i<q->size - 1; i++)
        {
            q->arr[i] = q->arr[i+1];
        }
        q->size--;
        printf("Popped data: %d with priority: %d\n", temp->data, temp->priority);
        free(temp);
    }
}

void Display(QUEUE q)
{
    if(isEmpty(q))
    {
        printf("Queue is empty\n");
        return;
    }
    else
    {
        for(int i=0; i<q->size; i++)
        {
            printf("Data: %d, Priority: %d\n", q->arr[i]->data, q->arr[i]->priority);
        }
    }
}


int main()
{
    QUEUE q = (QUEUE)malloc(sizeof(struct Queue));
    initiQueue(q);
    enqueu(q, 10, 2);
    enqueu(q, 20, 1);
    enqueu(q, 30, 3);
    Display(q);
    pop(q);
    pop(q);
    pop(q);
    return 0;
}
