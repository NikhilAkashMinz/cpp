#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *left,*right;
}*NODE;

NODE createNode(int val)
{
    NODE newNode = (NODE)malloc(sizeof(struct Node));

    if(newNode == NULL)
    {
        printf("Memory allocation failed \n");
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

    if(val<root->data) root->left = insert(root->left,val);
    else root->right = insert(root->right,val);

    return root;
}

NODE findLargestNode(NODE root)
{
    while(root != NULL && root->right != NULL) root=root->right;

    return root;
}

NODE deletionNode(NODE root, int key)
{
    if(root == NULL)
    {
        printf("Root is NULL \n]");
        return root;
    }

    if(key < root->data) root->left = deletionNode(root->left,key);
    else if(key>root->data) root->right= deletionNode(root->right,key);
    else
    {
        if(root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        else if(root->left==NULL)
        {
            NODE temp = root;
            root=root->right;
            free(temp);
        }
        else if(root->right==NULL)
        {
            NODE temp = root;
            root = root->left;
            free(temp);
        }
        else{
            NODE temp = findLargestNode(root->left);
            root->data = temp->data;
            root->left = deletionNode(root->left,temp->data);
        }
        return root;
    }

}

void inorder(NODE root)
{
    if(root == NULL) return;

    inorder(root->left);
    printf("%d", root->data);
    inorder(root->right);
}

int main() {
    NODE root = NULL;
    int choice, val;

    while (1) {
        printf("\n----- BST MENU -----\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Inorder Traversal\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                root = insert(root, val);
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                root = deletionNode(root, val);
                break;

            case 3:
                printf("Inorder: ");
                inorder(root);
                printf("\n");
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}