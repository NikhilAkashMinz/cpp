#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void UpHeapify(int heap[], int index) {
    int parent = (index - 1) / 2;
    while(index > 0 && heap[parent] < heap[index]) {
        swap(&heap[parent], &heap[index]);
        index = parent;
        parent = (index - 1) / 2;
    }
}

void Insert(int heap[], int *size, int value) {
    heap[*size] = value;
    UpHeapify(heap, *size);
    (*size)++;
}

void PrintHeap(int heap[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}
void DownHeapify(int heap[], int size, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if(left< size && heap[left]>heap[largest]) {
        largest = left;
    }

    if(right < size && heap[right]>heap[largest]) {
        largest = right;
    }

    if(largest != index) {
        swap(&heap[largest], &heap[index]);
        DownHeapify(heap, size, largest);
    }
}

int main() {
    int heap[100];
    int size = 0;

    Insert(heap, &size, 10);
    Insert(heap, &size, 20);
    Insert(heap, &size, 5);
    Insert(heap, &size, 30);

    PrintHeap(heap, size);

    return 0;
}