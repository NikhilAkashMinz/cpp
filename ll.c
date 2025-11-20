#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* link;
}*Node;

Node Initilize(int data)
{
    Node newNode = (Node)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Unable to create Node\n");
        exit(1);
    }

    newNode->data = data;
    newNode->link = NULL;
    return newNode;
}

Node insert_end(Node head,int data)
{   
    Node newNode = (Node)malloc(sizeof(struct Node));
    newNode->data = data;
    Node temp = head;
    if(head == NULL)
    {
        head = newNode;
        newNode->link = NULL;
        return head;
    }

    while(temp->link != NULL)
    {
        temp = temp->link;
    }

    temp->link = newNode;
    newNode->link = NULL;
    return head;
}

Node Insert_front(Node head, int data)
{
    Node newNode = (Node)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->link = head;   // ✅ Point new node to old head
    return newNode;         // ✅ Return new head
}


Node Delete_front(Node head)
{
    if(head == NULL)
    {
        printf("list is empty");
        return NULL;
    }

    Node temp = head;
    printf("Deleted from front:%d \n", temp->data);
    head = head->link;
    free(temp);

    return head;
}

Node Delete_End(Node head)
{
    if(head == NULL)
        return NULL;
    if (head->link == NULL) {
        printf("Deleted from end: %d\n", head->data);
        free(head);
        return NULL;
    }


    Node temp = head;
    while(temp->link->link != NULL)
    {
        temp = temp->link;
    }

    printf("Deleted from end: %d\n", temp->link->data);
    free(temp->link);
    temp->link = NULL;
    return head;
}

Node Search(Node head,int data)
{
    if(head == NULL) return NULL;
    Node temp =  head;

    while(temp!=NULL)
    {
        if(temp->data == data)
        {
            printf("the element is found %d \n");
            return temp;
        }
        temp = temp->link;
    }
    printf("element not found\n");
    return NULL;
}

Node Insert_at_position(Node head,int pos,int data)
{
    if(pos<1) return head;
    Node newNode = malloc(sizeof(Node));
    newNode->data = data;
    if(pos == 1 )
    {
        newNode->link = head;
        return newNode;
    }

    Node temp = head;
    for (int i = 1; temp != NULL && i < pos - 1; i++)
        temp = temp->link;         // ✅ Move to node before position

    if (temp == NULL) {            // ✅ Out of bounds
        printf("Position out of range\n");
        free(newNode);
        return head;
    }

    newNode->link = temp->link;
    temp->link = newNode;

    return head;

}

Node Insert_by_search(Node head,int data,int val)
{
    if(head == NULL) return NULL;
    Node newNode = (Node)malloc(sizeof(struct Node));
    newNode->data = data;
    Node temp=head;
    while(temp != NULL && temp->data != val)
    {
        temp=temp->link;
    }

    if(temp->link == NULL) return head;
    newNode->link = temp->link;
    temp->link = newNode;

    return head;
    
}

Node reverse(Node head)
{
    Node prev = NULL;
    Node curr = head;
    Node next = NULL;

    while (curr != NULL)  // ✅ loop until we reach the end
    {
        next = curr->link;  // ✅ store next node
        curr->link = prev;  // ✅ reverse the link
        prev = curr;        // ✅ move prev ahead
        curr = next;        // ✅ move curr ahead
    }
    return prev;
}
Node reverse2(Node head)
{
    if(head == NULL) return NULL;
    Node newHead = NULL;
    int data;
    while(head!=NULL)
    {
        data = head->data;

        head = Delete_front(head);
        newHead = Insert_front(newHead, data);
    }
    return newHead;
}

Node Insert_inorder(Node head,int data)
{
    //printf("function called");
    Node newNode = (Node)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->link = NULL;
    if(head == NULL || data < head->data){
        newNode->link = head;
        return newNode;
    }
    else{
        Node temp = head;
        while(temp->link!=NULL && temp->link->data < data)
        {
            temp=temp->link;
        }
        newNode->link = temp->link;
        temp->link=newNode;
    }
    return head;
}

Node sorted(Node head)
{
    Node sorted=NULL;
    int data;
    while (head!=NULL)
    {
        data = head->data;
        head = Delete_front(head);
        sorted = Insert_inorder(sorted,data);
    }

    return sorted;
}


void Display(Node head)
{
    Node temp = head;
    while(temp!=NULL)
    {
        printf("%d -> ",temp->data);
        temp=temp->link;
    }
    printf("NULL\n");
}

Node mergeRec(Node head, Node head2)
{
    if(head == NULL) return head2;
    if(head2 == NULL) return head;

    if(head->data < head2->data)
    {
        head->link = mergeRec(head->link,head2);
        return head;
    }
    else
    {
        head2->link=mergeRec(head,head2->link);
        return head2;
    }
}

Node merge(Node head,Node head2)
{
    if(head == NULL) return head2;
    if(head2 == NULL) return head;
    int data;
    while(head2 != NULL)
    {
        data = head2->data;
        head2 = Delete_front(head2);
        head = Insert_inorder(head,data);
    }

    return head;
}

Void DelFont(head)
{
    
}


int main()
{
    Node head = Initilize(1);
    Node head2 = Initilize(1);
    head = Insert_front(head, 2);
    head = Insert_front(head, 3);
    head = Insert_front(head, 4);
    head = Insert_front(head, 5);
    head = Insert_front(head, 6);
    head = Insert_front(head, 7);
    head = Insert_front(head, 8);
    head = Insert_front(head, 9);

    head = insert_end(head, 3);
    head = insert_end(head, 4);
    head = insert_end(head, 5);
    head = insert_end(head, 6);
    head = insert_end(head, 7);
    head = insert_end(head, 8);
    head = insert_end(head, 9);
    head = insert_end(head, 0);
   

    //2ND lIST

    head2 = insert_end(head2, 2);
    head2 = insert_end(head2, 3);
    head2 = insert_end(head2, 4);
    head2 = insert_end(head2, 5);
    head2 = insert_end(head2, 6);
    head2 = insert_end(head2, 7);
    head2 = insert_end(head2, 8);
    head2 = insert_end(head2, 9);
    head2 = insert_end(head2, 10);
    head2 = insert_end(head2, 11);
    head2 = insert_end(head2, 12);
    head2 = insert_end(head2, 13);
    head2 = insert_end(head2, 14);
    
    
    Display(head);
    Display(head2);
    head = sorted(head);
    Display(head);
    head = merge(head,head2);
    Display(head);

    return 0;
}
