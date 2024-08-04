#include <iostream>
#include <queue>
#include <vector>
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

Node* buildTree(){
    int data;
    cout<<"Enter the data : "<<endl;
    cin>>data;

    if(data == -1){
        return NULL;
    }

    Node* root = new Node(data);

    cout<<"Enter data for left part of "<<data<<" node"<<endl;
    root -> left = buildTree();

    cout<<"Enter data for right part of "<<data<<" node"<<endl;
    root -> right = buildTree();

    return root;
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

void inorderTraversal(Node* root){
    if(root == NULL){
        return;
    }
    // LNR
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}

void preorderTraversal(Node* root){
    if(root == NULL){
        return;
    }
    // NLR
    cout<<root->data<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postOrderTraversal(Node* root){
    if(root == NULL){
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data<<" ";
}

int height(Node* root){
    if(root == NULL){
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    int ans = max(leftHeight,rightHeight) + 1;

    return ans;
}

int diameter(Node* root){
    if(root == NULL){
        return 0;
    }
    int op1 = diameter(root->left);
    int op2 = diameter(root->right);
    int op3 = height(root->left) + height(root->right);

    int ans = max(op1,max(op2,op3));

    return ans;
}

int main(){
    Node *root = NULL;
    root = buildTree();

    cout<<"Level order traversal is :  "<<endl;
    levelOrderTraversal(root);
    cout<<endl; 

    cout<<"Inorder traversal is : "<<endl;
    inorderTraversal(root);
    
    cout<<"Preorder traversal is : "<<endl;
    preorderTraversal(root);

    cout<<"Postorder traversal is : "<<endl;
    postOrderTraversal(root);

    cout<<"Height of tree is : "<<height(root)<<endl;

    cout<<"Diameter of tree is : "<<diameter(root)<<endl;
    return 0;
}