#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* left,* right;
}*NODE;


NODE createNode(int data)
{
    NODE newNode = (NODE)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


NODE inserNode(NODE root,int data)
{
    
    if(root == NULL)
    {
        return createNode(data);
    }

    if(data < root->data)
    {
        root->left = inserNode(root->left,data);
    }
    else
    {
        root->right = inserNode (root->right,data);
    }
    return root;
}

void InOrder(NODE root)
{
    if(root == NULL) return;
    InOrder(root->left);
    printf("%d ",root->data);
    InOrder(root->right);
}
NODE findLargest(NODE root)
{
    if (root == NULL)
        return NULL;

    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}


NODE DelNode(NODE root,int key)
{
    if(root == NULL) return root;
    if(key <root->data)
        root->left = DelNode(root->left,key);
    else if(key > root->data)
        root->right = DelNode(root->right,key);
    else{
        if(root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        else if(root->left == NULL)
        {
            NODE temp = root;
            root = root->right;
            free (temp);
        }
        else if(root->right == NULL)
        {
            NODE temp = root;
            root = root->left;
            free (temp);
        }
        else
        {
            NODE temp = findLargest(root->left);
            root->data = temp->data;
            root->left = DelNode(root->left,temp->data);
        }
    }
    return root;
}

int main()
{
    NODE root = NULL;
    root = inserNode(root,10);
    inserNode(root,5);
    inserNode(root,15);
    inserNode(root,3);
    inserNode(root,7);
    InOrder(root);
    DelNode(root,7);
    printf("\nAfter Deletion:\n");
    InOrder(root);
    return 0;
}