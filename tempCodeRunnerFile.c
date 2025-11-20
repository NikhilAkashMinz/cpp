#include<stdio.h>
#include<stdlib.h>

#define Max  10

typedef struct stack{
    int stk[Max];
    int Top;
}*Stack;

int IsFull(Stack myStack){
    return ((myStack->Top)==Max-1) ? 1 : 0;
}

int IsEmpty(Stack myStack){
    return ((myStack->Top)== -1) ? 1:0;
}

void Push(Stack myStack){
    int element;
    if(IsFull(myStack))
    {
        printf("stack is full \n");
    }
    else{
         printf("Enter element: \n");
         scanf("%d",&element);
         myStack->stk[++(myStack->Top)] = element;
    }
}

void Pop(Stack myStack)
{
    if(IsEmpty(myStack))
    {
        printf("Stack is empty");
    }
    else{
        myStack->stk[myStack->Top--];
    }
}

void Peek(Stack myStack )
{
    printf("%d",myStack->stk[myStack->Top]);
}
void Display(Stack myStack)
{
    if(IsEmpty(myStack)){
        printf("Stack is Empty");
    }
    else
    {
        for(int i = myStack->Top;i>= 0;i--)
        {
            printf("%d |" , myStack->stk[i]);
        }
        printf("\n");
    }

}




int main()
{
    Stack myStack = (Stack)malloc(sizeof(struct stack));
    myStack->Top = -1;

    Push(myStack);
    Push(myStack);
    Push(myStack);
    Push(myStack);
    Push(myStack);
    Display(myStack);
    Pop(myStack);
    Display(myStack);
    return 0;
}