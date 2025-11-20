#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct stack{
    int *arr;
    int top;
    int cap;
}* Stack;

Stack creaCap(int capi)
{
    Stack newStack = (Stack)malloc(sizeof(struct stack));

    if(newStack == NULL) exit(1);

    newStack->arr = (int*)malloc(sizeof(int)* capi);

    if(newStack->arr == NULL ) exit(EXIT_FAILURE);

    newStack->top = -1;
    newStack->cap = capi;

    return newStack;
}

int Resize(Stack myStack,int dec)
{
    int newSize = myStack->cap+dec;
    if(newSize<=0) return 0;

    int *newArr = realloc(myStack->arr,sizeof(int)*newSize);

    if(newArr == NULL) return 0;
    myStack->cap = newSize;
    myStack->arr = newArr;

    return 1;
}

void Push(Stack myStack)
{
    int element,status;
    printf("Enter Element: ");
    scanf("%d", &element);

    status = (myStack->top == myStack->cap-1) ? Resize(myStack,1) : 1;

    if(!status){
        printf("Stack overFlow \n");
        return;
    }

    myStack->arr[++myStack->top] = element;
}

void Pop(Stack myStack)
{
    if (myStack->top == -1) {
        printf("Stack Underflow!\n");
        return;
    }

    int popped = myStack->arr[myStack->top--];
    printf("Popped: %d\n", popped);

    Resize(myStack, -1);
}

void Display(Stack myStack){
    if(myStack->top == -1) return;

    for(int i = myStack->top; i>=0;i--)
    {
        printf("|%d|",myStack->arr[i]);
    }
    printf("\n");
}
int Peek(Stack myStack){
    if(myStack->top == -1)
        return -1;

    return myStack->arr[myStack->top];
}

void Destroy(Stack myStack)
{
    free(myStack->arr);
    free(myStack);
}

int main()
{
      Stack myStack = creaCap(1);  // Initial size = 1

    int choice;

    while (1) {
        printf("\n\n----- MENU -----\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: Push(myStack); break;
            case 2: Pop(myStack); break;
            case 3: printf("\nTop element = %d\n", Peek(myStack)); break;
            case 4: Display(myStack); break;
            case 5: Destroy(myStack); exit(0);
            default: printf("\nInvalid Choice!\n");
        }
    }

    return 0;
}

