#include <iostream>
#include <map>
#include <queue>
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

void printTopView(Node* root){
    if(root == NULL){
        return;
    }

    // create a map for storing Horizontal distance -> topNode data
    map<int,int>topNode;

    // level order
    // we will store a pair consisting of Node and Horizontal Distance
    queue<pair<Node*,int>>q;
    q.push(make_pair(root,0));

    while(!q.empty()){
        pair<Node*,int>temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;

        // jo b horizontal distance aaya h,check if answer for that hd already exists or not
        if(topNode.find(hd) == topNode.end()){
            // if answer is not available in map then store it
            topNode[hd] = frontNode->data;
        }

        if(frontNode -> left)
            q.push(make_pair(frontNode->left,hd-1));
        if(frontNode -> right)
            q.push(make_pair(frontNode->right,hd+1));
    }

    // ab aapka answer store hua hoga aapke map me
    cout<<"Printing the answer: "<<endl;
    for(auto i:topNode){
        cout<<i.first << " -> "<<i.second<<endl;
    }
}



void printBottomView(Node* root){
    if(root == NULL){
        return;
    }

    // create a map for storing Horizontal distance -> topNode data
    map<int,int>topNode;

    // level order
    // we will store a pair consisting of Node and Horizontal Distance
    queue<pair<Node*,int>>q;
    q.push(make_pair(root,0));

    while(!q.empty()){
        pair<Node*,int>temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;

    // only here code changes from topview to bottomview
        topNode[hd] = frontNode->data;


        if(frontNode -> left)
            q.push(make_pair(frontNode->left,hd-1));
        if(frontNode -> right)
            q.push(make_pair(frontNode->right,hd+1));
    }

    // ab aapka answer store hua hoga aapke map me
    cout<<"Printing the answer: "<<endl;
    for(auto i:topNode){
        cout<<i.first << " -> "<<i.second<<endl;
    }
}



// left view
void printLeftTree(Node* root,vector<int>&ans,int level){
    // base case
    if(root == NULL){
        return;
    }
    if(level == ans.size()){
        ans.push_back(root->data);
    }

    // left
    printLeftTree(root->left,ans,level+1);

    // right
    printLeftTree(root->right,ans,level+1);

}

// right view
void printRightTree(Node* root,vector<int>&ans,int level){
    // base case
    if(root == NULL){
        return;
    }
    if(level == ans.size()){
        ans.push_back(root->data);
    }
    // right call phele
    printRightTree(root->right,ans,level+1);
    // left
    printRightTree(root->left,ans,level+1);

}

void printLeftBoundary(Node* root){
    // base case
    // if root is NULL,then go back
    if(root == NULL){
        return;
    }
    // if root is a leaf node,then go back
    if(root -> left == NULL && root->right == NULL){
        return;
    }

    cout<<root->data<<" ";
    if(root->left){
    printLeftBoundary(root->left);
    }
    else{
    printLeftBoundary(root->right);
    }
}

void printLeafBoundary(Node* root){
    // base case
    if(root == NULL){
        return;
    }

    if(root->left == NULL && root->right == NULL){
        cout<<root->data<<" ";
    }
    printLeafBoundary(root->left);
    printLeafBoundary(root->right);
}

void printRightBoundary(Node* root){
    // base case
    if(root == NULL){
        return;
    }
    if(root->left == NULL && root->right == NULL){
        return;
    }

    if(root->right){
    printRightBoundary(root->right);
    }
    else{
    printRightBoundary(root->left);
    }

    cout<<root->data<<" "; 
}

void boundaryTraversal(Node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    // A
    printLeftBoundary(root->left);
    // B
    printLeafBoundary(root);
    // C
    printRightBoundary(root->right);
}

int main(){
    Node* root = NULL;
    root = buildTree();
    vector<int>ans;
    vector<int>ans2;
    int level = 0;
// 10 20 30 -1 -1 40 60 -1 -1 -1 80 50 -1 70 -1 -1 90 -1 -1 -->input
    printTopView(root);
    printBottomView(root);
    printLeftTree(root,ans,0);
    cout<<"Printing left view"<<endl;
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
    printRightTree(root,ans2,0);
    cout<<"Printing Right view"<<endl;
    for(auto i:ans2){
        cout<<i<<" ";
    }

    cout<<endl; 
    cout<<"Printing Boundary Traversal"<<endl;
    boundaryTraversal(root);
    return 0;
}