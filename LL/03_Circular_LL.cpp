#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(){
        this->data = 0;
        this->next = NULL;
    }

    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    ~Node(){    
        cout<<"\nNode with value "<<this->data<<" deleted"<<endl;
    }
};

void insertNode(Node* &head,int data){
    Node* newNode = new Node(data);
    if(head == NULL){
        newNode->next = newNode;
        head = newNode;
        return;
    }

    Node* temp=head;
    newNode->next=head;
    while(temp->next != head){
        temp=temp->next;
    }
    temp->next = newNode;
}

void deleteNode(Node* &head,int data){
    if(head==NULL){
        cout<<"No element available to perform deletion..";
        return;
    }
    if(head->data == data && head->next == head){
        Node* temp = head;
        head = NULL;
        delete(temp);
        return;
    }
    Node* last=head;
    if(head->data == data){
        while(last->next != head){
            last=last->next;
        }
        last->next=head->next;
        Node*temp = head;
        head=head->next;
        delete(temp);
        return ;
    }
    Node* temp = head->next;
    Node* back = head;
    while(temp->data != data && temp->next != head){
        temp = temp->next;
        back = back->next;
    }
    back->next = temp->next;
    delete(temp);

}

void print(Node* &head){
    Node* temp=head;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp != head);
}

int main(){
    Node* head = NULL;
    insertNode(head,1);
    print(head);
    cout<<endl;
    insertNode(head,2);
    insertNode(head,3);
    insertNode(head,4);
    insertNode(head,5);
    insertNode(head,6);
    print(head);
    deleteNode(head,6);
    print(head);

    return 0;
}