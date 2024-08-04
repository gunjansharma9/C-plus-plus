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

Node* insertIntoBST(Node* &root,int data){
    if(root == NULL){
        root = new Node(data);
        return root;
    }

    if(root -> data > data){
        root -> left = insertIntoBST(root->left,data);
    }else{
        root -> right = insertIntoBST(root->right,data);
    }

    return root;
}

void takeInput(Node* &root){
    int data;
    cin>>data;

    while(data != -1){
        root = insertIntoBST(root,data);
        cin >> data;
    }

}

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

void InOrder(Node* root){
    if(root == NULL){
        return;
    }
    InOrder(root->left);
    cout<<root->data<<" ";
    InOrder(root->right);
}
// Inorder of a BST is always sorted 

// average case mein Binary Search tree ki complexity O(logn) hoti hai insertion m b or searching m b

Node* findNodeInBST(Node* root,int target){
    if(root == NULL){
        return NULL;
    }
    if(root->data == target){
        return root;
    }

    if(target > root->data){
        return findNodeInBST(root->right,target);
    }else{
        return findNodeInBST(root->left,target);
    }
}

int minVal(Node* root){
    Node* temp = root;
    if(temp == NULL){
        return -1;
    }
    while(temp -> left != NULL){
        temp = temp->left;
    }
    return temp -> data;
}

// this is iterative approach to find maximum
int maxVal(Node* root){
    Node* temp = root;
    if(temp == NULL){
        return -1;
    }

    while(temp -> right != NULL){
        temp = temp -> right;
    }
    return temp -> data;
}

// Inorder predecessor and succesor
void PrecSucc(Node* root,Node* &pre,Node* &suc,int key){
    if(root == NULL){
        return ;
    }

    if(root -> data == key){
        if(root -> left != NULL){
            Node* temp = root -> left;
            while(temp -> right){
                temp = temp -> right;
            }
            pre = temp;
        }

        if(root -> right != NULL){
            Node* temp = root -> right;
            while(temp -> left){
                temp = temp -> left;
            }
            suc = temp;
        }
        return;
    }

    if(root -> data > key){
        suc = root;
        PrecSucc(root -> left , pre , suc , key);
    }else{
        pre = root;
        PrecSucc(root -> right, pre ,suc , key);
    }
}

Node* deleteNodeInBST(Node* root,int target){
    // base case
    if(root == NULL){
        return NULL;
    }

    if(root -> data == target){
        if(root -> left == NULL && root -> right == NULL){
            delete root;
            return NULL;
        }
        else if(root -> left == NULL && root -> right != NULL){
            Node* child = root -> right;
            delete root;
            return child;
        }
        else if(root -> left != NULL && root -> right == NULL){
            Node* child = root -> left;
            delete root;
            return child;
        }
        else{
            int inorderPre = maxVal(root->left);
            root -> data = inorderPre;
            root -> left = deleteNodeInBST(root -> left,inorderPre);
            return root;
        }
    }

    else if(target > root -> data){
        root -> right =  deleteNodeInBST(root -> right,target);
    }

    else if(target < root -> data){
        root -> left =  deleteNodeInBST(root -> left,target);
    }
    return root;
}

int main(){
    Node* root = NULL;
    cout<<"Enter the data for the Node : ";
    takeInput(root);

    cout<<"Printing the tree "<<endl;
    levelOrderTraversal(root);

    cout<<"Printing Inorder"<<endl;
    InOrder(root);
    cout<<endl; 

    int target;
    cout<<"Enter data to find in BST : ";
    cin >>target;

    if(findNodeInBST(root,target)){
        cout<<"Node with data "<<target<<" is present";
    }else{
        cout<<"Node with data "<<target<<" is not present";
    }

    cout<<endl;
    cout<<"Minimum value in the BST is : "<<minVal(root)<<endl;

    cout<<"Maximum value in the BST is : "<<maxVal(root)<<endl;

    root = deleteNodeInBST(root, 150);
    levelOrderTraversal(root);
    
    return 0;
}