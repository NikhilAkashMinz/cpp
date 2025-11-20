#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}*Node;

Node Initilize(int data)
{
    Node newNode = (Node)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = newNode;
    
    return newNode;
}

Node LastNode(Node head)
{
    Node temp = head;
    while(temp->next != head)
    {
        temp = temp->next;

    }

    return temp;
}



Node InsFront(Node head,int data)
{
    Node newNode = Initilize(data);
    if(head == NULL) 
    {
        newNode->next = newNode;
        return newNode;
    }
    LastNode(head)->next =  newNode;
    newNode->next = head;
    head = newNode;
    return head;
}

Node InsEnd(Node head,int data)
{
    Node newNode = Initilize(data);
    if(head == NULL)
    {
        newNode->next = newNode;
        return newNode;
    }
    LastNode(head)->next =  newNode;
    newNode->next = head;
    return head;
}

Node DelFont(Node head)
{
    if(head==NULL) return head;
    if(head->next == head)
    {
        free(head);
        return NULL;
    }
    Node temp = head;

    LastNode(head)->next = temp->next;
    head = temp->next;
    free(temp);

    return head;
}

Node DelEnd(Node head)
{
    Node temp= head;
    if (head == NULL) return head;

    while(temp->next->next != head)
    {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = head;

    return head;
}

void Display(Node head)
{
    if(head == NULL){
        printf("NULL");
        return ;
    }
    Node temp = head;
    while(temp->next != head)
    {
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("%d -> %d\n",temp->data,head->data);
}



int main()
{

    Node head = Initilize(1);
    head = InsFront(head,2);
    head = InsFront(head,3);
    head = InsFront(head,4);
    head = InsFront(head,5);
    head = InsEnd(head,6);
    head = InsEnd(head,7);
    head = InsEnd(head,8);
    head = InsEnd(head,9);
    Display(head);
    
    return 0;
}