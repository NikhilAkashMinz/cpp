#include <stdio.h>
#include <stdlib.h>

typedef struct myQueue {
    int *arr;
    int rear, front;
    int capacity;
} *Queue;

Queue Initilize(int cap) {
    Queue q = (Queue)malloc(sizeof(struct myQueue));
    if (!q) {
        printf("Memory allocation failed for queue\n");
        exit(1);
    }

    q->arr = (int *)malloc(sizeof(int) * cap);
    if (!q->arr) {
        printf("Memory allocation failed for array\n");
        exit(1);
    }

    q->front = q->rear = -1;
    q->capacity = cap;
    return q;
}

int isEmpty(Queue q) {
    return q->front == -1;
}

int Resize(Queue q, int newCap) {
    int *newArr = (int *)realloc(q->arr, sizeof(int) * newCap);
    if (!newArr) return 0;   // failed

    q->arr = newArr;
    q->capacity = newCap;
    return 1;
}

void Enqueue(Queue q, int val) {
    // If full, grow capacity (e.g., double)
    if (q->rear == q->capacity - 1) {
        if (!Resize(q, q->capacity * 2)) {
            printf("Resize failed\n");
            exit(1);
        }
    }

    if (isEmpty(q)) {
        q->front = q->rear = 0;
    } else {
        q->rear++;
    }

    q->arr[q->rear] = val;
}

int Dequeue(Queue q) {
    if (isEmpty(q))
        return -1;

    int val = q->arr[q->front];

    if (q->front == q->rear) {
        // Queue becomes empty
        q->front = q->rear = -1;
    } else {
        q->front++;
    }

    return val;
}

void Display(Queue q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    for (int i = q->front; i <= q->rear; i++) {
        printf("| %d | ", q->arr[i]);
    }
    printf("\n");
}

int Peek(Queue q) {
    if (isEmpty(q)) return -1;
    return q->arr[q->front];
}

int main() {
    Queue q = Initilize(2);   // start with capacity 2

    Enqueue(q, 10);
    Enqueue(q, 20);
    Enqueue(q, 30);           // triggers resize

    Display(q);

    printf("Dequeued: %d\n", Dequeue(q));
    Display(q);
    Enqueue(q, 30);   
    Enqueue(q, 30);   
    Enqueue(q, 30);   
    Display(q);
    printf("Peek: %d\n", Peek(q));
    
    return 0;
}
