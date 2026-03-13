#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} *NODE;

typedef struct Stack {
    NODE top;
} *STACK;

STACK createStack(){
    STACK stack = (STACK)malloc(sizeof(struct Stack));
    if(stack == NULL){
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    stack->top = NULL;
    return stack;
}

int isEmpty(STACK stack){
    return (stack->top == NULL);
}

void push(STACK stack,int data)
{
    NODE newNode  = (NODE)malloc(sizeof(struct Node));
    if(newNode == NULL){
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;

    printf("Pushed: %d\n", data);
}

void pop(STACK stack)
{
    if(isEmpty(stack)){
        printf("Stack Underflow\n");
        return;
    }

   NODE temp = stack->top;
    printf("Popped: %d\n", temp->data);
    stack->top = temp->next;
    free(temp);
}

int peek(STACK stack){
    if(isEmpty(stack)){
        printf("Stack is empty\n");
        return -1; // Return -1 to indicate stack is empty
    }
    return stack->top->data;
}

void Display(STACK stack)
{
    if(isEmpty(stack))
    {
        printf("Stack is Empty\n");
        return;
    }

    NODE temp = stack->top;
    printf("Stack elements: ");
    while(temp != NULL)
    {
        printf("[%d]-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void DestroyStack(STACK stack)
{
    while(!isEmpty(stack))
    {
        pop(stack);
    }
    free(stack);
}

int main()
{
    STACK stack = createStack();

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    Display(stack);

    printf("Top element: %d\n", peek(stack));

    pop(stack);
    Display(stack);

    DestroyStack(stack);
    return 0;
}