Node Ins_Pos(Node head,int data,int pos)
{    
    Node newNode = (Node)malloc(sizeof(Node));
    newNode->data = data;
    newNode->link = NULL;
    if(head == NULL || pos==0){
        newNode->link = head;
        return newNode;
    }

    Node temp = head;
    int i=0;
    while (temp!=NULL && 0 < pos-1)
    {
        temp = temp->link;
        pos--;
    }
    if(temp == NULL) return head;

    newNode->link = temp->link;
    temp->link = newNode;

    return head;
}