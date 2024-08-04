#include "bits/stdc++.h"
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
    

// is valid BST

// bool solve(Node* root,long long int lb,long long int ub){
//     // base case
//     if(root == NULL){
//         return true;
//     }

//     if((root -> data > lb && root->data < ub) && solve(root->left,lb,root->data) && solve(root->right,root->data,ub)){
//         return true;
//     }
//     else{
//         return false;
//     }

// }

// bool isValidBST(Node* root) {
//     long long int lowerBound = -4294967296;
//     long long int upperBound = 4294967296;
//     bool ans = solve(root,lowerBound,upperBound);
//     return ans;
// }



// lowest common ancestor in BST -> leetcode

// Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
//     if(root == NULL)
//         return NULL;

//     if(p->data < root->data && q->data < root-> data){
//         return lowestCommonAncestor(root->left,p,q);
//     }
//     if(p->data > root->data && q->data > root->data){
//         return lowestCommonAncestor(root->right,p,q);
//     }

//     return root;
// }



// 230. Kth Smallest Element in a BST --> leetcode

// inorder traversal kro -> left m jao phir node pr jb jaoge toh k ko decrement kr do phir right mein jao

// int kthSmallest(Node* root, int& k) {
//     if(root == NULL){
//         return -1;
//     }

//     // inorder

//     // left
//     int leftAns = kthSmallest(root->left,k);

//     if(leftAns != -1){
//         return leftAns;
//     }

//     // N->root
//     k--;
//     if(k == 0){
//         return root->data;
//     }

//     // right
//     int rightAns = kthSmallest(root->right,k);
//     return rightAns;
// }


// Create a BST using inorder traversal

// Node* bstUsingInorder(int inorder[],int s,int e){
//     // base case
//     if(s > e){
//         return NULL;
//     }

//     int mid = (s+e)/2;
//     int element = inorder[mid];
//     Node* root = new Node(element);

//     root->left= bstUsingInorder(inorder,s,mid-1);
//     root->right = bstUsingInorder(inorder,mid+1,e);

//     return root;
// }

// int main(){
//     int inorder[] = {1,2,3,4,5,6,7,8,9} ; 
//     int s = 0;
//     int e = 8;

//     Node* root = bstUsingInorder(inorder,s,e);
//     bstUsingInorder(inorder,s,e);

//     return 0;
// }



// // Convert BST into sorted doubly LL
// void convertIntoSortedDLL(Node* root,Node* &head){
//     if(root == NULL){
//         return;
//     }

//     // right subtree into LL
//     convertIntoSortedDLL(root->right,head);

//     // attach root node
//     root->right = head;

//     if(head != NULL){
//         head -> left = root;
//     }

//     // update head
//     head = root;

//     // left subtree linked list
//     convertIntoSortedDLL(root->left,head);
// }

// void printLinkedList(Node* head){
//     Node* temp = head;
//     cout<<endl;
//     while(temp != NULL){
//         cout<<temp->data<<" ";
//         temp = temp->right;
//     }
//     cout<<endl;
// }

// // convert sorted LL to BST
// Node* sortedLLintoBST(Node* &head,int n){
//     // base case
//     if(n<=0 || head == NULL){
//         return NULL;
//     }

//     Node* leftSubtree = sortedLLintoBST(head,n-1-n/2);
//     Node* root = head;
//     root->left = leftSubtree;

// // remember this line 
//     head = head -> right;

//     // right part solve krna h
//     root->right = sortedLLintoBST(head,n/2);
//     return root;
// }
void levelOrderTraversal(Node* root){
    queue<Node*>q;

    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }

        else{
            cout<<temp->data<<" ";

            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }

    }
}

// int main(){
//     int inorder[] = {1,2,3,4,5,6,7,8,9};
//     int s = 0;
//     int e = 8;

//     Node* root = bstUsingInorder(inorder,s,e);
    
//     cout<<"Printing sorted Linked list : "<<endl;
//     Node* head = NULL;
//     convertIntoSortedDLL(root,head);
//     printLinkedList(head);

//     // checking for ques convert sortedLL into BST
//     Node* root1 = NULL;
//     root1 = sortedLLintoBST(head,9);
//     cout<<"Doing level order traversal for root1"<<endl;
//     levelOrderTraversal(root1);

//     return 0;
// }


// Largest BST in a binary Tree
class NodeData{
    public:
    int size;
    int minVal;
    int maxVal;
    bool validBST;

    NodeData(){

    }

    NodeData(int size,int max,int min,bool valid){
        this -> size = size;
        minVal = min;
        maxVal = max;
        validBST = valid;
    }
};

NodeData* findLargestBST(Node* root, int &ans) {
	//base case
	if(root == NULL) {
		NodeData* temp  = new NodeData(0, INT_MIN, INT_MAX, true);
		return temp;
	}

	NodeData* leftKaAns = findLargestBST(root->left, ans);
	NodeData* rightKaAns = findLargestBST(root->right,ans);

	//checking starts here
	NodeData* currNodeKaAns = new NodeData();

	currNodeKaAns->size = leftKaAns->size + rightKaAns->size + 1;
	currNodeKaAns->maxVal = max(root->data, rightKaAns->maxVal);
	currNodeKaAns->minVal = min(root->data, leftKaAns->minVal);

	if(leftKaAns->validBST && rightKaAns->validBST && (root->data > leftKaAns->maxVal && root->data < rightKaAns->minVal) ) {
		currNodeKaAns->validBST = true;
	}
	else {
		currNodeKaAns->validBST = false;
	}

	if(currNodeKaAns->validBST) {
		ans = max(ans, currNodeKaAns->size);
	}
	return currNodeKaAns;
}
int main(){

    Node* root = new Node(50);
    Node* first = new Node(30);
    Node* second = new Node(60);
    Node* third = new Node(5);
    Node* fourth = new Node(20);
    Node* fifth = new Node(45);
    Node* sixth = new Node(70);
    Node* seventh = new Node(65);
    Node* eight = new Node(80);

    root->left = first;
    root->right = second;
    first->left = third;
    first -> right = fourth;
    second->left = fifth;
    second->right = sixth;
    sixth->left = seventh;
    sixth->right= eight;
	
    cout << "Printing the tree" << endl;
    levelOrderTraversal(root);


    int ans = 0;
    findLargestBST(root,ans);
    cout << "Largest BSK ka Size:  "<< ans << endl;    
    

    return 0;
}