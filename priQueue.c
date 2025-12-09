#include<stdio.h>
#include<stdlib.h>
#define Max 20

typedef struct myNode{
    int element,priority;
}Node;

typedef struct myPrioQueue{
    Node arr[Max];
    int size;
}*PrioQueue;


void Initilize(PrioQueue queue)
{
    queue->size = 0;
}

void Add(PrioQueue queue, int element,int priority)
{
    if(queue->size == Max)
    return;

    Node newNode;
    newNode.element = element;
    newNode.priority = priority;

    int i;
    for(i = queue->size-1;i >= 0 && queue->arr[i].priority > priority;i--)
        queue->arr[i+1] = queue->arr[i];

    queue->arr[i+1] = newNode;
    queue->size++;

}

Node Peek(PrioQueue queue)
{
    if(queue -> size == 0)
        return (Node){-1,-1};

    return queue->arr[0];
}

Node Pop(PrioQueue queue)
{
    if(queue->size == 0)
    return (Node){-1,-1};

    Node pop = queue->arr[0];
    for(int i = 0;i<=queue->size-1;i++)
        queue->arr[i]=queue->arr[i+1];

    queue->size--;
    return pop;
    
}



int main(){

    PrioQueue queue = (PrioQueue)malloc(sizeof(struct myPrioQueue));
    Initilize(queue);
    Add(queue,4,4);
    Add(queue,8,3);
    Add(queue,9,1);
    printf("Peek: %d\n", Peek(queue).element);
    printf("Pop: %d\n", Pop(queue).element);
    printf("Peek: %d\n", Peek(queue).element);

    

    return 0;
}