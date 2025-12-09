#include<stdio.h>
#include<stdlib.h>


typedef struct myNode{
    int data;
    struct myNode *next;
}*Node;

typedef struct myQueue{
    Node front;
    Node rear;
}*Queue;

Node InitiNode(int data)
{
    Node newNode = (Node)malloc(sizeof(struct myNode));

    if(!newNode) return NULL;

    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Queue InitiQueue()
{
    Queue q = (Queue)malloc(sizeof(struct myQueue));
    if(q==NULL) return NULL;

    q->front = q->rear = NULL;
    return q;
}

int isEmpty(Queue q)
{
    return(q->front == NULL || q->rear == NULL);
}

void Enqueue(Queue q, int val)
{
    if(q == NULL)
        return;

    Node newNode = InitiNode(val);

    if(isEmpty(q))
        q->front = q->rear = newNode;
    else{
        q->rear->next = newNode;
        q->rear = newNode;
    }

}

int Dequeue(Queue q)
{
    if(isEmpty(q)) return-1;

    int val = q->front->data;

    Node temp = q->front;
    q->front = q->front->next;

    if(q->front == NULL) q->rear == NULL;

    free(temp);
    return val;
}

void Display(Queue q)
{
    if(isEmpty(q)) 
    {
        printf("Queue is Empty");
        return ;
    }

    Node temp = q->front;
    while(temp->next != NULL)
    {
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}



int main()
{

    Queue q = InitiQueue();
    
    Enqueue(q, 10);
    Enqueue(q, 20);
    Enqueue(q, 30);

    Display(q);

    printf("Dequeued: %d\n", Dequeue(q));
    Display(q);

    return 0;
}