#include<stdio.h>
#include<stdlib.h>

#define Max 10

typedef struct stack {
    int stk[Max];
    int Top;
} *Stack;

typedef struct {
    Stack mainStack;
    Stack minStack;
} *MinStack;

/* Stack Functions */
Stack createStack() {
    Stack s = (Stack)malloc(sizeof(struct stack));
    s->Top = -1;
    return s;
}

int IsFull(Stack s) {
    return (s->Top == Max - 1);
}

int IsEmpty(Stack s) {
    return (s->Top == -1);
}

void Push(Stack s, int val) {
    if (IsFull(s)) {
        printf("Stack is full\n");
        return;
    }
    s->stk[++(s->Top)] = val;
}

int Pop(Stack s) {
    if (IsEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->stk[(s->Top)--];
}

int Peek(Stack s) {
    if (IsEmpty(s)) return -1;
    return s->stk[s->Top];
}

void Display(Stack s) {
    if (IsEmpty(s)) {
        printf("Stack is empty\n");
        return;
    }
    for (int i = s->Top; i >= 0; i--)
        printf("%d | ", s->stk[i]);
    printf("\n");
}

/* MinStack Functions */
MinStack createMinStack() {
    MinStack ms = (MinStack)malloc(sizeof(*ms));
    ms->mainStack = createStack();
    ms->minStack = createStack();
    return ms;
}

void pushMinStack(MinStack ms, int val) {
    Push(ms->mainStack, val);

    if (IsEmpty(ms->minStack) || val <= Peek(ms->minStack))
        Push(ms->minStack, val);
}

int popMinStack(MinStack ms) {
    int val = Pop(ms->mainStack);

    if (val == Peek(ms->minStack))
        Pop(ms->minStack);

    return val;
}

int getMin(MinStack ms) {
    return Peek(ms->minStack);
}

/* Main */
int main() {
    MinStack ms = createMinStack();

    pushMinStack(ms, 5);
    pushMinStack(ms, 3);
    pushMinStack(ms, 7);
    pushMinStack(ms, 2);
    pushMinStack(ms, 8);

    printf("Main stack: ");
    Display(ms->mainStack);

    printf("Min stack : ");
    Display(ms->minStack);

    printf("\nCurrent Min: %d\n", getMin(ms));

    printf("Popped: %d\n", popMinStack(ms));
    printf("New Min: %d\n", getMin(ms));

    return 0;
}
