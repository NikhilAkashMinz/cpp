#include<stdio.h>
#include<stdlib.h>


typedef struct MyNode{
    int data;
    struct MyNode *left,*right;
}*NODE;

NODE createNode(int value)
{
    NODE newNode = (NODE)malloc(sizeof(struct MyNode));
    if(newNode == NULL)
    {
        printf("Memory allocation faiiled! \n");
        return;
    }

    newNode->data = value;
    newNode->left=newNode->right=NULL;
    return newNode;
}

NODE insert(NODE root,int val)
{
    if(root==NULL) return createNode(val);

    if(val<root->data) root->left = insert(root->left,val);
    else root->right = insert(root->right,val);
    return root;
}

void inorderTrav(NODE root)
{
    if(root == NULL) return;

    inorderTrav(root->left);
    printf("%d",root->data);
    inorderTrav(root->right);

}

int main()
{
    NODE root = NULL;
     root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 25);
    root = insert(root, 35);

    inorderTrav(root);
    return 0;



}



