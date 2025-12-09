#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
    int *q;
    int front, rear;
    int cap;
} *Queue;

// Create queue
Queue CreateQueue(int capi) {
    Queue nq = (Queue)malloc(sizeof(struct queue));
    if (nq == NULL) {
        printf("Insufficient Memory!\n");
        exit(-1);
    }

    nq->q = (int *)malloc(sizeof(int) * capi);
    if (nq->q == NULL) {
        printf("Insufficient Memory!\n");
        exit(-1);
    }

    nq->front = -1;
    nq->rear  = -1;
    nq->cap   = capi;

    return nq;
}

// Resize queue
int Resize(Queue myQueue, int size) {
    int newSize = myQueue->cap + size;
    if (newSize <= 0)
        return 0;

    int *newArr = (int *)realloc(myQueue->q, sizeof(int) * newSize);
    if (newArr == NULL)
        return 0;

    myQueue->q   = newArr;
    myQueue->cap = newSize;

    return 1;
}

// Enqueue
void Enqueue(Queue myQueue, int item) {
    if (myQueue->rear == myQueue->cap - 1) {
        if (!Resize(myQueue, 1)) {
            printf("Queue Full! Cannot Enqueue\n");
            return;
        }
    }

    if (myQueue->front == -1)
        myQueue->front = 0;

    myQueue->q[++myQueue->rear] = item;
}

// Dequeue
void Dequeue(Queue myQueue) {
    if (myQueue->front == -1) {
        printf("Queue Empty!\n");
        return;
    }

    printf("Dequeued: %d\n", myQueue->q[myQueue->front]);

    if (myQueue->front == myQueue->rear) {
        myQueue->front = myQueue->rear = -1;
    } else {
        myQueue->front++;
    }

    Resize(myQueue, -1);  // reduce size
}

// Display
void DisplayQueue(Queue myQueue) {
    if (myQueue->front == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue: ");
    for (int i = myQueue->front; i <= myQueue->rear; i++)
        printf("%d ", myQueue->q[i]);
    printf("\n");
}

// Free memory
void DestroyQueue(Queue myQueue) {
    free(myQueue->q);
    free(myQueue);
}

// Main
int main() {
    Queue myQueue = CreateQueue(1);

    Enqueue(myQueue, 10);
    Enqueue(myQueue, 20);
    Enqueue(myQueue, 30);

    DisplayQueue(myQueue);

    Dequeue(myQueue);
    Dequeue(myQueue);

    DisplayQueue(myQueue);

    DestroyQueue(myQueue);
    return 0;
}
