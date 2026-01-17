#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct Node{
    char data;
    struct Node *left,*right;
}*NODE;

typedef struct Stack{
    NODE data;
    struct Stack *next;
}*STACK;

NODE createNode(char data)
{
    NODE newNode = (NODE)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left=newNode->right=NULL;
    return newNode;

}

STACK pushStack(STACK top, NODE node)
{
    STACK newStack = (STACK)malloc(sizeof(struct Stack));
    newStack->data = node;
    newStack->next = top;
    return newStack;
}

STACK pop(STACK top,NODE *poppedNode)
{
    if(top==NULL) return NULL;
    *poppedNode = top->data;
    STACK temp = top;
    top=top->next;
    free(temp);
    return top;
}

NODE buildExpTree(char postfix[])
{
    STACK stack = NULL;
    for(int i=0;postfix[i] != '\0';i++)
    {
        if(isdigit(postfix[i]))
            stack = pushStack(stack,createNode(postfix[i]));
        else{
            NODE right , left;
            stack = pop(stack,&right);
            stack = pop(stack,&left);
            NODE newNode = createNode(postfix[i]);
            newNode->right = right;
            newNode->left = left;
            stack= pushStack(stack, newNode);
        }
    }

    NODE root;
    stack = pop(stack,&root);
    return root;
}

void inorder(NODE root)
{
    if(root == NULL) return;

    inorder(root->left);
    printf("%c", root->data);
    inorder(root->right);
}


int main()
{

    char postfix[] = "34+52-*";
    NODE root = buildExpTree(postfix);
    inorder(root);
    return 0;
}