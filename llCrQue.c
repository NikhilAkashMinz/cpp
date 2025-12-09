#include <stdio.h>
#include <stdlib.h>

typedef struct myNode {
    int data;
    struct myNode *next;
} *Node;

typedef struct myQueue {
    Node front;
    Node rear;
} *CrQueue;

// Create a new node
Node InitiNode(int data) {
    Node newNode = (Node)malloc(sizeof(struct myNode));
    if (!newNode) return NULL;

    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Initialize queue
CrQueue InitiQueue() {
    CrQueue q = (CrQueue)malloc(sizeof(struct myQueue));
    if (!q) return NULL;

    q->front = q->rear = NULL;
    return q;
}

// Check if queue is empty
int isEmpty(CrQueue q) {
    return q == NULL || q->front == NULL;
}

// Enqueue element
void Enqueue(CrQueue q, int val) {
    if (!q) return;

    Node newNode = InitiNode(val);

    if (isEmpty(q)) {
        q->front = q->rear = newNode;
        newNode->next = q->front; // Circular link
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
        q->rear->next = q->front; // Maintain circular structure
    }
}

// Dequeue element
int Dequeue(CrQueue q) {
    if (isEmpty(q)) return -1;

    int val = q->front->data;

    if (q->front == q->rear) {
        free(q->front);
        q->front = q->rear = NULL;
    } else {
        Node temp = q->front;
        q->front = q->front->next;
        q->rear->next = q->front; // Maintain circular structure
        free(temp);
    }
    return val;
}

// Display queue
void DisplayQueue(CrQueue q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }

    Node temp = q->front;
    printf("Queue: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != q->front);

    printf("\n");
}

int main() {
    CrQueue q = InitiQueue();

    Enqueue(q, 10);
    Enqueue(q, 20);
    Enqueue(q, 30);

    DisplayQueue(q);

    printf("Dequeued: %d\n", Dequeue(q));
    DisplayQueue(q);

    printf("Dequeued: %d\n", Dequeue(q));
    DisplayQueue(q);

    return 0;
}
