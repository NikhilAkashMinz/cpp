#include<stdio.h>
#include<stdlib.h>


typedef struct node{
    int data;
    struct node *lptr, *rptr;

}*NODE;

NODE CreateNode(int data)
{
    NODE newNode = (NODE)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->rptr=newNode->lptr = NULL;
    return newNode;
}

void Display(NODE head)
{
    if(head == NULL)
        return;
    printf("[%d]<->", head->data);
    Display(head->rptr);
}

NODE insertFront(NODE head, int data)
{
    if(head == NULL)
        return CreateNode(data);
    NODE newNode = CreateNode(data);
    newNode->rptr = head;
    head->lptr = newNode;
    return newNode;
}

NODE insertAtPosition(NODE head, int data, int pos)
{
    if(pos <= 1 || head == NULL)
        return insertFront(head, data);
    
    NODE temp = head;
    for(int i = 1; i < pos-1 && temp->rptr != NULL; i++)
        temp = temp->rptr;
    NODE newNode = CreateNode(data);
    newNode->rptr = temp->rptr;
    newNode->lptr = temp;   
    temp->rptr = newNode;
    temp = newNode->rptr;
    temp->lptr = newNode;
    return head;
}

NODE Delete_First(NODE head)
{
    NODE temp;
    if(head == NULL)
        return NULL;
    if(head->rptr == NULL)
    {
        free(head);
        return NULL;
    }

    temp = head;
    head = head->rptr;
    head->lptr = NULL;
    free(temp);
    return head;
}

NODE Delete_Last(NODE head)
{
    NODE temp;
    if(head == NULL)
        return NULL;
    if(head->rptr == NULL)
    {
        free(head);
        return NULL;
    }

    temp = head;
    while(temp->rptr != NULL)
        temp = temp->rptr;
    
    temp->lptr->rptr = NULL;
    free(temp);
    return head;
}

void Delete_At_position(NODE head, int pos)
{
    if(head == NULL)
        return;
    if(pos <= 1)
    {
        head = Delete_First(head);
        return;
    }
    NODE temp = head;
    for(int i = 1; i < pos && temp != NULL; i++)
        temp = temp->rptr;
    
    if(temp->rptr != NULL)
        temp->rptr->lptr = temp->lptr;
    
    if(temp->lptr != NULL)
        temp->lptr->rptr = temp->rptr;
    
    free(temp);
}

int main()
{
    NODE head = NULL;
    head = insertFront(head, 10);
    head = insertFront(head, 20);
    head = insertFront(head, 30);
    head = insertAtPosition(head, 40, 2);
    Display(head);
    printf("\n");
    head = Delete_First(head);
    Display(head);
    printf("\n");
    head = Delete_Last(head);
    Display(head);
    printf("\n");
    Delete_At_position(head, 2);
    Display(head);
    return 0;
}