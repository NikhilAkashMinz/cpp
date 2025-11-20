#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* link;
}*Node;

Node Initilize(int data)
{
    Node newNode = (Node)malloc(sizeof(Node));
    newNode->data = data;
    newNode->link = NULL;

    return newNode;
}

Node Ins_Font(Node head,int data)
{
    Node newNode = (Node)malloc(sizeof(Node));
    newNode->data = data;
    newNode->link = NULL;
    if(head == NULL) return newNode;
    
    newNode->link = head;
    head = newNode;
    return head;
}

Node Ins_End(Node head, int data)
{
    Node newNode = Initilize(data);

    if(head == NULL)
    {
        head = newNode;
        return head;
    }

    Node temp = head;
    while(temp->link!=NULL)
    {
        temp=temp->link;
    }
    temp->link = newNode;

    return head;
}

Node Ins_pos(Node head, int data, int pos)
{
    Node temp = head; Node newNode = Initilize(data);
    if(head == NULL || pos == 0)
    {
        newNode->link = head;
        head = newNode;
        return head;
    }

    while(temp!=NULL &&  pos > 1)
    {
        temp = temp->link;
        pos--;
    }

    if(temp == NULL) return head;

    newNode->link = temp->link;
    temp->link = newNode;

    return head;
}

Node Ins_order(Node head,int data)
{
    Node newNode = Initilize(data);

    if(head == NULL || head->data > data)
    {
        newNode->link = head;
        return newNode;
    }
    Node temp = head;
    while(temp->link != NULL && temp->link->data < data)
    {
        temp=temp->link;
    }

    newNode->link = temp->link;
    temp->link = newNode;

    return head;

}

Node Delete_front(Node head)
{
    if(head == NULL) return NULL;
    Node temp = head;
    head = head->link;
    free(temp);
    
    return head;

}

Node Delete_End(Node head)
{
    Node temp = head;

    while(temp->link->link != NULL)
    {
        temp = temp->link;
    }

    free(temp->link->link);
    temp->link = NULL;
    return head;
}

Node revers(Node head)
{
    int data = 0;
    Node newNode = NULL;
    while(head!=NULL)
    {
        data = head->data;
        head = Delete_front(head);
        newNode = Ins_Font(newNode,data);
    }
    return newNode;
}

Node sorted(Node head)
{
    int data;
    Node newNode = NULL;
    while(head!=NULL)
    {
        data=head->data;
        head = Delete_front(head);
        newNode = Ins_order(newNode,data);
    }
    return newNode;
}

void Display(Node head)
{
    Node temp = head;
    while(temp!=NULL)
    {
        printf("%d ->",temp->data);
        temp=temp->link;
    }
    printf("NULL \n");
}

int main()
{
    printf("Insert_Front\n");
   Node head = Initilize(1);
   head = Ins_Font(head,2);
   head = Ins_Font(head,3);
   head = Ins_Font(head,4);
   head = Ins_Font(head,5);
   Display(head);
   printf("Insert_End\n");
   head = Ins_End(head,6);
   head = Ins_End(head,7);
   head = Ins_End(head,8);
   head = Ins_End(head,9);
   head = Ins_End(head,10);
   Display(head);
   printf("Inseart by position \n");
   head = Ins_pos(head,8,3);
   Display(head);

   printf("Inorder_Ins\n");
   head = Ins_order(head,7);
   Display(head);
   head = Delete_front(head);
   Display(head);
   head = Delete_End(head);
   Display(head);

    printf("Reverse List\n");
   head = revers(head);
   Display(head);

   printf("Sorted \n");
   head = sorted(head);
   Display(head);

   


   return 0;
}