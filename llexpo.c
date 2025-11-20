#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int coeff;
    int pow;
    struct Node* next;

} *Node;

Node create_Node(int c,int p)
{
    Node newNode = (Node)malloc(sizeof(struct Node));
    if(!newNode){
        printf("Memory Error\n");
        return NULL;
    }
    newNode->coeff = c;
    newNode->pow = p;
    newNode->next = NULL;
    return newNode;
}



int main()
{
    //list1👉
    Node poly1 = create_Node(5,2);
    poly1->next = create_Node(4,1);
    poly1->next->next = create_Node(2,0);

    //list2👉
    Node poly2 = create_Node(3,2);
    poly2->next = create_Node(2,0);

    return 0;
}