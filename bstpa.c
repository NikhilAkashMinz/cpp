#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
} *NODE;

NODE FindLargest(NODE root)
{
    while(root->right!=NULL)
        root=root->right;
    return root;
}

NODE createNode(int val)
{
    NODE newNode = (NODE)malloc(sizeof(struct Node));
   
    if(newNode==NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }

    newNode->data = val;
    newNode->left = NULL;   
    newNode->right = NULL;

    return newNode;
}

NODE insert(NODE root,int val)
{
    if(root == NULL)
        return createNode(val);
    if(val < root->data)
        root->left = insert(root->left,val);
    else
        root->right = insert(root->right,val);
    return root;
}

void inOrder(NODE root)
{
    if(root==NULL)
        return;
    inOrder(root->left);
    printf("%d ",root->data);
    inOrder(root->right);
}

NODE delete(NODE root, int k)
{
    if (root == NULL)
        return root;

    if(k < root->data)
        root->left = delete(root->left,k);
    else if(k > root->data)
        root->right  = delete(root->right,k);
    else{
        if(root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        if(root->left == NULL)
        {
            NODE temp = root->right;
            root = root->right;
            free(temp);
        }
        else if(root->right == NULL)
        {
            NODE temp = root->left;
            root = root->left;
            free(temp);
        }
        else{
            NODE temp = FindLargest(root->left);
            root->data = temp->data;
            root->left = delete(root->left,temp->data);

        }
    }
    return root;
}


int main()
{
    NODE root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    // Display the tree (in-order traversal)
    printf("In-order Traversal: ");
    inOrder(root);
    printf("\n");

    delete(root, 60);
    printf("In-order Traversal after deletion: ");
    inOrder(root);
    printf("\n");

    return 0;
}