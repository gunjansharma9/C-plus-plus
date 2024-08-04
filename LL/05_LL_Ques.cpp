#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }

};

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

// LL IS PALINDROME OR NOT

// Node* reverse(Node* head){
//     Node* curr = head;
//     Node* prev = NULL;
//     Node* next = curr -> next;
//     while(curr != NULL){
//         next = curr -> next;
//         curr->next = prev;
//         prev = curr;
//         curr = next;
//     }
//     return prev;
// }

// bool isPalindrome(Node* &head){
//     if(head == NULL){
//         cout<<"LL is empty"<<endl;
//         return true;
//     }
//     if(head -> next == NULL){
//         return true;
//     }
//     // step1: Find the middle node;
//     Node* slow = head;
//     Node* fast = head -> next;

//     while(fast != NULL){
//         fast = fast -> next;
//         if(fast != NULL){
//             fast = fast -> next;
//             slow = slow -> next;
//         }
//     }
//     // now slow pointer is pointing to the middle node

//     // Step B: reverse LL after middle node
//     Node* reverseLLkaHead = reverse(slow->next);

//     slow -> next = reverseLLkaHead;
//     // StepC : start comparison
//     Node* temp1 = head;
//     Node* temp2 = reverseLLkaHead;
//     while(temp2 != NULL){
//         if(temp1 -> data != temp2 -> data){
//             // not a palindrome
//             return false;
//         }
//         else{
//             // if data is equal, then aage bdh jao
//             temp1 = temp1 -> next;
//             temp2 = temp2 -> next;
//         }
//     }
//     return true;
// }

// int main(){
//     Node* head = new Node(10);
//     Node* second = new Node(20);
//     Node* third = new Node(30);
//     Node* fourth = new Node(20);
//     Node* fifth = new Node(10);

//     head -> next = second ;
//     second -> next = third;
//     third -> next = fourth ;
//     fourth -> next = fifth;
//     fifth -> next = NULL;

//     print(head);

//     bool check = isPalindrome(head);

//     if(check){
//         cout<<"LL is a valid Palindrome"<<endl;
//     }

//     else{
//         cout<<"LL is not a palindrome"<<endl;
//     }

//     return 0;
// }


// // REMOVE DUPLICATSES IN SORTED LL


// void removeDuplicates(Node* &head){
//     if(head == NULL){
//         cout<<"LL is empty"<<endl;
//         return ;
//     }

//     if(head -> next == NULL){
//         cout<<"Single Node in LL"<<endl;
//         return;
//     }

//     Node* curr = head;
//     while(curr != NULL){
//         if((curr->next != NULL) && (curr->data == curr->next->data)){
//             Node* temp = curr -> next;
//             curr->next = curr->next->next;
//             // delete node
//             temp->next = NULL;
//             delete temp;
//         }
//         else{
//             curr = curr -> next;
//         }
//     }
// }

// int main(){
//     Node* head = new Node(1);
//     Node* second = new Node(2);
//     Node* third = new Node(2);
//     Node* fourth = new Node(3);
//     Node* fifth = new Node(4);
//     Node* sixth = new Node(4);

//     head -> next = second ;
//     second -> next = third;
//     third -> next = fourth ;
//     fourth -> next = fifth;
//     fifth -> next = sixth;
//     sixth -> next = NULL;

//     print(head);

//     removeDuplicates(head);
//     print(head);

//     return 0;
// }


// // SORT 0's 1's and 2's in a linked list

// Node* sort(Node* &head){

//     if(head == NULL){
//         return NULL;
//     }

//     else if(head -> next == NULL){
//         return head;
//     }
//     // create dummy nodes
//     Node* zeroHead = new Node(-1);
//     Node* zeroTail = zeroHead;

//     Node* oneHead = new Node(-1);
//     Node* oneTail = oneHead;

//     Node* twoHead = new Node(-1);
//     Node* twoTail = twoHead;

//     // traverse the original LL
//     Node* curr = head;
//     while(curr != NULL){
//         if(curr -> data == 0){
//             // take out the zero wali node
//             Node* temp = curr;
//             curr = curr -> next;
//             temp -> next = NULL;

//             // append the zero node in zeroHead LL
//             zeroTail -> next = temp;
//             zeroTail = temp; 
//         }
//         else if(curr -> data == 1){
//             Node* temp = curr;
//             curr = curr -> next;
//             temp -> next = NULL;

//             oneTail-> next = temp;
//             oneTail = temp;
//         }
//         else if(curr -> data == 2){
//             Node* temp = curr;
//             curr = curr -> next;
//             temp -> next = NULL;

//             twoTail -> next = temp;
//             twoTail = temp;
//         }
//     }

//     // deleting dummy node
    
//     Node* temp2 = oneHead;
//     oneHead = oneHead -> next;
//     temp2 -> next = NULL;
//     delete temp2 ;

//     Node* temp3 = twoHead;
//     twoHead = twoHead -> next;
//     temp3->next = NULL;
//     delete temp3;

    
//     if(oneHead != NULL){
//         zeroTail -> next = oneHead;
//         if(twoHead != NULL){
//             oneTail -> next = twoHead;
//         }
//     }
//     else{
//         if(twoHead != NULL){
//             zeroTail->next = twoHead;
//         }
//     }

//     // 0 dummy node ko baad mein isliye remove kia hai agr LL mein zero nhi hoga toh vo vala case b handle ho jayega 
//     Node* temp1 = zeroHead;
//     zeroHead = zeroHead -> next;
//     temp1 -> next = NULL;
//     delete temp1;
    
//     return zeroHead;
// }
// int main(){
//     Node* head = new Node(0);
//     Node* second = new Node(1);
//     Node* third = new Node(1);
//     Node* fourth = new Node(2);
//     Node* fifth = new Node(1);
//     Node* sixth = new Node(1);
//     Node* seventh = new Node(2);

//     head -> next = second ;
//     second -> next = third;
//     third -> next = fourth;
//     fourth -> next = fifth;
//     fifth -> next = sixth;
//     sixth -> next = seventh;
//     seventh -> next = NULL;

//     print(head);
//     head = sort(head);
//     print(head);
//     return 0;
// } 



// ADD TWO LL

Node* reverse(Node* head){
    Node* curr = head;
    Node* prev = NULL;
    Node* next = curr -> next;
    while(curr != NULL){
        next = curr -> next;
        curr->next = prev;
        prev = curr;
        curr = next; 
    }
    return prev;
}

Node* solve(Node* &head1,Node* &head2){
    head1 = reverse(head1);
    head2 = reverse(head2);

    Node* ansHead = NULL;
    Node* ansTail = NULL;
    int carry = 0;

    while(head1 != NULL && head2 != NULL){
        // calculate sum
        int sum = carry + head1->data + head2->data;
        // find digit to create node for
        int digit = sum % 10;
        carry = sum/10;

        // create a new Node for the digit
        Node* newNode = new Node(digit);
        // attach the newNode into the answer wali linked list
        if(ansHead == NULL){
            // first node insert kro
            ansHead = newNode;
            ansTail = newNode;
        }else{
            ansTail -> next = newNode;
            ansTail = newNode;
        }

        head1 = head1 -> next;
        head2 = head2 -> next;
    }

    while(head1 != NULL){
        int sum = carry + head1 -> data;
        int digit = sum % 10;
        carry = sum/10;
        Node* newNode = new Node(digit);
        ansTail -> next = newNode;
        ansTail = newNode;
        head1 = head1 -> next;
    }

    while(head2 != NULL){
        int sum = carry + head2 -> data;
        int digit = sum % 10;
        carry = sum/10;
        Node* newNode = new Node(digit);
        ansTail -> next = newNode;
        ansTail = newNode;
        head2 = head2 -> next;
    }

    while(carry != 0){
        int sum = carry;
        int digit = sum % 10;
        carry = sum/10;
        Node* newNode = new Node(digit);
        ansTail -> next = newNode;
        ansTail = newNode;
    }

    // reverse the ans ll
    ansHead = reverse(ansHead);
    return ansHead;
}

int main(){
    Node* head1 = new Node(2);
    Node* second1 = new Node(4);

    head1 -> next = second1;

    Node* head2 = new Node(2);
    Node* second2 = new Node(3);
    Node* third2 = new Node(4);

    head2 -> next = second2;
    second2 -> next = third2;

    Node* ans = solve(head1,head2);

    print(ans);
    return 0;
}