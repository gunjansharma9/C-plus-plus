#include "bits/stdc++.h"
using namespace std;


// 207. Course Schedule
// a course ki dependancy b k upar hai isliye topological sort vala algo use kia
class Solution {
    private:
    bool topoSortBfs(int n,unordered_map<int,list<int>>&adjList){
        vector<int>ans;
        queue<int>q;
        unordered_map<int,int>indegree;

        for(auto i:adjList){
            int src = i.first;
            for(auto nbr:i.second){
                indegree[nbr]++;
            }
        }
        for(int i=0;i<n;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int fNode = q.front();
            q.pop();

            ans.push_back(fNode);

            for(auto nbr:adjList[fNode]){
                indegree[nbr]--;
                // check for zero again
                if(indegree[nbr] == 0){
                    q.push(nbr);
                }
            }
        }
        if(ans.size() == n){
            return true;
        }
        else {
            // agr size n k equal nhi hai mtlb cyclic graph hai
            return false;
        }
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // adjList create krdo v to u isliye kri qki prerequisite hai u lene se phele v hona hi chahiye
        unordered_map<int,list<int>>adjList;
        for(auto task:prerequisites){
            int u = task[0];
            int v = task[1];
            adjList[v].push_back(u);
        }
        bool ans = topoSortBfs(numCourses,adjList);
        return ans;
    }
};

// 210. Course Schedule II
class Solution {
    private:
    vector<int> topoSortBfs(int n,unordered_map<int,list<int>>&adjList){
        vector<int>ans;
        queue<int>q;
        unordered_map<int,int>indegree;

        for(auto i:adjList){
            int src = i.first;
            for(auto nbr:i.second){
                indegree[nbr]++;
            }
        }
        for(int i=0;i<n;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int fNode = q.front();
            q.pop();

            ans.push_back(fNode);

            for(auto nbr:adjList[fNode]){
                indegree[nbr]--;
                // check for zero again
                if(indegree[nbr] == 0){
                    q.push(nbr);
                }
            }
        }
        if(ans.size() == n){
            return ans;
        }
        else {
            // agr size n k equal nhi hai mtlb cyclic graph hai
            return {};
        }
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,list<int>>adjList;
        for(auto task:prerequisites){
            int u = task[0];
            int v = task[1];
            adjList[v].push_back(u);
        }
        vector<int> ans = topoSortBfs(numCourses,adjList);
        return ans;
    }
};

// 127. Word Ladder
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        q.push({beginWord,1});

        unordered_set<string>st(wordList.begin(),wordList.end());
        // jo bhi word queue me insert karunga,toh usko set mein se remove krdunga
        st.erase(beginWord);

        while(!q.empty()){
            pair<string,int>fNode = q.front();
            q.pop();

            string currString = fNode.first;
            int currCount = fNode.second;

            // check kahin destination tk toh nhi phoch gye
            if(currString == endWord){
                return currCount;
            }

            for(int index = 0;index<currString.length();index++){
                // original value ko store krlo aage ka check krne k liye
                char originalCharacter = currString[index];
                // hr index pr jo value h,usko main 'a' to 'z' se replace karungi
                for(char ch='a';ch<='z';ch++){
                    currString[index] = ch;
                    // check in wordList
                    if(st.find(currString) != st.end()){
                        q.push({currString,currCount+1});
                        st.erase(currString);
                    }
                }
                // phir se original word mein convert krdo
                currString[index] = originalCharacter;
            }
        }

        return 0;
    }
};


// 1631. Path With Minimum Effort
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        // create a minheap 
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;

        vector<vector<int>>dist(heights.size(),vector<int>(heights[0].size(),INT_MAX));
        pq.push({0,{0,0}});
        dist[0][0] = 0;

        while(!pq.empty()){
            auto fNode = pq.top();
            pq.pop();
            int frontNodeDifference = fNode.first;
            int x = fNode.second.first;
            int y = fNode.second.second;

            // check ans tk toh nhi phoch gye
            if(x == heights.size()-1 && y == heights[0].size()-1){
                return dist[x][y];
            }

            int dx[] = {-1,0,1,0};
            int dy[] = {0,1,0,-1};
            for(int i=0;i<4;i++){
                int newX = x + dx[i];
                int newY = y + dy[i];
                if(newX >= 0 && newY >= 0 && newX<heights.size() && newY < heights[0].size()){
                    int currDifference = abs(heights[x][y] - heights[newX][newY]);
                    int newMax = max(frontNodeDifference,currDifference);
                    if(newMax < dist[newX][newY]){
                        dist[newX][newY] = newMax;
                        pq.push({newMax,{newX,newY}});
                    }
                }
            }
        }
        return 0;
    }
};



// 834. Sum of Distances in Tree
class Solution {
public:
    long root_result = 0;
    vector<int>TotalChildcount;
    int N;

    int dfsBase(unordered_map<int,vector<int>>&adj,int curr_node,int prev_node,int depth){
        int total_count = 1;
        root_result += depth;

        for(int &child : adj[curr_node]){
            if(child == prev_node){
                continue;
            }
            total_count += dfsBase(adj,child,curr_node,depth+1);
        }
        TotalChildcount[curr_node] = total_count;
        return total_count;
    }
    void DFS(unordered_map<int,vector<int>>&adj,int parent_node,int prev_node,vector<int>&result){
        for(int &child:adj[parent_node]){
            if(child==prev_node){
                continue;
            }
            result[child] = result[parent_node] - TotalChildcount[child] + (N-TotalChildcount[child]);
            DFS(adj,child,parent_node,result);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>adj;
        N = n;
        TotalChildcount.resize(n,0);
        for(auto vec:edges){
            int u = vec[0];
            int v = vec[1];
            adj[v].push_back(u);
            adj[u].push_back(v);
        }

        root_result = 0;
        dfsBase(adj,0,-1,0);

        vector<int>result(n,0);

        result[0] = root_result;

        DFS(adj,0,-1,result);
        return result;
    }
};

