#include <iostream>
using namespace std;

class Node{
    public:

    int data;
    Node* prev;
    Node* next;

    Node(){
        this->data=0;
        this->prev=NULL;
        this->next=NULL;
    }

    Node(int data){
        this->data=data;
        this->prev=NULL;
        this->next=NULL;
    }

    ~Node(){
        cout<<"Node with value: "<<this->data<<" deleted"<<endl;
    }
};

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<< temp->data <<" ";
        temp=temp->next;
    }
}

int getLength(Node* & head){
    int len = 0;
    Node* temp = head;

    while(temp != NULL){
        temp = temp->next;
        len++;
    }
    return len;
}

void insertAtHead(Node* &head,Node* &tail,int data){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else{
        Node* newNode = new Node(data);

        newNode -> next = head;

        head -> prev = newNode;

        head = newNode;
    }
}

void insertAtTail(Node* &head,Node* &tail,int data){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else{
        Node* newNode = new Node(data);
        tail -> next = newNode;
        newNode->prev = tail;
        tail=newNode; 
    }
}

void insertAtPosition(Node* &head,Node* &tail,int data,int position){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else{
        if(position == 1){
            insertAtHead(head,tail,data);
            return;
        }
        int len = getLength(head);
        if(position > len){
            insertAtTail(head,tail,data);
            return;
        }

        int i=1;
        Node* prevNode = head;
        while(i<position-1){
            prevNode = prevNode->next;
            i++;
        }
        
        Node* curr = prevNode->next;
        Node* newNode = new Node(data);
        prevNode -> next = newNode;
        newNode -> prev = prevNode;
        curr -> prev = newNode;
        newNode -> next = curr;
    }
}

void deleteFromPos(Node* &head,Node* &tail,int position){
    int len = getLength(head);

    if(head == NULL){
        cout<<"Linked list is empty";
        return;
    }
    if(position > len){
        cout<<"Please enter a valid position"<<endl;
        return;
    }
    if(head->next == NULL){
        Node* temp = head;
        head = NULL;
        tail = NULL;
        delete temp;
        return;
    }
    if(position == 1){
        Node* temp = head;
        head = head->next;
        head->prev = NULL;
        temp->next = NULL;
        delete temp;
        return;
    }
    
    if(position == len){
        // delete last node
        Node* temp = tail;
        tail = tail->prev;
        temp->prev = NULL;
        tail->next = NULL;
        delete temp;
        return;
    }

    // delete from middle of linked list
    // step1:find left,right,curr
    int i=1;
    Node* left = head;
    while(i<position - 1){
        left = left->next;
        i++;
    }
    Node* curr = left->next;
    Node* right = curr->next;

    left->next = right;
    right->prev = left;
    curr->next = NULL;
    curr->prev = NULL;
    delete curr;
}

int main(){
    Node* head=NULL;
    Node* tail=NULL;
    insertAtHead(head,tail,34);
    insertAtTail(head,tail,45);
    insertAtTail(head,tail,11);
    insertAtTail(head,tail,22);
    print(head);
    cout<<endl;
    insertAtPosition(head,tail,900,4);
    print(head);
    cout<<endl;
    deleteFromPos(head,tail,5);
    print(head);
    return 0;
}