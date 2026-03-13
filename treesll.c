#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} *NODE;

NODE createNode(int val)
{
    NODE newNode = (NODE)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

NODE insert(NODE root, int val)
{
    NODE newNode = createNode(val);

    if (root == NULL)
        return newNode;

    NODE queue[MAX];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear)
    {
        NODE temp = queue[front++];

        if (temp->left == NULL)
        {
            temp->left = newNode;
            return root;
        }
        else
            queue[rear++] = temp->left;

        if (temp->right == NULL)
        {
            temp->right = newNode;
            return root;
        }
        else
            queue[rear++] = temp->right;
    }
    return root;
}

/* Preorder DFS */
void dfs(NODE root)
{
    if (root == NULL)
        return;

    printf("%d ", root->data);
    dfs(root->left);
    dfs(root->right);
}

int main()
{
    NODE root = NULL;
    int val[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(val) / sizeof(val[0]);

    for (int i = 0; i < n; i++)
        root = insert(root, val[i]);

    printf("DFS Traversal: ");
    dfs(root);
    printf("\n");

    return 0;
}
