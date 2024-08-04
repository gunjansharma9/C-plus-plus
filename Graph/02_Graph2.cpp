#include "bits/stdc++.h"
using namespace std;

class graph{
    public:
    unordered_map<int,list<pair<int,int>>>adjList;

    void addEdge(int u,int v,int wt,bool direction){
        // directed graph -> 1
        // undirected graph -> 0
        adjList[u].push_back({v,wt});
        if(direction == 0){
            adjList[v].push_back({u,wt});
        }
    }

    void printAdjList(){
        for(auto i:adjList){
            cout<<i.first<<"-> ";
            for(auto j:i.second){
                cout<<"("<<j.first<<", "<<j.second<<"), ";
            }
            cout<<endl;
        }
    }

    void shortestPathBfs(int src,int dest){
        // sbse phele jisse hm dest se phoch jayenge vo hi shortest path hoga
        queue<int>q;
        unordered_map<int,bool>visited;
        unordered_map<int,int>parent;

        q.push(src);
        visited[src] = 1;
        parent[src] = -1;

        while(!q.empty()){
            int fNode = q.front();
            q.pop();

            for(auto nbr:adjList[fNode]){
                if(!visited[nbr.first]){
                    q.push(nbr.first);
                    visited[nbr.first] = 1;
                    parent[nbr.first] = fNode;
                }
            }
        }

        // ab parent vala array bn gya hai
        vector<int>ans;
        int node = dest;
        while(node != -1){
            ans.push_back(node);
            node = parent[node];
        }
        reverse(ans.begin(),ans.end());

        cout<<"Printing ans : "<<endl;
        for(auto i:ans){
            cout<<i<<", ";
        }
        cout<<endl;
    }


    void topoSortDfs(int src,unordered_map<int,bool>&visited,stack<int>&ans){
        visited[src] = true;
        for(auto neighbour:adjList[src]){
            if(!visited[neighbour.first]){
                topoSortDfs(neighbour.first,visited,ans);
            }
        }
        // while returning,store the node in stack
        ans.push(src);
    }

    void shortestpathDfs(int dest,stack<int>topoOrder,int n){
        // distance vector ko initialize krdo phele
        vector<int>dist(n,INT_MAX);

        int src = topoOrder.top();
        topoOrder.pop();
        dist[src] = 0;

        for(auto nbr:adjList[0]){
            // if distance of 0 + weight of nbr agr less than hai distance jo phele se hai nbr ki toh hm update kr denge
            if(dist[0]+nbr.second < dist[nbr.first]){
                dist[nbr.first] = dist[0] + nbr.second;
            }
        }

        while(!topoOrder.empty()){
            int topElement = topoOrder.top();
            topoOrder.pop();


            if(dist[topElement] != INT_MAX){
                for(auto nbr:adjList[topElement]){
                    if(dist[topElement] + nbr.second < dist[nbr.first]){
                        dist[nbr.first] = dist[topElement]+ nbr.second;
                    }
                }
            }
        }
        cout<<"Printing Ans: "<<endl;
        for(int i=0;i<n;i++){
            cout<<i<<"=> "<<dist[i]<<endl;
        }
    }

    // dijkstra algorithm fails in negative cycle(a cycle which is having edge weight negative)
    // if we run dijkstra on -ve cycle then it will get stuck in infinite loop
    void shortestDistDijkstra(int src,int n){
        vector<int>dist(n,INT_MAX);
        // dist to node ka set h taki hm distance k basis pr values sort kr ske set m
        set<pair<int,int>>st;

        dist[src] = 0;
        st.insert(make_pair(0,src));

        while(!st.empty()){
            // st.begin se hmhe first vali value ka iterator milega isliye * lgaye value ko dereference krne k liye
            // set ka use isliye kia hai ye hmhe minimum element fetch krke de dega O(1) complexity mein
            auto topElement = *(st.begin());
            int nodeDistance = topElement.first;
            int node = topElement.second;

            // pop from the set
            st.erase(st.begin());

            // ab neighbour ko traverse kro
            for(auto nbr:adjList[node]){
                if(nodeDistance + nbr.second < dist[nbr.first]){
                    // ye condition true hai mtlb distance ko update kro
                    // phele find kro kya ye set mein phele se exist hai agr hai toh delete kro phir distance update krke set mein insert krdo
                    // mtlb phele vali entry ko delete kro
                    auto result = st.find(make_pair(dist[nbr.first],nbr.first));
                    // if found then remove
                    if(result != st.end()){
                        st.erase(result);
                        // sidha erase result isliye likh rhe hai qki result is like a pointer
                    }
                    // distance vale vector mein or set mein dono mein update kro
                    dist[nbr.first] = nodeDistance + nbr.second;
                    st.insert(make_pair(dist[nbr.first],nbr.first));
                }
            }
        }
        cout<<"Printing ans : "<<endl;
        for(auto i=0;i<n;i++){
            cout<<dist[i]<<", ";
        }cout<<endl;
    }

    // it is used in negative cycle and also detect negative cycle in the graph

    void bellmanFordAlgo(int n, int src) {
        //assuming directed weighted graph
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        //n-1 relaxation step
        for (int i = 0; i < n - 1; i++) {
            //for all edges
            for (auto t : adjList) {
                for (auto nbr : t.second) {
                    int u = t.first;
                    int v = nbr.first;
                    int wt = nbr.second;
                    if (dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
                        dist[v] = dist[u] + wt;
                    }
                }
            }
        }

        //to check for -ve cycle
        // agr n-1 relaxation krne k baad b kuch update ho jata hai iska mtlb hai cycle present hai
        bool negativeCycle = false;
        for (auto t : adjList) {
            for (auto nbr : t.second) {
                int u = t.first;
                int v = nbr.first;
                int wt = nbr.second;
                if (dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
                    negativeCycle = true;
                    break;
                }
            }
        }

        if (negativeCycle == true)
            cout << "-ve cycle present"<<endl;
        else
            cout << "-ve cycle absent"<<endl;

        cout << "printing dist array: ";
        for (auto i : dist)
            cout << i << " ";
    }

    void floydWarshal(int n){
        vector<vector<int>>dist(n,vector<int>(n,100000));
        // diagonal pr zero mark krdo
        for(int i=0;i<n;i++){
            dist[i][i] = 0;
        }
        // graph k according dist insert krdo
        for(auto t:adjList){
            for(auto nbr:t.second){
                int u = t.first;
                int v = nbr.first;
                int wt = nbr.second;
                dist[u][v] = wt;
            }
        }

        for(int helper=0;helper<n;helper++){
            for(int src=0;src<n;src++){
                for(int dest=0;dest<n;dest++){
                    dist[src][dest] = min(dist[src][dest],dist[src][helper]+dist[helper][dest]);
                }
            }
        }

        cout<<"Printing distance array by warshal algo:"<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<dist[i][j]<<", ";
            }cout<<endl;
        }
    }

};

int main(){
    // graph g;
    // g.addEdge(0,1,1,0);
    // g.addEdge(1,2,1,0);
    // g.addEdge(2,3,1,0);
    // g.addEdge(3,4,1,0);
    // g.addEdge(0,5,1,0);
    // g.addEdge(5,4,1,0);
    // g.addEdge(0,6,1,0);
    // g.addEdge(6,7,1,0);
    // g.addEdge(7,8,1,0);
    // g.addEdge(8,4,1,0);

    // g.printAdjList();

    // int src = 0;
    // int dest = 4;
    // // for undirected graph
    // g.shortestPathBfs(src,dest);


    // // directed and weighted graph
    graph g;
    g.addEdge(0,1,5,1);
    g.addEdge(0,2,3,1);
    g.addEdge(2,1,2,1);
    g.addEdge(1,3,3,1);
    g.addEdge(2,3,5,1);
    g.addEdge(2,4,6,1);
    g.addEdge(4,3,1,1);

    g.printAdjList();

    stack<int>topoOrder;
    unordered_map<int,bool>visited;
    g.topoSortDfs(0,visited,topoOrder);

    // main function call for directed and weighted graph
    g.shortestpathDfs(3,topoOrder,5);
    // // 5 yha pr nodes hai -> 0,1,2,3,4
    // // ye jo function hai ye 0 se hr node tk ka shortest path print kr rha hai


    // // Dijkstra Algo
    // graph g;
    // g.addEdge(6,3,2,0);
    // g.addEdge(6,1,14,0);
    // g.addEdge(3,1,9,0);
    // g.addEdge(3,2,10,0);
    // g.addEdge(1,2,7,0);
    // g.addEdge(2,4,15,0);
    // g.addEdge(4,3,11,0);
    // g.addEdge(6,5,9,0);
    // g.addEdge(4,5,6,0);

    // g.printAdjList();

    // g.shortestDistDijkstra(6,7);
    // // 7 is no of nodes -> 0,1,2,3,4,5,6
    // // 6 is source node here

    // graph g2;
    // g2.addEdge(0,1,-1,1);
    // g2.addEdge(0,2,4,1);
    // g2.addEdge(1,2,3,1);
    // g2.addEdge(1,3,2,1);
    // g2.addEdge(1,4,2,1);
    // g2.addEdge(3,1,1,1);
    // g2.addEdge(3,2,5,1);
    // g2.addEdge(4,3,-3,1);

    // g2.bellmanFordAlgo(5,0);
    graph g2;
    g2.addEdge(0,1,11,1);
    g2.addEdge(0,2,12,1);
    g2.addEdge(1,2,13,1);
    g2.addEdge(1,3,10,1);
    g2.addEdge(1,4,-9,1);
    g2.addEdge(2,3,-8,1);
    g2.addEdge(2,4,14,1);
    g2.addEdge(3,1,-7,1);
    g2.addEdge(4,3,12,1);
    g2.bellmanFordAlgo(5,0);


    // graph g3;
    // g3.addEdge(0,1,3,1);
    // g3.addEdge(0,3,5,1);
    // g3.addEdge(1,0,2,1);
    // g3.addEdge(1,3,4,1);
    // g3.addEdge(2,1,1,1);
    // g3.addEdge(3,2,2,1);

    // g3.floydWarshal(4);

    return 0;
}