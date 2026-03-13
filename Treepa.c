#include<stdio.h>
#include<stdlib.h>

void Insert(int tree[],int *size,int val)
{
    tree[(*size)++]=val;
}

void Display(int tree[],int size)
{
    if (size==0)
    {
        printf("Tree is empty\n");
        return;
    }

    for(int i=0;i<size;i++)
        printf("%d ",tree[i]);
    printf("\n");
}

int parent(int idx)
{
    return (idx-1)/2;
}
int leftChild(int idx)
{
    return 2*idx+1;
}
int rightChild(int idx)
{
    return 2*idx+2;
}

void displayRelation(int tree[],int size,int idx)
{
    if(idx<0 || idx>=size)
    {
        printf("Invalid index\n");
        return;
    }

    printf("NODE at index %d: %d\n",idx,tree[idx]);

    if(idx >0)
    {
        printf("parent: %d\n",tree[parent(idx)]);
    }
    if(leftChild(idx)<size)
    {
        printf("left child: %d\n",tree[leftChild(idx)]);
    }
    if(rightChild(idx)<size)
    {
        printf("right child: %d\n",tree[rightChild(idx)]);
    }
}   

int main()
{
    int tree[100];
    int size=0;

    Insert(tree,&size,10);
    Insert(tree,&size,20);
    Insert(tree,&size,30);
    Insert(tree,&size,40);
    Insert(tree,&size,50);

    Display(tree,size);

    displayRelation(tree,size,1); // Display relations for node at index 1
    displayRelation(tree,size,0); // Display relations for node at index 0

    return 0;
}