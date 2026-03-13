// #include<stdio.h>
// #include<stdlib.h>

// typedef struct MyStackADT{
//     int *arr;
//     int top;
//     int capacity;
// } *Stack;


// void Display(Stack myStack)
// {
//     if(myStack->top == -1)
//     {
//         printf("\n\t\t Stack is Empty !!! Underflow Condition ");
//         return;
//     }
//     printf("\n\t\t Stack Elements are : ");
//     for(int i = myStack->top; i >= 0; i--)
//     {
//         printf("%d ", myStack->arr[i]);
//     }
// }
// Stack CreateStack(int capacity)
// {
//     Stack newStack = (Stack)malloc(sizeof(struct MyStackADT));

//     if(newStack == NULL)
//     {
//         printf("\n\t\t Insufficient Memory !!! Exitinf ");
//         exit(EXIT_FAILURE);
//     }
//     newStack->arr = (int *)malloc(capacity * sizeof(int));
//     if(newStack->arr == NULL)
//     {
//         printf("\n\t\t Insufficient Memory !!! Exitinf ");
//         exit(EXIT_FAILURE);
//     }
//     newStack->top = -1;
//     newStack->capacity = capacity;
//     return newStack;
// }

// int Do_Resize(Stack MyStack, int new_cap)
// {
//     int newSize = MyStack->capacity + new_cap;
//     int *newArr = (int *)realloc(MyStack->arr, newSize * sizeof(int));
//     if(newArr == NULL)
//     {
//         printf("\n\t\t Insufficient Memory !!! Exitinf ");
//         exit(EXIT_FAILURE);
//     }

//     MyStack->capacity = newSize;
//     MyStack->arr = newArr;
//     return 1;
// }

// void Push(Stack myStack, int data)
// {
//     int element,status;
//     //printf("\n\t\t Enter the element to be pushed : ");
//     //scanf("%d", &element);
//     status =(myStack->top == myStack->capacity - 1) ? Do_Resize(myStack, 5) : 1;
//     if(status)
//     {
//         myStack->arr[++(myStack->top)] = data;
//         printf("\n\t\t [%d] Element Pushed Successfully !!!",data);
//     }
// }

// void pop(Stack myStack)
// {
//     int ele,status;
//     if(myStack->top == -1)
//     {
//         printf("\n\t\t Stack is Empty !!! Underflow Condition ");
//         return;
//     }
//     ele = myStack->arr[(myStack->top)--];
//     printf("\n\t\t Popped Element is : %d", ele);
//     status = Do_Resize(myStack, -1);
//     Display(myStack);
// }


// int peek(Stack myStack)
// {
//     if(myStack->top == -1)
//     {
//         printf("\n\t\t Stack is Empty !!! Underflow Condition ");
//         return -1;
//     }
//     return myStack->arr[myStack->top];
// }

// void DestroyStack(Stack myStack)
// {
//     free(myStack->arr);
//     free(myStack);
//     printf("\n\t\t Stack Destroyed Successfully !!!");
// }

// int main()
// {
//     Stack myStack = CreateStack(5);
//     Push(myStack, 10);
//     Push(myStack, 20);
//     Push(myStack, 30);
//     Display(myStack);
//     printf("\n\t\t Peeked Element is : %d", peek(myStack));
//     pop(myStack);
//     DestroyStack(myStack);
// }
#include <stdio.h>
#include <stdlib.h>

/* Node structure */
typedef struct Node {
    int data;
    struct Node *next;
} Node;

/* Stack structure */
typedef struct StackADT {
    Node *top;
} Stack;

/* Create Stack */
Stack* CreateStack() {
    Stack *s = (Stack*)malloc(sizeof(Stack));
    if(s == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    s->top = NULL;
    return s;
}

/* Check Empty */
int IsEmpty(Stack *s) {
    return (s->top == NULL);
}

/* Push operation */
void Push(Stack *s, int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL) {
        printf("Stack Overflow (Memory Full)\n");
        return;
    }

    newNode->data = data;
    newNode->next = s->top;
    s->top = newNode;

    printf("Pushed: %d\n", data);
}

/* Pop operation */
void Pop(Stack *s) {
    if(IsEmpty(s)) {
        printf("Stack Underflow\n");
        return;
    }

    Node *temp = s->top;
    printf("Popped: %d\n", temp->data);

    s->top = temp->next;
    free(temp);
}

/* Peek operation */
int Peek(Stack *s) {
    if(IsEmpty(s)) {
        printf("Stack is Empty\n");
        return -1;
    }
    return s->top->data;
}

/* Display Stack */
void Display(Stack *s) {
    if(IsEmpty(s)) {
        printf("Stack is Empty\n");
        return;
    }

    Node *temp = s->top;
    printf("Stack elements: ");
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/* Destroy Stack */
void DestroyStack(Stack *s) {
    Node *temp;
    while(s->top != NULL) {
        temp = s->top;
        s->top = temp->next;
        free(temp);
    }
    free(s);
    printf("Stack destroyed successfully\n");
}

/* Main */
int main() {
    Stack *s = CreateStack();

    Push(s, 10);
    Push(s, 20);
    Push(s, 30);

    Display(s);

    printf("Peek: %d\n", Peek(s));

    Pop(s);
    Display(s);

    DestroyStack(s);
    return 0;
}
