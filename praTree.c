#include <stdio.h>
#include <stdlib.h>

#define MAX 100

/* Insert a value into the tree (level order) */
void insert(int arr[], int *size, int val)
{
    if (*size >= MAX)
    {
        printf("Tree is full\n");
        return;
    }
    arr[*size] = val;
    (*size)++;
}

/* Display tree in level order */
void Display(int arr[], int size)
{
    if (size == 0)
    {
        printf("Tree is empty\n");
        return;
    }

    printf("Binary Tree Level Order: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/* Helper functions */
int parent(int index)
{
    return (index - 1) / 2;
}

int leftChild(int index)
{
    return 2 * index + 1;
}

int rightChild(int index)
{
    return 2 * index + 2;
}

/* Display parent and children of a node */
void displayNodeRelations(int tree[], int size, int index)
{
    if (index < 0 || index >= size)
    {
        printf("Invalid index\n");
        return;
    }

    printf("Node: %d", tree[index]);

    if (index > 0)
        printf(", Parent: %d", tree[parent(index)]);

    if (leftChild(index) < size)
        printf(", Left Child: %d", tree[leftChild(index)]);

    if (rightChild(index) < size)
        printf(", Right Child: %d", tree[rightChild(index)]);

    printf("\n");
}

/* Main function */
int main()
{
    int tree[MAX];
    int size = 0;

    insert(tree, &size, 10);
    insert(tree, &size, 20);
    insert(tree, &size, 30);
    insert(tree, &size, 40);
    insert(tree, &size, 50);

    Display(tree, size);

    printf("\nNode relations:\n");
    for (int i = 0; i < size; i++)
    {
        displayNodeRelations(tree, size, i);
    }

    return 0;
}
