#include<stdio.h>
#include<stdlib.h>

#define MAX 100

int parent(int index)
{
    return (index -1)/2;
}

int leftChild(int index)
{
    return 2* index +1;
}

int rightChild(int index)
{
    return 2 * index +2;
}

void insert(int tree[],int *size, int value)
{
    if(*size >= MAX)
    {
        printf("Tree is full!\n");
        return;
    }

    tree[(*size)++] = value;
}

void Display(int tree[],int size)
{
    if(size == 0)
    {
        printf("Tree is empty! \n");
        return;
    }
    printf("Bt level order: ");
    for(int i = 0; i< size; i++)
    {
        printf("%d", tree[i]);
    }
    printf("\n");
}

void DisplayNode(int tree[], int size, int index){
    if(index < 0 || index >= size)
    {
        printf("Invalid \n");
        return;
    }

    printf("Node at index %d: %d\n", index, tree[index]);

    if (index > 0)
        printf("Parent: %d\n", tree[parent(index)]);

    if (leftChild(index) < size)
        printf("Left Child: %d\n", tree[leftChild(index)]);

    if (rightChild(index) < size)
        printf("Right Child: %d\n", tree[rightChild(index)]);

}

int main() {
    int tree[MAX];
    int size = 0;
    int choice, value, index;

    while (1) {
        printf("\n--- Binary Tree Menu ---\n");
        printf("1. Insert\n");
        printf("2. Display Tree\n");
        printf("3. Display Node Relations\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            insert(tree, &size, value);
            break;

        case 2:
            Display(tree, size);
            break;

        case 3:
            printf("Enter index: ");
            scanf("%d", &index);
            DisplayNode(tree, size, index);
            break;

        case 4:
            return 0;

        default:
            printf("Invalid choice!\n");
        }
    }
}