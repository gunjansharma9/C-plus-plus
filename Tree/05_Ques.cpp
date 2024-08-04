#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
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

int ans = 0;
void pathFromOneRoot(Node* root,long long sum){
    if(!root) return;

    if(sum == root->data){
        ++ans;
    }
    pathFromOneRoot(root->left,sum-root->data);
    pathFromOneRoot(root->right,sum-root->data);
}
int pathSum(Node* root, long long targetSum) {
    if(root){
        pathFromOneRoot(root,targetSum);
        pathSum(root->left,targetSum);
        pathSum(root->right,targetSum);
    }
    return ans;
}


// MorrisTraversal -> same as level order but in this we have space complexity constant instead of O(n)
vector<int>inorderTraversal(Node* root){
    vector<int>ans;
    Node* curr = root;
    while(curr){
        if(curr->left == nullptr){
            ans.push_back(curr->data);
            curr = curr->right;
        }
        else{
            Node* pred = curr->left;
            while(pred->right != curr && pred->right){
                pred = pred->right;
            }

            if(pred->right == nullptr){
                pred->right = curr;
                curr = curr->left;
            }
            else{
                pred->right = nullptr;
                ans.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    return ans;
}


//Flatten a Binary Tree into LL -> leetcode
void flatten(Node* root) {
    Node* curr = root;
    while(curr){
        if(curr->left){
            Node* pred = curr -> left;
            while(pred -> right){
                pred = pred -> right;
            }
            pred -> right = curr -> right;
            curr -> right = curr -> left;
            curr -> left = nullptr;
        }
        curr = curr -> right;
    }
} 


// Maximum sum of Non-adjacent nodes
// pair of sum included and excluded
pair<int,int> getMaxSum_helper(Node* root){
    if(!root){
        return {0,0};
    }
    auto left = getMaxSum_helper(root->left);
    auto right = getMaxSum_helper(root->right);
    
    // sum including the node
    int a = root->data + left.second + right.second;
    
    // sum excluding the node
    int b = max(left.first,left.second) + max(right.first,right.second);
    return {a,b};
}
int getMaxSum(Node *root) 
{
    auto ans = getMaxSum_helper(root);
    return max(ans.first,ans.second);
}
 

// Sum of nodes on the longest path from root to leaf node - gfg

// make pair of height and sum
pair<int,int>height(Node* root){
    if(!root){
        return {0,0};
    }
    
    auto lh = height(root->left);
    auto rh = height(root->right);
    
    int sum = root->data;
    
    if(lh.first == rh.first){
        sum += lh.second > rh.second ? lh.second : rh.second;
    }
    else if(lh.first > rh.first){
        sum += lh.second;
    }
    else{
        sum += rh.second;
    }
    return {max(lh.first,rh.first)+1,sum};
}

int sumOfLongRootToLeafPath(Node *root)
{
    auto h = height(root);
    return h.second;
}




// Burn Tree -> gfg
Node* makeNodetoParentMappingAndFindTargetNode(Node* root,unordered_map<Node*,Node*>&parentMap,int target){
    queue <Node*>q;
    Node* targetNode = 0;
    q.push(root);
    parentMap[root] = 0;
    while(!q.empty()){
        Node* front = q.front();q.pop();
        if(front->data == target){
            targetNode = front;
        }
        if(front->left){
            q.push(front->left);
            parentMap[front->left] = front;
        }
        if(front->right){
            q.push(front->right);
            parentMap[front->right] = front;
        }
    }
    return targetNode;
}

int burnTheTree(Node* targetNode,unordered_map <Node*,Node*>&parentMap){
    unordered_map<Node*,bool>isBurnt;
    queue<Node*>q;
    int T = 0;
    q.push(targetNode);
    isBurnt[targetNode] = 1;
    while(!q.empty()){
        int size= q.size();
        bool isFireSpreaded = 0;
        for(int i=0;i<size;++i){
            Node* front = q.front();
            q.pop();
            if(front->left && !isBurnt[front->left]){
                q.push(front->left);
                isBurnt[front->left] = 1;
                isFireSpreaded = 1;
            }
            if(front->right && !isBurnt[front->right]){
                q.push(front->right);
                isBurnt[front->right] = 1;
                isFireSpreaded = 1;
            }
            if(parentMap[front] && !isBurnt[parentMap[front]]){
                q.push(parentMap[front]);
                isBurnt[parentMap[front]] = 1;
                isFireSpreaded = 1;
            }
        }
        if(isFireSpreaded) ++T;
    }
    return T;
}
int minTime(Node* root, int target) 
{
    unordered_map<Node*,Node*>parentMap;
    Node* targetNode = makeNodetoParentMappingAndFindTargetNode(root,parentMap,target);
    return burnTheTree(targetNode,parentMap);
}



// Find Duplicate Subtrees - leetcode
class Solution {
public:
    vector<Node*>ans;
    unordered_map<string,int>subTreeMap;
    string preorder(Node* root){
        if(!root) return "N";

        string curr = to_string(root->data);
        string l = preorder(root->left);
        string r = preorder(root->right);
        string s = curr + "," + l + "," + r;
        if(subTreeMap.find(s) != subTreeMap.end()){
            if(subTreeMap[s] == 1){
                ans.push_back(root);
            }
            subTreeMap[s]++;
        }
        else{
            subTreeMap[s] = 1;
        }
        return s;
    }
    vector<Node*> findDuplicateSubtrees(Node* root) {
        preorder(root);
        return ans;
    }
};