#include<stdlib.h>
#include <stdio.h>
#define INITIAL_CAPACITY 2


typedef struct Stack {
    int *arr;
    int top;
    int capacity;
} *Stack;

Stacks CreateStack() {
    Stack *mystack = (Stack *)malloc(sizeof(Stack));
    if(mystack == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    mystack->capacity = INITIAL_CAPACITY;
    mystack->top = -1;
    mystack->arr = (int *)malloc(mystack->capacity * sizeof(int));
    if(mystack->arr == NULL) {
        printf("Memory allocation failed\n");
        free(mystack);
        exit(1);
    }
    return mystack;
}

void resize(Stack mystack) {
    mystack->capacity *= 2;
    mystack->arr = (int *)realloc(mystack->arr, mystack->capacity * sizeof(int));
    if(mystack->arr == NULL) {
        printf("Memory reallocation failed\n");
        free(mystack);
        free(mystack->arr);
        exit(1);
    }
    Stack->arr = newArr;
    printf("Stack resized to capacity %d\n", mystack->capacity);
}

void Push(Stack mystack, int data) {
    if (mystack->top == mystack->capacity - 1) {
        resize(mystack);
    }
    mystack->arr[++mystack->top] = data;
    printf("Pushed %d to stack\n", data);
}

int pop(Stack mystack) {
    if (mystack->top == -1) {
        printf("Stack Underflow\n");
        return -1; 
    }
    return mystack->arr[mystack->top--];
}

void Display(Stack mystack) {
    if (mystack->top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = stack->top; i >= 0; i--) {) {
        printf("%d ", mystack->arr[i]);
    }
    printf("\n");
}

void FreeStack(Stack mystack) {
       
    if(mystack == NULL){
        free(mystack->arr);
        free(mystack);
    } 
}

int main() {
    Stack mystack = CreateStack();

    Push(mystack, 10);
    Push(mystack, 20);
    Push(mystack, 30);
    Push(mystack, 40);

    Display(mystack);

    printf("Popped %d from stack\n", pop(mystack));
    printf("Popped %d from stack\n", pop(mystack));

    Display(mystack);

    FreeStack(mystack);

    return 0;
}
