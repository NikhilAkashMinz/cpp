#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}*NODE;

typedef struct Stack{
    NODE data;
    struct Stack* next;
} *STACK;


NODE createNode(int data)
{
    NODE newNode = (NODE)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

STACK push(STACK top,NODE data)
{
    STACK newStack = (STACK)malloc(sizeof(struct Stack));
    newStack->data = data;
    newStack->next = top;
    return newStack;
}

STACK pop(STACK top, NODE* poped)
{
    if(top == NULL) return NULL;
    *poped = top->data;
    STACK temp = top;
    top=top->next;
    free(temp);
    return top;
}

NODE builExp(char postfix[])
{
    STACK stack = NULL;
    for(int i=0;postfix[i]!='\0';i++)
    {
        if(isdigit(postfix[i]))
        {
            stack = push(stack,createNode(postfix[i]));
        }
        else{
            NODE right,left;
            stack = pop(stack,&right);
            stack = pop(stack,&left);
            NODE newNode = createNode(postfix[i]);
            newNode->left = left;
            newNode->right = right;
            stack = push(stack,newNode);
        }
    }
    NODE root;
    stack = pop(stack,&root);
    return root;
}

void InOrder(NODE root)
{
    if(root == NULL) return;
    InOrder(root->left);
    printf("%c ",root->data);
    InOrder(root->right);
}

int main(){
    char postfix[] = "23+54*+9-";
    NODE root = builExp(postfix);
    InOrder(root);
    return 0;
}