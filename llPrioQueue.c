#include <stdio.h>
#include <stdlib.h>

typedef struct myNode{
    int element,priority;
    struct myNode* next;
}*Node;

Node Initilize(int element , int priority )
{
    Node temp = (Node)malloc(sizeof(struct myNode));
    temp->element = element;
    temp->priority = priority;
    temp->next = NULL;

    return temp;
}

int isEmpty(Node head)
{
    return head == NULL;
}

void Add(Node head,int ele,int prio)
{
    Node temp = Initilize(ele,prio);
    Node start = head;
    if(head == NULL && head->priority > prio)
    {
        temp->next = head;
        head=temp;
        return;
    }

    while(start->next != NULL && start->next->priority <= prio)
        start = start->next;

    temp->next = start->next;
    start->next = temp;
}

int Pop(Node head)
{
    if(head == NULL) return -1;
    Node temp = head;
    head=head->next;
    int pop = temp->element;
    free(temp);
    return pop;

}

int Peek(Node head)
{
    if(head == NULL)
    return -1;

    return head->element;
}

void Display(Node* head) {
    if (*head == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    Node temp = *head;
    printf("Priority Queue: [Element | Priority]\n");
    while (temp != NULL) {
        printf("%d | %d --> ", temp->element, temp->priority);
        temp = temp->next;
    }
    printf("NULL\n");
}


int main()
{

    Node pq = NULL;
    Add(pq,5,4);
    Add(pq,6,6);
    Add(pq,54,7);
    Add(pq,50,3);
    Add(pq,51,14);
    Display(pq);
    return 0;
}