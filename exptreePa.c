#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Node{
    char data;
    struct Node *left;
    struct Node *right; 
} *NODE;

typedef struct Stack{
    NODE data;
    struct Stack *next;
} *STACK;

/* Create tree node */
NODE CreateNode(char ch)
{
    NODE newNode = (NODE)malloc(sizeof(struct Node));
    newNode->data = ch;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/* Push stack */
STACK push(STACK top, NODE node)
{
    STACK newStack = (STACK)malloc(sizeof(struct Stack));
    newStack->data = node;
    newStack->next = top;
    return newStack;   
}

/* Pop stack */
STACK pop(STACK top, NODE *popped)
{
    if(top == NULL) return NULL;

    *popped = top->data;
    STACK temp = top;
    top = top->next;
    free(temp);
    return top;
}

/* Build Expression Tree from Postfix */
NODE buildExpTree(char postfix[])
{
    STACK stack = NULL;

    for(int i = 0; postfix[i] != '\0'; i++)
    {
        if(isdigit(postfix[i]))
        {
            stack = push(stack, CreateNode(postfix[i]));
        }
        else
        {
            NODE right, left;
            stack = pop(stack, &right);
            stack = pop(stack, &left);

            NODE newNode = CreateNode(postfix[i]);
            newNode->left = left;
            newNode->right = right;

            stack = push(stack, newNode);
        }
    }

    NODE root;
    stack = pop(stack, &root);
    return root;
}

/* Inorder Traversal */
void inorder(NODE root)
{
    if(root)
    {
        inorder(root->left);
        printf("%c ", root->data);
        inorder(root->right);
    }
}

int main()
{
    char postfix[] = "35+52-*";
    NODE root = buildExpTree(postfix);

    printf("Inorder traversal: ");
    inorder(root);

    return 0;
}
