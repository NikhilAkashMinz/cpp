#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}*TREENode;

TREENode createNode(int data){
    TREENode newNode = (TREENode)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

TREENode  inserNode(TREENode root,int data)
{
    TREENode newNode = createNode(data);
    if(root == NULL){
        return newNode;
    }   

    TREENode queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while(front<rear)
    {
        TREENode temp = queue[front++];
        if(temp->left == NULL){
            temp->left = newNode;
            return root;
        }else{
            queue[rear++] = temp->left;
        }

        if(temp->right == NULL){
            temp->right = newNode;
            return root;
        }else{
            queue[rear++] = temp->right;
        }
    }
    return root;
}

void DFS ( TREENode root){
    if(root == NULL) return;
    printf("%d ",root->data);
    DFS(root->left);
    DFS(root->right);
}

int main(){
    TREENode root = NULL;
    root = inserNode(root,1);
    inserNode(root,2);
    inserNode(root,3);
    inserNode(root,4);
    inserNode(root,5);
    inserNode(root,6);
    inserNode(root,7);

    printf("DFS Traversal: ");
    DFS(root);
    printf("\n");
    return 0;
}