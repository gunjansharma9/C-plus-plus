#include "bits/stdc++.h"
using namespace std;

class graph{
    public:
    unordered_map<int,list<int>>adjList;

    void addEdge(int u,int v,bool direction){
        // directed graph -> 1
        // undirected graph -> 0
        adjList[u].push_back(v);
        if(direction == 0){
            adjList[v].push_back(u);
        }
    }


    // Count no of strongly connected components
    // Kosa Raju Algorithm 
    void dfs1(int src,stack<int>&s,unordered_map<int,bool>&vis){
        vis[src] = true;

        for(auto nbr:adjList[src]){
            if(!vis[nbr]){
                dfs1(nbr,s,vis);
            }
        }
        s.push(src);
    }

    void dfs2(int src,unordered_map<int,bool>&visited,unordered_map<int,list<int>>&adjNew){
        visited[src] = true;
        cout<<src<<", ";
        for(auto nbr:adjNew[src]){
            if(!visited[nbr]){
                dfs2(nbr,visited,adjNew);
            }
        }
    }

    int countSCC(int n){
        stack<int>s;
        unordered_map<int,bool>visited;

        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs1(i,s,visited);
            }
        }

        // reverse all edges
        unordered_map<int,list<int>>adjNew;

        for(auto t:adjList){
            for(auto nbr:t.second){
                int u = t.first;
                int v = nbr;
                // v->u insert
                adjNew[v].push_back(u);
            }
        }

        // reverse using DFS
        int count = 0;
        unordered_map<int,bool>visited2;
        while(!s.empty()){
            int node = s.top();
            s.pop();
            if(!visited2[node]){
                cout<<"Printing "<<count+1<<"th SCC: ";
                dfs2(node,visited2,adjNew);
                cout<<endl;
                count++;
            }
        }

        return count;
    }

    void findBridges(int src,int parent,int& timer,vector<int>&tin,vector<int>&low,unordered_map<int,bool>vis){
        vis[src] = true;
        tin[src] = timer;
        low[src] = timer;
        timer++;

        for(auto nbr:adjList[src]){
            if(nbr == parent){
                continue;
            }

            if(!vis[nbr]){
                // dfs call
                findBridges(nbr,src,timer,tin,low,vis);
                // low update
                low[src] = min(low[src],low[nbr]);
                // check for bridge
                if(low[nbr]>low[src]){
                    cout<<nbr<<"--"<<src<<" is a bridge"<<endl;
                }
            }
            else{
                // node is visited and not a parent
                // low update
                low[src] = min(low[src],low[nbr]);
            }
        }
    }
};

int main(){
    graph g;
    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(2,3,1);
    g.addEdge(3,0,1);
    g.addEdge(2,4,1);
    g.addEdge(4,5,1);
    g.addEdge(5,6,1);
    g.addEdge(6,4,1);
    g.addEdge(6,7,1);

    int ans = g.countSCC(8);
    cout<<"Number of SCC: "<<ans<<endl;

    // Targan's algorithm
    // Bridge in a graph
    // no of components ka count increase kr jaaye toh bridge hai
    // starting mein insertion time and lowest insertion time dono same honge
    // jb b lowest insertion time ko update krenge toh parent ko dekh kr ni krna
    // ab check kro jis node pr khade ho vha pr kha kha ja skte ho..jha ja skte ho agr vo phele se visited hai toh iska mtlb hai jis node se check krre the vha pr ush node se ja skte hai toh ish case mein lowest insertion time ko update krdo..isko ushke equal krdo jis se tum aa skte ho vha
    // agr low[child]<=low[parent] ho gya iska mtlb hai kisi or node se bhi phoch skte hai toh ye bridge nhi hai

    graph g2;
    g2.addEdge(0,1,0);
    g2.addEdge(0,2,0);
    g2.addEdge(2,1,0);
    g2.addEdge(0,3,0);
    g2.addEdge(3,4,0);

    int n=5;
    int timer = 0;
    vector<int>tin(n);
    vector<int>low(n);
    unordered_map<int,bool>vis;
    g2.findBridges(0,-1,timer,tin,low,vis);

    return 0;
}

// 1192. critical connections in a network 
class Solution {
public:

    void findBridges(int src, int parent, int& timer, vector<int>& tin, vector<int>& low, unordered_map<int,bool>& vis, vector<vector<int>>& ans, unordered_map<int, list<int> >& adjList) {

        vis[src] = true;
        tin[src] = timer;
        low[src] = timer;
        timer++;

        for(auto nbr: adjList[src]) {
            if(nbr == parent)
                continue;
            if(!vis[nbr]) {
                //dfs call
                findBridges(nbr, src, timer, tin, low, vis, ans, adjList);
                //low update
                low[src] = min(low[src], low[nbr]);
                //check for bridge
                
                if(low[nbr] > tin[src]) {
                    vector<int> temp;
                    temp.push_back(nbr);
                    temp.push_back(src);
                    ans.push_back(temp);
                }
            }
            else{
                //node is visited and not a parent
                //low update
                low[src] = min(low[src], low[nbr]);
            }
        }
        
        
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        unordered_map<int, list<int> > adjList;


        for(int i=0; i<connections.size(); i++) {
            int u = connections[i][0];
            int v = connections[i][1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        vector<vector<int>> ans;
                    int timer = 1;
                vector<int> tin(n);
                vector<int> low(n);
                unordered_map<int,bool> vis;
        findBridges(0, -1,timer, tin, low, vis, ans,adjList);

        return ans;

    }
};




// 	PRIM's ALGORITHM -> (MINIMUM SPANNING TREE gfg)
class Solution
{
	public:
	
	int getMinValueNode(vector<int>&key,vector<int>&mst){
	    int temp = INT_MAX;
	    int index = -1; //represent actual node having min value
	    for(int i=0;i<key.size();++i){
	        if(key[i]<temp && mst[i]==false){
	            temp = key[i];
	            index = i;
	        }
	    }
	    return index;
	}
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int>key(V,INT_MAX);
        vector<int>mst(V,false); //to keep track which all nodes are added in MST
        vector<int>parent(V,-1); //stores final MST relation.
        
        key[0] = 0;
        
        while(true){
            // Step 1:
            int u = getMinValueNode(key,mst);
            if(u == -1) break;
            // Step 2;
            mst[u] = true;
            
            // Step 3:process all adj NODE to u
            for(auto edge:adj[u]){
                int v = edge[0];
                int w = edge[1];
                if(mst[v] == false && w<key[v]){
                    key[v] = w;
                    parent[v] = u;
                }
            }
        }
        
        // find sum of weights of MST
        int sum = 0;
        for(int u = 0;u<parent.size();++u){
            if(parent[u] == -1) continue;
            for(auto edge:adj[u]){
                int v = edge[0];
                int w = edge[1];
                if(v == parent[u])
                    sum += w;
            }
        }
        return sum;
    }
};


// KRUSKAL's ALGORITHM

bool cmp(vector<int>&a,vector<int>&b){
    return a[2]<b[2];
}

void makeSet(vector<int>&parent,vector<int>&rank,int n){
    // initialization
    for(int i=0;i<n;i++){
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(vector<int>&parent,int node){
    if(parent[node] == node){
        return node;
    }
    return parent[node] = findParent(parent,parent[node]);
}

void unionSet(int u,int v,vector<int>&parent,vector<int>&rank){
    u = findParent(parent,u);
    v = findParent(parent,v);

    if(rank[u]<rank[v]){
        parent[u] = v;
    }
    else if(rank[v]<rank[u]){
        parent[v] = u;
    }
    else{
        parent[v] = u;
        rank[u]++;
    }
}
int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
    // ascending order mein store kr liye weight k basis pr
  sort(edges.begin(),edges.end(),cmp);
  vector<int>parent(n);
  vector<int>rank(n);
  makeSet(parent,rank,n);

  int minWeight = 0;
  for(int i=0;i<edges.size();i++){
      int u = findParent(parent,edges[i][0]);
      int v = findParent(parent,edges[i][1]);
      int wt = edges[i][2];

      if(u != v){
          minWeight += wt;
          unionSet(u,v,parent,rank);
      }
  }
  return minWeight;
}


// Eventual Safe States -> gfg
class Solution {
  public:
    bool checkCyclicDirectedGraphUsingDfs(vector<int>adj[],int src,unordered_map<int,bool>&visited,unordered_map<int,bool>&dfsVisited,int safenodes[]){
        visited[src] = true;
        dfsVisited[src] = true;
        safenodes[src] = 0;

        for(auto nbr:adj[src]){
            if(!visited[nbr]){
                bool aageKaAnswer = checkCyclicDirectedGraphUsingDfs(adj,nbr,visited,dfsVisited,safenodes);
                if(aageKaAnswer == true)
                    return true;
            }
            if(visited[nbr] == true && dfsVisited[nbr] == true){
                return true;
            }
        }
        // jb vapas jayenge to recursion stack se pop krte time isko phir se absent mark krna hai
        dfsVisited[src] = false;
        safenodes[src] = 1;
        return false;
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int>ans;
        unordered_map<int,bool>visited,dfsVisited;
        int safenodes[V] = {0};
        for(int i=0;i<V;i++){
            if(!visited[i]) checkCyclicDirectedGraphUsingDfs(adj,i,visited,dfsVisited,safenodes);
        }
        for(int i=0;i<V;++i){
            if(safenodes[i]) ans.push_back(i);
        }
        return ans;
    }
};

// Word Ladder 2 - gfg
class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        // same as word ladder 1 bs ek toh ye dyan rkhna hai ki ek dm se remove ni krne items jb ek level k saare process ho jaaye tb remove krne hai..or hmhe items to be removed ka track rkhna hai or prevlevel or currlevel ka taaki agr prevlevel or currlevel different ho toh hm siply remove krde set mein se
        vector<vector<string>>ans;
        queue<pair<vector<string>,int>>q;
        q.push({{beginWord},1});
        unordered_set<string>st(wordList.begin(),wordList.end());

        int prevLevel = -1;
        vector<string>toBeRemoved;

        while(!q.empty()){
            auto fNode = q.front();
            q.pop();

            auto currSeq = fNode.first;
            auto currString = currSeq[currSeq.size()-1];
            auto currLevel = fNode.second;

            if(currLevel != prevLevel){
                for(auto s:toBeRemoved) st.erase(s);
                toBeRemoved.clear();
                prevLevel = currLevel;
            }

            if(currString == endWord)
                ans.push_back(currSeq);

            for(int index=0;index<currString.length();index++){
                char originalCharacter = currString[index];
                for(char ch='a';ch<='z';ch++){
                    currString[index] = ch;

                    if(st.find(currString) != st.end()){
                        auto temp = currSeq;
                        temp.push_back(currString);
                        q.push({temp,currLevel+1});
                        toBeRemoved.push_back(currString);
                    }
                }
                currString[index] = originalCharacter;
            }
        }

        return ans;
    }
};


// Minimum Multiplications to reach End
class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        queue<int>q;
        const int mod = 100000;
        vector<int>ans(100000,-1);
        ans[start] = 0;
        q.push(start);
        while(!q.empty()){
            int front = q.front();
            q.pop();
            if(front == end) return ans[end];
            
            for(auto it:arr){
                int newNode = (front*it)%mod;
                if(ans[newNode] == -1){
                    ans[newNode] = ans[front] + 1;
                    q.push(newNode);
                }
            }
        }
        return -1;
    }
};


// 1319. Number of Operations to Make Network Connected
class Solution {
public:
    int findParent(vector<int>&parent,int node){
        if(parent[node] == node){
            return node;
        }
        return parent[node] = findParent(parent,parent[node]); //path compression
    }

    void unionSet(int u,int v,vector<int>&parent,vector<int>&rank){
        u = findParent(parent,u);
        v = findParent(parent,v);
        if(rank[u] < rank[v]){
            parent[u] = v;
            rank[v]++;
        }
        else{
            parent[v] = u;
            rank[u]++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int>parent(n);
        vector<int>rank(n,0);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
        int noExtraEdges = 0;
        for(auto connection:connections){
            int u = connection[0];
            int v = connection[1];

            u = findParent(parent,u);
            v = findParent(parent,v);

            if(u != v){
                unionSet(u,v,parent,rank);
            }else{
                ++noExtraEdges;
            }
        }

        int nocc = 0;
        for(int i=0;i<n;i++){
            if(parent[i] == i){
                nocc++;
            }
        }

        int ans = nocc - 1; //no. of cables needed
        return noExtraEdges >= ans ? ans:-1;
    }
};

// 721. Accounts Merge
class Solution {
public:
    int findParent(vector<int>&parent,int node){
        if(parent[node] == node){
            return node;
        }
        return parent[node] = findParent(parent,parent[node]); //path compression
    }

    void unionSet(int u,int v,vector<int>&parent,vector<int>&rank){
        u = findParent(parent,u);
        v = findParent(parent,v);
        if(rank[u] < rank[v]){
            parent[u] = v;
            rank[v]++;
        }
        else{
            parent[v] = u;
            rank[u]++;
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<int>parent(n);
        vector<int>rank(n,0);
        for(int i=0;i<n;i++) parent[i] = i;
        
        // email id corresponding to particular node
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++){
            auto account = accounts[i];
            // 1 index se isliye start kia hai qki 0 index pr name hai
            for(int j=1;j<account.size();++j){
                string&mail = account[j];
                auto it = mp.find(mail);
                if(it == mp.end()) mp[mail] = i;
                else unionSet(i,it->second,parent,rank);
            }
        }

        // set ascending order maintain krne k liye use kia hai qki ans ascending order mein return krna hai
        unordered_map<int,set<string>>preAns;
        for(auto it:mp){
            int accountNo = it.second;
            auto mail = it.first;
            accountNo = findParent(parent,accountNo);
            preAns[accountNo].insert(mail);
        }

        vector<vector<string>>ans;
        for(auto it:preAns){
            auto accountNo = it.first;
            auto st = it.second;
            vector<string>v;
            v.push_back(accounts[accountNo][0]);
            for(auto mail:st) v.push_back(mail);
            ans.push_back(v);
        }
        return ans;
    }
};


// 1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance
class Solution {
public:
    int shortestDistDijkstra(int src,int n,unordered_map<int,list<pair<int,int>>>&adjList,int &distanceThreshold){
        vector<int>dist(n,INT_MAX);
        set<pair<int,int>>st;

        dist[src] = 0;
        st.insert(make_pair(0,src));
        int reachableCities = 0;

        while(!st.empty()){
            auto topElement = *(st.begin());
            int nodeDistance = topElement.first;
            int node = topElement.second;

            st.erase(st.begin());

            if(node != src && nodeDistance <= distanceThreshold)
                ++reachableCities;

            for(auto nbr:adjList[node]){
                if(nodeDistance + nbr.second < dist[nbr.first]){
                    auto result = st.find(make_pair(dist[nbr.first],nbr.first));
                    if(result != st.end()){
                        st.erase(result);
                    }
                    dist[nbr.first] = nodeDistance + nbr.second;
                    st.insert(make_pair(dist[nbr.first],nbr.first));
                }
            }
        }
        return reachableCities;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        unordered_map<int,list<pair<int,int>>>adjList;
        for(auto edge:edges){
            int &u = edge[0];
            int &v = edge[1];
            int &w = edge[2];
            adjList[u].push_back({v,w});
            adjList[v].push_back({u,w});
        }

        int city = 0;
        int minReachableCities = INT_MAX;
        for(int u=0;u<n;u++){
            int reachableCitiesCount = shortestDistDijkstra(u,n,adjList,distanceThreshold);
            if(reachableCitiesCount <= minReachableCities){
                minReachableCities = reachableCitiesCount;
                city = u;
            }
        }
        return city;
    }
};

