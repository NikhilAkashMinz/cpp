#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* next;
} *Node;


Node top = NULL;


int isEmpty() {
    return top == NULL;
}


void push(int data) {
    Node newNode = (Node)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Stack Overflow! Memory allocation failed.\n");
        return;
    }

    newNode->data = data;
    newNode->next = top;
    top = newNode;

    printf("%d pushed to stack\n", data);
}


void pop() {
    if (isEmpty()) {
        printf("Stack Underflow! Cannot pop from empty stack.\n");
        return;
    }

    Node temp = top;
    printf("%d popped from stack\n", top->data);
    top = top->next;
    free(temp);
}


int peek() {
    if (isEmpty()) {
        printf("Stack is empty!\n");
        return -1; // Return a sentinel value for empty stack
    }
    return top->data;
}


void display() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
        return;
    }

    Node temp = top;
    printf("Stack elements (top → bottom): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int main() {
    push(10);
    push(20);
    push(30);

    display();

    printf("Top element is %d\n", peek());

    pop();
    display();

    return 0;
}
