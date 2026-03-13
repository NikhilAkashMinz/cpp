#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct Stack{
    int arr[MAX];
    int top;
} *STACK;

void initStack(STACK s){
    s->top = -1;
}

int isFull(STACK s){
    return s->top == MAX - 1;
}
int isEmpty(STACK s){
    return s->top == -1;
}

void Push(STACK s, int data){
    if(isFull(s)){
        printf("Stack Overflow\n");
        return;
    }
    s->arr[++(s->top)] = data;
    printf("Pushed: %d\n", data);
}

int Pop(STACK s){
    if(isEmpty(s)){
        printf("Stack Underflow\n");
        return -1; // Return -1 to indicate stack is empty
    }
    return s->arr[(s->top)--];
}

int peek(STACK s){
    if(isEmpty(s)){
        printf("Stack is empty\n");
        return -1; // Return -1 to indicate stack is empty
    }
    return s->arr[s->top];
}

typedef struct MinStack {
    STACK mainStack;
    STACK minStack;
} *MINSTACK;

void initMinStack(MINSTACK ms) {
    ms->mainStack = (STACK)malloc(sizeof(struct Stack));
    ms->minStack = (STACK)malloc(sizeof(struct Stack));
    initStack(ms->mainStack);
    initStack(ms->minStack);
}
void pushMinStack(MINSTACK ms, int data){
    if(isFull(ms->mainStack)){
        printf("Main Stack Overflow\n");
        return;
    }
    Push(ms->mainStack, data);
    if(isEmpty(ms->minStack) || data <= peek(ms->minStack)){
        Push(ms->minStack, data);
    }
}

int popMinStack(MINSTACK ms){
    if(isEmpty(ms->mainStack)){
        printf("Stack Underflow\n");
        return -1; // Return -1 to indicate stack is empty
    }
    int poppedValue = Pop(ms->mainStack);
    if(poppedValue == peek(ms->minStack)){
        Pop(ms->minStack);
    }
    return poppedValue;
}

int main()
{
    MINSTACK ms = (MINSTACK)malloc(sizeof(struct MinStack));
    initMinStack(ms);

    pushMinStack(ms, 5);
    pushMinStack(ms, 3);
    pushMinStack(ms, 7);
    pushMinStack(ms, 2);

    printf("Current Min: %d\n", peek(ms->minStack)); // Should print 2

    popMinStack(ms);
    printf("Current Min after popping: %d\n", peek(ms->minStack)); // Should print 3

    popMinStack(ms);
    printf("Current Min after popping: %d\n", peek(ms->minStack)); // Should print 3

    return 0;
}

