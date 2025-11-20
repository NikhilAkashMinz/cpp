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
        cout<<endl;
    }

    void delete_front(){
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void delete_back(){
        Node* temp = head;
        while(temp->next!=tail){
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
        
    }

    void insert(int val , int pos){

        Node* temp = head;

        if(pos < 0) return;

        if(pos == 0) 
            push_front(val);

        for(int i=0;i<pos-1;i++)
        {
            temp = temp->next;
        }

        Node* newNode = new Node(val);

        newNode->next = temp->next;
        temp->next = newNode;

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
    ll.push_back(4);    
    ll.traverse();
    //ll.delete_back();
    
    ll.insert(5,4);
    ll.traverse();

    return 0;
}