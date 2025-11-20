#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node  *rlink,*llink;
}*Node;

Node Initilize(int data)
{
    Node newNode = (Node)malloc(sizeof(struct node));
    if(newNode == NULL) return NULL;

    newNode->data = data;
    newNode->llink = newNode->rlink = NULL;

    return newNode;
}

Node InsFront(Node head,int data)
{   
    Node newNode = Initilize(data);
    if(head == NULL){
        head = newNode;
        return head;
    }

    newNode->rlink = head;
    head->llink = newNode;
    head = newNode;

    return head;
}

Node InsPos(Node head,int data,int pos)
{
    Node newNode = Initilize(data);
    if(head == NULL || pos < 1)
    {
        newNode->rlink = head;
        head->llink = newNode;
        return newNode;
    }

    int i = 1;
    Node temp = head;
    while (temp->rlink!=NULL && i< pos-1)
    {
        temp = temp->rlink;
        i++;
    }

    newNode->rlink = temp->rlink;
    newNode->llink = temp;
    if(temp->rlink != NULL)
        temp->rlink->llink = newNode;
    temp->rlink = newNode;
    
    return head;
}

Node InsEnd(Node head, int data)
{
    Node newNode = Initilize(data);

    if(head == NULL) return newNode;

    Node temp = head;
    while(temp->rlink != NULL)
    {
        temp = temp->rlink;
    }

    temp->rlink = newNode;
    newNode->llink = temp;

    return head;

}

void Display(Node head)
{
    if(head == NULL) printf("NULL \n");

    Node temp = head;
    
    while(temp!=NULL)
    {
        printf("%d <-> ",temp->data);
        temp=temp->rlink;
    }
    printf("NULL \n");
}

Node DelFont(Node head)
{
    if (head == NULL) return head;

    if(head->rlink == NULL) return NULL;

    Node temp = head;
    head = head->rlink;
    head->llink = NULL;
    free(temp);

    return head;

}

Node DelEnd(Node head)
{
    if(head == NULL) return head;
    Node temp = head;
    while(temp->rlink!=NULL)
    {
        temp=temp->rlink;
    }

    temp->llink->rlink = NULL;
    free(temp);

    return head;
}

Node InsOrd(Node head, int data)
{
    Node newNode = Initilize(data);
    if(head == NULL || head->data > data)
    {
        newNode->rlink = head;
        if(head != NULL )
            head->llink = newNode;
        
        return newNode;
    }
    Node temp = head;
    while(temp->rlink != NULL && temp->rlink->data < data)
    {
        temp=temp->rlink;
    }

    newNode->rlink = temp->rlink;
    newNode->llink = temp;
    if(temp->rlink != NULL)
        temp->rlink->llink = newNode;
    temp->rlink = newNode;

    return head;

}

Node Sort(Node head)
{
    if(head==NULL) return NULL;
    Node sorted = NULL;
    int data;
    while(head!=NULL)
    {
         data = head->data;
        head = DelFont(head);
        sorted = InsOrd(sorted, data);
    }
    return sorted;
}

int main()
{
    Node head = Initilize(4);
    head = InsFront(head,3);
    head  = InsPos(head,2,2);
   head = InsEnd(head,8);
   //head = DelFont(head);
  // head = DelEnd(head);
   head = InsOrd(head,3);
    Display(head);

    head = Sort(head);
    Display(head);

    return 0;
}
