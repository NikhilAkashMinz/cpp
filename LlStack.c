#include <stdio.h>
#include <stdlib.h>


typedef struct myNode{
    int data;
    struct myNode* next;
}* Node;


Node Initialize(int data)
{
    Node newNode = (Node)malloc(sizeof(struct myNode));

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

int isEmpty(Node t)
{
    return t==NULL;
}

Node Push(Node T,int val)
{
    Node newNode = Initialize(val);
    newNode->next = T;

    T = newNode;

    return T;
}

int del()




int main()
{

    return 0;
}
