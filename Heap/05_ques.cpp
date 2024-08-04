#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>
using namespace std;


// Median in a stream
void callMedian(int &median,priority_queue<int>&maxHeap,priority_queue<int,vector<int>,greater<int>>& minHeap,int element){
    if(minHeap.size() == maxHeap.size()){
        if(element > median){
            minHeap.push(element);
            median = minHeap.top();
        }
        else{
            maxHeap.push(element);
            median = maxHeap.top();
        }
    }
    else if(maxHeap.size() > minHeap.size()){
        if(element > median){
            minHeap.push(element);
            median = (minHeap.top() + maxHeap.top())/2;
        }
        else{
            int maxTop = maxHeap.top();
            maxHeap.pop();
            minHeap.push(maxTop);
            maxHeap.push(element);
            median = (minHeap.top() + maxHeap.top())/2;
        }
    }
    else{
        // maxHeap.size() < minHeap.size()
        if(element > median){
            int minTop = minHeap.top();
            minHeap.pop();
            maxHeap.push(minTop);
            minHeap.push(element);
            median = (minHeap.top() + maxHeap.top())/2;
        }
        else{
            maxHeap.push(element);
            median = (minHeap.top() + maxHeap.top())/2;
        }

    }
}

int main(){
    int arr[6] = {5,7,2,9,3,8};
    int n = 6;

    int median = 0;
    priority_queue<int>maxHeap;
    priority_queue<int,vector<int>,greater<int>> minHeap;

    for(int i=0;i<n;i++){
        int element = arr[i];
        callMedian(median,maxHeap,minHeap,element);
        cout<<"->"<<median<<" ";
    }cout<<endl;

    return 0;
}




// Is Binary Tree Heap -> gfg
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
int nodecount(struct Node* root){
    if(!root) return 0;
    int l = nodecount(root->left);
    int r = nodecount(root->right);
    return l+r+1;
}

bool isCBT(struct Node* root,int i,int &n){
    if(!root) return true;
    if(i > n) return false;
    return isCBT(root->left,2*i,n) && isCBT(root->right,2*i+1,n);
}

bool isMaxOrder(struct Node* root){
    if(!root) return true;
    int l = isMaxOrder(root->left);
    int r = isMaxOrder(root->right);
    int ans = false;
    if(!root->left && !root->right){
        ans = true;
    }
    else if(root->left && !root->right){
        ans = root->data > root->left->data;
    }
    else{
        ans = root->data > root->left->data && root->data > root->right->data;
    }
    return ans && l && r;
}

class Solution {
  public:
    bool isHeap(struct Node* tree) {
        int n = nodecount(tree);
        int i = 1;
        return isCBT(tree,i,n) && isMaxOrder(tree);
    }
};



//Merge two binary Max heaps - gfg
class Solution{
    public:
    void heapify(vector<int>&v,int i,int n){
        while(true){
            int left = 2*i+1;
            int right = 2*i+2;
            int swapindex = i;
            if(left < n && v[left] > v[i]){
                swapindex = left;
            }
            if(right < n && v[right] > v[swapindex]){
                swapindex = right;
            }
            if(swapindex == i){
                break;
            }
            swap(v[i],v[swapindex]);
            i = swapindex;
        }
    }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // 1.merge two heap vectors
        vector<int>c(a.begin(),a.end());
        c.insert(c.end(),b.begin(),b.end());
        
        // 2.Let's heapify vector c
        for(int i=(c.size()/2)-1;i>=0;--i){
            heapify(c,i,c.size());
        }
        
        return c;
    }
};



// 973. K Closest Points to Origin
class Solution {
public:
    class mycomp{
        public:
        bool operator()(pair<int,int>&a,pair<int,int>&b){
            int distA = a.first*a.first + a.second*a.second;
            int distB = b.first*b.first + b.second*b.second;
            return distA > distB;
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,mycomp>pq;
        //min heap based on giving higher priority to point closer to origin.
        for(auto p:points){
            pq.push({p[0],p[1]});
        }
        while(!pq.empty() && k--){
            auto&top = pq.top();
            ans.push_back({top.first,top.second});
            pq.pop();
        }
        return ans;
    }
};



// 239. Sliding Window Maximum
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    priority_queue<pair<int,int>>pq; //pair<val,index>
    vector<int>ans;

    // consider first window
    for(int i=0;i<k;++i){
        pq.push({nums[i],i});
    }
    // store max of first window
    ans.push_back(pq.top().first);

    // consider rest of the window
    for(int i=k;i<nums.size();++i){
        pq.push({nums[i],i});

        // remove if maxs are from previous windows.
        while(pq.top().second <= i-k){
            pq.pop();
        }
        ans.push_back(pq.top().first);
    }
    return ans;
}




// 1878. Get Biggest Three Rhombus Sums in a Grid
class Solution {
public:
    bool checkBounds(vector<vector<int>>&grid,vector<pair<int,int>>&v){
        int m = grid.size();
        int n = grid[0].size();
        for(auto pt:v){
            if(pt.first < 0 || pt.first >= m || pt.second < 0 || pt.second >= n){
                return false;
            }
        }
        return true;
    }
    bool getAllVertices(vector<vector<int>>&grid,vector<pair<int,int>>&v,pair<int,int>c,int& delta){
        pair<int,int>A(c.first-delta,c.second);
        pair<int,int>B(c.first,c.second+delta);
        pair<int,int>C(c.first+delta,c.second);
        pair<int,int>D(c.first,c.second-delta);
        v[0] = A;
        v[1] = B;
        v[2] = C;
        v[3] = D;
        if(checkBounds(grid,v)){
            return true;
        }
        return false;
    }
    void getAllSum(vector<vector<int>>grid,int&cx,int&cy,priority_queue<int>&pq){
        // push Rhombus sum of RH with arr
        pq.push(grid[cx][cy]);
        int delta = 1;
        vector<pair<int,int>>v(4);
        while(getAllVertices(grid,v,{cx,cy},delta)){
            pair<int,int>&A = v[0];
            pair<int,int>&B = v[1];
            pair<int,int>&C = v[2];
            pair<int,int>&D = v[3];
            int csum = grid[A.first][A.second] + grid[B.first][B.second] + grid[C.first][C.second] + grid[D.first][D.second];

            // all cells between AB
            for(int i=1;i<(B.first-A.first);++i){
                csum += grid[A.first+i][A.second+i];
            }

            // all cells between BC
            for(int i=1;i<(C.first-B.first);++i){
                csum += grid[B.first+i][B.second-i];
            }

            // all cells between CD
            for(int i=1;i<(C.first-D.first);++i){
                csum += grid[C.first-i][C.second-i];
            }

            // all cells between DA
            for(int i=1;i<(D.first-A.first);++i){
                csum += grid[D.first-i][D.second+i];
            }

            pq.push(csum);
            ++delta;
        }
    }

    bool canpush(vector<int>&ans,int &top){
        for(auto val:ans){
            if(val == top){
                return false;
            }
        }
        return true;
    }
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        vector<int>ans;
        priority_queue<int>pq;
        int m = grid.size();
        int n = grid[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                getAllSum(grid,i,j,pq);
            }
        }

        while(!pq.empty() && ans.size() < 3){
            int top = pq.top();
            pq.pop();
            if(canpush(ans,top)){
                ans.push_back(top);
            }
        }

        return ans;
    }
};



// 2163. Minimum Difference in Sums After Removal of Elements
class Solution {
public:
#define ll long long
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size()/3;
        vector<ll>prefix(nums.size(),-1),suffix(nums.size(),-1);
        // prefix[i] = sum of first n elements from left side
        // suffix[i] = sum of first n elements from right side;

        ll sum = 0; //min n elements sum
        priority_queue<ll>pq; //max heap
        for(int i=0;i<nums.size();++i){
            sum += nums[i];
            pq.push(nums[i]);

            // pop out max elements
            if(pq.size() > n){
                sum -= pq.top();
                pq.pop();
            }

            if(pq.size() == n){
                prefix[i] = sum;
            }
        }

        sum = 0; //max n elements sum
        priority_queue<ll,vector<ll>,greater<ll>>pq2; //min heap
        for(int i=nums.size()-1;i>=0;--i){
            sum += nums[i];
            pq2.push(nums[i]);

            // pop out min elements
            if(pq2.size() > n){
                sum -= pq2.top();
                pq2.pop();
            }
            if(pq2.size() == n){
                suffix[i] = sum;
            }
        }
        ll ans = LONG_LONG_MAX;
        for(int i=n-1;i<2*n;++i){
            ans = min(ans,prefix[i]-suffix[i+1]);
        }
        return ans;
    }
};



// 871. Minimum Number of Refueling Stops
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int stops = 0;
        int dist = 0;
        int i = 0;
        int fuel = startFuel;
        priority_queue<pair<int,int>>pq; //{fuel,pos}
        while(true){
            while(i<stations.size()){
                // push stations within the reach with my current fuel levels from my current pos
                if(stations[i][0] <= dist+fuel){
                    pq.push({stations[i][1],stations[i][0]});
                }
                else{
                    break;
                }
                ++i;
            }

            // travel with full fuel level
            dist += fuel;
            fuel = 0;
            if(dist >= target) break;

            // no fuel stations within reach
            if(pq.empty()){
                stops = -1;
                break;
            }

        
            // refuel ans re-adjust dist & fuel based on the distance travel
            auto &top = pq.top();
            fuel = (dist-top.second) + top.first;
            dist = top.second;
            pq.pop();
            stops++;

        }
        return stops;
    }
};