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

void print(Node* &head){
    Node* temp = head;
    while(temp!= NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

// Node* reverse(Node* &prev,Node* &curr){
//     // base case
//     if(curr == NULL){
//         return prev;
//     }

//     Node* forward = curr->next;
//     curr->next = prev;
//     reverse(curr,forward);
// }

// int main(){
//     Node* head = new Node(1);
//     Node* second = new Node(2);
//     Node* third = new Node(3);
//     Node* fourth = new Node(4);
//     Node* fifth = new Node(5);
    
//     head->next=second;
//     second->next = third;
//     third->next = fourth;
//     fourth->next = fifth;
//     fifth->next = NULL;
//     print(head);

//     Node* prev = NULL;
//     Node* curr = head;
//     head = reverse(prev,curr);
//     print(head);

//     return 0;
// }



// ***************************** FIND MIDDLE **********************
// Node* getMiddle(Node* &head){
//     if(head == NULL){
//         cout<<"LL is empty"<<endl;
//         return head;
//     }

//     if(head -> next == NULL){
//         return head;
//     }

//     Node* slow = head;
//     Node* fast = head;

//     while(slow != NULL && fast != NULL){
//         fast = fast -> next;
//         if(fast != NULL){
//             fast = fast->next;
//             slow = slow->next;
//         }
//     }

//     return slow;
// }

// int main(){
//     Node* head = new Node(10);
//     Node* second = new Node(20);
//     Node* third = new Node(30);
//     Node* fourth = new Node(40);
//     Node* fifth = new Node(50);

//     head -> next = second;
//     second -> next = third;
//     third -> next = fourth;
//     fourth -> next = fifth;
//     fifth -> next = NULL;

//     print(head);

//     cout << "Middle element is : " << getMiddle(head) -> data << endl;
//     return 0;
// }




// **************************** REVERSE K NODES ****************************

int getLength(Node* head){
    int len = 0;
    Node* temp = head;
    while(temp != NULL){
        temp = temp -> next;
        len++;
    }
    return len;
}

Node* reverseKNodes(Node* &head,int k){
    if(head == NULL){
        cout<<"LL is empty"<<endl;
        return NULL;
    }

    int len = getLength(head);
    if(k > len){
        cout<<"Enter valid value for k "<<endl;
        return head;
    }

    Node* prev = NULL;
    Node* curr = head;
    Node* forward = curr -> next;
    int count = 0;

    while(count < k){
        forward = curr->next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
        count++;
    }

    if(forward != NULL){
        head -> next = reverseKNodes(forward,k);
    }

    return prev;
}

int main(){
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);
    Node* sixth = new Node(60);

    head -> next = second;
    second -> next = third;
    third -> next = fourth;
    fourth -> next = fifth;
    fifth -> next = sixth;
    sixth -> next = NULL;

    print(head);
    cout<<"After reversing k nodes LL becomes : "<<endl; 
    head = reverseKNodes(head,2);
    print(head);

    return 0;
}



// // ***********************LOOP IS PRESENT OR NOT**********************
// Floyd’s Cycle-Finding Algorithm (also known as the Tortoise and Hare algorithm)

// bool checkForLoop(Node* &head){
//     if(head == NULL){
//         cout<<"LL is empty"<<endl;
//         return false;
//     }

//     Node* slow = head;
//     Node* fast = head;

//     while(fast != NULL){
//         fast = fast->next;
//         if(fast != NULL){
//             fast = fast -> next;
//             slow = slow -> next;
//         }

//         if(slow == fast){
//             // loop present
//             return true;
//         }
//     }
//     // fast NULL hogya
//     return false;
// }


// Node* startingPointLoop(Node* &head){
//     if(head == NULL){
//         cout<<"LL is empty"<<endl;
//         return NULL;
//     }

//     Node* slow = head;
//     Node* fast = head;

//     while(fast != NULL){
//         fast = fast->next;
//         if(fast != NULL){
//             fast = fast -> next;
//             slow = slow -> next;
//         }

//         if(slow == fast){
//             slow = head;
//             break;
//         }
//     }
//     while(slow != fast){
//         slow = slow->next;
//         fast = fast->next;
//     }
//     return slow;
// }


// void removeLoop(Node* &head){
//     if(head == NULL){
//         cout<<"LL is empty"<<endl;
//         return ;
//     }

//     Node* slow = head;
//     Node* fast = head;

//     while(fast != NULL){
//         fast = fast->next;
//         if(fast != NULL){
//             fast = fast -> next;
//             slow = slow -> next;
//         }

//         if(slow == fast){
//             slow = head;
//             break;
//         }
//     }
//     Node* prev = fast;
//     while(slow != fast){
//         prev = fast;
//         slow = slow->next;
//         fast = fast->next;
//     }
//     prev->next = NULL;
// }

// int main(){
//     Node* head=new Node(10);
//     Node* second = new Node(20);
//     Node* third = new Node(30);
//     Node* fourth = new Node(40);
//     Node* fifth = new Node(50);
//     Node* sixth = new Node(60);
//     Node* seventh = new Node(70);
//     Node* eighth = new Node(80);
//     Node* ninth = new Node(90);
    
//     head->next = second;
//     second->next = third;
//     third->next = fourth;
//     fourth->next = fifth;
//     fifth->next = sixth;
//     sixth->next = seventh; 
//     seventh->next = eighth;
//     eighth->next = ninth;
//     ninth->next = fifth;

    
//     cout<<"Loop is Present or not : "<<checkForLoop(head)<<endl;

//     cout<<"starting point of loop : "<<startingPointLoop(head)->data<<endl;

//     removeLoop(head);
//     print(head);
//     cout<<"Loop is Present or not : "<<checkForLoop(head)<<endl;

//     return 0;
// }