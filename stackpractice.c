#include<stdio.h>
#include<stdlib.h>

#define MAX 10

typedef struct stackADT{
    int arr[MAX];
    int TOP;
} *Stack;

int IsFULL(Stack MyStack){
    return ((MyStack->TOP) == MAX-1) ? 1 : 0;
}

int IsEmpty(Stack MyStack){
    return ((MyStack->TOP) == -1) ? 1 : 0;
}

void Push(Stack MyStack, int data){
    if(IsFULL(MyStack)){
        printf("Stack is Full\n");
        return;
    }
    MyStack->arr[++(MyStack->TOP)] = data;
}

void Pop(Stack MyStack){
    if(IsEmpty(MyStack)){
        printf("Stack is Empty\n");
        return;
    }
    printf("Popped element: %d\n", MyStack->arr[(MyStack->TOP)--]);
}

void Display(Stack MyStack){
    if(IsEmpty(MyStack)){
        printf("Stack is Empty\n");
        return;
    }
    printf("Stack elements: ");
    for(int i = MyStack->TOP; i >= 0; i--)
        printf("%d ", MyStack->arr[i]);
    printf("\n");
}

int main(){
    Stack MyStack = (Stack)malloc(sizeof(struct stackADT));
    MyStack->TOP = -1;

    Push(MyStack, 10);
    Push(MyStack, 20);
    Push(MyStack, 30);
    Display(MyStack);

    Pop(MyStack);
    Display(MyStack);

    Pop(MyStack);
    Pop(MyStack);
    Pop(MyStack); // Attempt to pop from empty stack

    free(MyStack);
    return 0;
}
