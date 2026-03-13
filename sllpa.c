#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
} *NODE;

void Display(NODE head)
{
    NODE temp = head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

NODE createNode(int val)
{
    NODE newNode = (NODE)malloc(sizeof(struct Node));
   
    if(newNode==NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }

    newNode->data = val;
    newNode->next = NULL;   

    return newNode;
}

NODE insertAtEnd(NODE head,int val)
{
    NODE newNode = createNode(val);
    if(head == NULL)
        return newNode;
    
    NODE temp = head;
    while(temp->next!=NULL)
        temp = temp->next;
    temp->next = newNode;
    return head;
}

NODE insertAtBeginning(NODE head,int val)
{
    NODE newNode = createNode(val);
    newNode->next = head;
    return newNode;
}

NODE deleteAtFront(NODE head, int k)
{
    if (head == NULL)
        return head;

    if(head->data == k)
    {
        NODE temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    NODE current = head;
    while(current->next!=NULL && current->next->data != k)
        current = current->next;

    if(current->next!=NULL)
    {
        NODE temp = current->next;
        current->next = current->next->next;
        free(temp);
    }
    return head;
}

NODE deleteAtKey(NODE head, int k)
{
    if (head == NULL)
        return head;

    if(head->data == k && head->next == NULL)
    {
        free(head);
        return NULL;
    }

    NODE current = head;
    while(current->next!=NULL && current->next->data != k)
        current = current->next;

    if(current->next!=NULL)
    {
        NODE temp = current->next;
        current->next = current->next->next;
        free(temp);
    }
    return head;
}

void insertAtPosition(NODE head, int val, int pos)
{
    NODE newNode = createNode(val);
    if(pos == 1)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    NODE temp = head;
    for(int i=1; i<pos-1 && temp!=NULL; i++)
        temp = temp->next;

    if(temp == NULL)
    {
        printf("Position out of bounds\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

NODE insert_ordered(NODE head, int val)
{
    NODE newNode = createNode(val);
    if(head == NULL || head->data >= val)
    {
        newNode->next = head;
        return newNode;
    }

    NODE temp = head;
    while(temp->next!=NULL && temp->next->data < val)
        temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}