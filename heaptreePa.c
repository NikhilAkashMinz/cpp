#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void unheapify(int heap[],int idx)
{
    int parntIdx= (idx-1)/2;
    while(idx>0 && heap[parntIdx] < heap[idx])
    {
        swap(&heap[parntIdx],&heap[idx]);
        idx=parntIdx;
        parntIdx=(idx-1)/2;
    }
} 
void downheap(int heap[],int size,int idx)
{
    int largest = idx;
    int left = 2*idx + 1;
    int right = 2*idx + 2;

    if(left<size && heap[left]>heap[largest])
        largest=left;
    if(right<size && heap[right]>heap[largest])
        largest=right;
    if(largest!=idx)
    {
        swap(&heap[largest],&heap[idx]);
        downheap(heap,size,largest);
    }
}

void buildMaxHeap(int heap[],int size)
{
    for(int i=(size/2)-1;i>=0;i--)
        downheap(heap,size,i);
}

void insert(int heap[],int *size,int val)
{
    heap[*size]=val;
    unheapify(heap,*size);
    (*size)++;
}

void display(int heap[],int size)
{
    if(size==0)
    {
        printf("Heap is empty\n");
        return;
    }

    for(int i=0;i<size;i++)
        printf("%d ",heap[i]);
    printf("\n");
}

int main()
{
    int heap[100];
    int size=0;

    insert(heap,&size,10);
    insert(heap,&size,20);
    insert(heap,&size,5);
    insert(heap,&size,15);
    insert(heap,&size,30);
    display(heap,size);
    buildMaxHeap(heap,size);
    display(heap,size);



    return 0;
}