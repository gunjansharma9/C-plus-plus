#include <iostream>
#include <list>
#include <vector>
#include <stack>
#include <unordered_map>
#include <queue>
using namespace std;
template <typename T>

// // adjacency list implementation
class Graph{
    public:
    // Here we are creating a general graph 
    unordered_map<T,list<T > >adjList;

    void addEdge(T u,T v,bool direction){
        adjList[u].push_back(v);
        if(direction == 0){
            adjList[v].push_back(u);
        }
    }
//     unordered_map<int,list<int>>adjList;

//     // void addEdge(int u,int v,bool direction){
//     //     adjList[u].push_back(v);
//     //     if(direction == 0){
//     //         // undirected edge
//     //         // create an edge from v to u
//     //         adjList[v].push_back(u);
//     //     }
//     // }

    void printAdjacencyList(){
        for(auto node:adjList){
            cout<<node.first<<"->";
            for(auto neighbour :node.second){
                cout<<neighbour<<", ";
            }
            cout<<endl;
        }
    }

    // BFS Traversal
    void bfs(int src,unordered_map<int,bool>&visited){
    queue<int>q;

    q.push(src);
    visited[src] = true;

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();
        cout<<frontNode<<", ";

        // insert neighbours
        for(auto neighbour:adjList[frontNode]){
            if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour] = true;
            }
        }
    }

    }

    // DFS Traversal
    void dfs(int src,unordered_map<int,bool>&visited){
        cout<<src<<", ";
        visited[src] = true;

        for(auto neighbour:adjList[src]){
            if(!visited[neighbour]){
                dfs(neighbour,visited);
            }
        }
    }

    // Undirected Graph
    bool checkCyclicUsingBfs(int src,unordered_map<int,bool>&visited){
        queue<int>q;
        unordered_map<int,int>parent;

        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        while(!q.empty()){
            int frontNode = q.front();
            q.pop();

            for(auto nbr:adjList[frontNode]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr] = true;
                    parent[nbr] = frontNode;
                }
                if(visited[nbr] && nbr != parent[frontNode]){
                    return true;
                }
            }
        }

        return false;
    }

    bool checkCyclicUsingDfs(int src,unordered_map<int,bool>&visited,int parent){
        visited[src] = true;
        for(auto nbr:adjList[src]){
            if(!visited[nbr]){
                bool checkAageKaAns = checkCyclicUsingDfs(nbr,visited,src);
                if(checkAageKaAns == true)
                    return true;
            }
            if(visited[nbr] && nbr != parent){
                return true;
            }
        }

        return false;
    }


    bool checkCyclicDirectedGraphUsingDfs(int src,unordered_map<int,bool>&visited,unordered_map<int,bool>dfsVisited){
        visited[src] = true;
        dfsVisited[src] = true;

        for(auto nbr:adjList[src]){
            if(!visited[nbr]){
                bool aageKaAnswer = checkCyclicDirectedGraphUsingDfs(nbr,visited,dfsVisited);
                if(aageKaAnswer == true)
                    return true;
            }
            if(visited[nbr] == true && dfsVisited[nbr] == true){
                return true;
            }
        }
        // jb vapas jayenge to recursion stack se pop krte time isko phir se absent mark krna hai
        dfsVisited[src] = false;
        return false;
    }

    // topological sort by using dfs
    void topoSortDfs(int src,unordered_map<int,bool>&visited,stack<int>&ans){
        visited[src] = true;
        for(auto neighbour:adjList[src]){
            if(!visited[neighbour]){
                topoSortDfs(neighbour,visited,ans);
            }
        }
        // while returning,store the node in stack
        ans.push(src);
    }

    // topological sort by using bfs
    void topoSortBfs(int n,vector<int>&ans){
        queue<int>q;
        unordered_map<int,int>indegree;

        // indegree calculate
        for(auto i:adjList){
            int src = i.first;
            for(auto nbr:i.second){
                indegree[nbr]++;
            }
        }

        // put all nodes inside queue,which has indegree = 0
        // sbse phele jis jis node ki indegree 0 hai unhe q mein push krdo
        for(int i=0;i<n;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        // bfs logic
        // ab q se element nikalo or usko ans mein push krdo phir usko pop krdo
        // pop krne k baad usse connected jo node hai unki indegree 1 minus bhi toh krni pdegi vo krdo
        // phir se check kro agr indegree 0 ho gyi hai toh q mein push krdo
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
    }
};

class GraphWithWeight{
    public:


    // unordered_map<int,list<pair<int,int>>>adjList;

    // void addEdge(int u,int v,int weight,bool direction){
    //     adjList[u].push_back({v,weight});
    //     if(direction == 0){
    //         // undirected edge
    //         // create an edge from v to u
    //         adjList[v].push_back({u,weight});
    //     }
    // }

    // void printAdjacencyList(){
    //     for(auto node:adjList){
    //         cout<<node.first<<"->";
    //         for(auto neighbour : node.second){
    //             cout<<"("<<neighbour.first<<","<<neighbour.second<<"),";
    //         }
    //         cout<<endl;
    //     }
    // }
};



int main(){
    // int n;
    // cout<<"Enter the number of nodes: "<<endl;
    // cin>>n;

    // vector<vector<int>>adj(n,vector<int>(n,0));

    // int e;
    // cout<<"Enter the number of edges: "<<endl;
    // cin>>e;

    // for(int i=0;i<e;i++){
    //     int u,v;
    //     cout<<"Enter u & v : "<<endl;
    //     cin>>u>>v;
    //     adj[u][v] = 1;
    // }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<adj[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    // // undirected graph
    // Graph g;
    // g.addEdge(0,1,0);
    // g.addEdge(1,2,0);
    // g.addEdge(0,2,0);
    // cout<<endl;
    // g.printAdjacencyList();

    // // directed graph
    // Graph g;
    // g.addEdge(0,1,1);
    // g.addEdge(1,2,1);
    // g.addEdge(0,2,1);
    // cout<<endl;
    // g.printAdjacencyList();

    
    // // Weighted directed graph
    // GraphWithWeight g2;


    // g2.addEdge(0,1,5,1);
    // g2.addEdge(1,2,8,1);
    // g2.addEdge(0,2,6,1);
    // cout<<endl;
    // g2.printAdjacencyList();

    //// yha pr ye integer bn jayega
    // Graph <char>g2;
    // g2.addEdge('a','b',0);
    // g2.addEdge('b','c',0);
    // g2.addEdge('a','c',0);
    // cout<<endl;
    // g2.printAdjacencyList();

    // // // BFS Traversal
    // Graph <int>g;
    // int n = 7;
    // g.addEdge(0,1,0);
    // g.addEdge(1,2,0);
    // g.addEdge(1,3,0);
    // g.addEdge(3,5,0);
    // g.addEdge(3,7,0);
    // g.addEdge(7,6,0);
    // g.addEdge(7,4,0);
    // g.printAdjacencyList();
    // cout<<endl;

    // Graph<int>g;
    // int n = 5;
    // g.addEdge(0,1,0);
    // g.addEdge(1,2,0);
    // g.addEdge(2,3,0);
    // g.addEdge(3,4,0);
    // g.addEdge(4,0,0);



    // if graph is unconnected means breaked in many components
    // run a loop for all nodes
    // cout<<"Printing BFS Traversal: "<<endl;
    // unordered_map<int,bool>visited;
    // for(int i=0;i<=n;i++){
    //     if(!visited[i]){
    //         g.bfs(i,visited);
    //     }
    // }

    // cout<<"Printing DFS Traversal: "<<endl;
    // unordered_map<int,bool>visited2;
    // for(int i=0;i<=n;i++){
    //     if(!visited2[i]){
    //         g.dfs(i,visited2);
    //     }
    // }

    // if graph is single then use this
    // g.bfs(0);

    // // Cycle is present or not
    // unordered_map<int,bool>visited;
    // bool ans = false;
    // for(int i=0;i<n;i++){
    //     if(!visited[i]){
    //         ans = g.checkCyclicUsingBfs(0,visited);
    //         if(ans == true){
    //             break;
    //         }
    //     }
    // }
    // cout<<endl;
    // if(ans == true){
    //     cout<<"Cycle is Present "<<endl;
    // }
    // else{
    //     cout<<"Cycle is Absent"<<endl;
    // }


    // // checking by using dfs
    // bool ansDfs = false;
    // unordered_map<int,bool>visitedDfs;
    // for(int i=0;i<n;i++){
    //     if(!visited[i]){
    //         ansDfs = g.checkCyclicUsingDfs(i,visitedDfs,-1);
    //         if(ansDfs == true){
    //             break;
    //         }
    //     }
    // }
    // if(ansDfs == true){
    //     cout<<"Cycle is Present"<<endl;
    // }
    // else{
    //     cout<<"Cycle is Absent"<<endl;
    // }

    // return 0;



    Graph<int>g3;
    // int n = 10;
    g3.addEdge(0,1,1);
    g3.addEdge(1,2,1);
    g3.addEdge(1,5,1);
    g3.addEdge(1,6,1);
    g3.addEdge(6,5,1);
    g3.addEdge(2,3,1);
    g3.addEdge(3,7,1);
    g3.addEdge(7,8,1);
    g3.addEdge(8,3,1);
    g3.addEdge(3,4,1);
    // unordered_map<int,bool>visited3;
    // unordered_map<int,bool>dfsVisited;

    // bool ans3 = false;

    // for(int i=0;i<n;i++){
    //     if(!visited3[i]){
    //         ans3 = g3.checkCyclicDirectedGraphUsingDfs(i,visited3,dfsVisited);
    //         if(ans3 == true)
    //             break;
    //     }
    // }

    // if(ans3 == true){
    //     cout<<"Cycle is present"<<endl;
    // }
    // else{
    //     cout<<"Cycle is Absent"<<endl;
    // }


    // topological sort

    Graph<int>g4;
    int n = 8;
    g4.addEdge(0,1,1);
    g4.addEdge(1,2,1);
    g4.addEdge(2,3,1);
    g4.addEdge(3,4,1);
    g4.addEdge(3,5,1);
    g4.addEdge(4,6,1);
    g4.addEdge(5,6,1);
    g4.addEdge(6,7,1);

    // // using dfs
    // unordered_map<int,bool>visited;
    // stack<int>ans;
    // for(int i=0;i<n;i++){
    //     if(!visited[i]){
    //         g4.topoSortDfs(i,visited,ans);
    //     }
    // }
    // cout<<"Topo Sort : "<<endl;
    // while(!ans.empty()){
    //     cout<<ans.top()<<" ";
    //     ans.pop();
    // }

    //// using bfs
    vector<int>ans;
    // either for connect or disconnected
    g4.topoSortBfs(n,ans);
    cout<<"Printing Topological Sort Using BFS: "<<endl;
    for(auto i:ans){
        cout<<i<<" ";
    }cout<<endl;

    // cycle detection using bfs
    if(ans.size() == n){
        cout<<"It is a valid topo sort"<<endl;
    }else{
        cout<<"Cycle Present or invalid topo sort"<<endl;
    }
}

// NOTE: cyclic graph k andr topological sort kbhi complete hota hi ni hai qki vha indegree 0 hoti hi ni

// => cyclic graph k andr topological sort ki length kbhi n k equal nhi hoti hai

// Topological sort hm DAG Graph pr lgate hai means directed acyclic graph k upar

// ab hm cycle detection using bfs kr skte hai
// agr hmhe valid topological sort mil jata hai iska mtlb hai iska mtlb hai cycle absent hai otherwise present