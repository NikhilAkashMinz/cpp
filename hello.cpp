#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
    
    Node(int val){
        data = val;
        next = NULL;
    }
};

class List{
    public:
        Node* head;
        Node* tail;
    
    List(){
        head = tail = NULL;
    }

    void push_front(int val){
        Node* newNode = new Node(val);
        if(!head){
            head = tail = newNode;
            return;
        }
        else{
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val){
        Node* newNode = new Node(val);
        if(!head)
        {
            head=tail=newNode;
            return;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    void traverse(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }

    void delete(){
        Node*
    }
};


int main()
{
  
    List ll;
    ll.push_front(1);
    ll.push_front(2);

    ll.traverse();


    ll.push_back(3);
    ll.push_back(4);    
    ll.traverse();
    return 0;
}