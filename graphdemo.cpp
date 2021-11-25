#include <bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    
    list<int> *adjlist;
    bool *vis;
 
public:
    Graph(int v){
        V = v;
        adjlist = new list<int>[v];
        vis = new bool[v+1]{0};
    }

    void addEdge(int u, int v, bool bidr = true){
        adjlist[u].push_back(v);
        if(bidr)
            adjlist[v].push_back(u);
    }

    void printGraph(){

        for(int i = 0; i < V; i++){
            cout<<i<<"->";
            for(auto node : adjlist[i])
                cout<<node<<",";
            cout<<endl;
        }
    }

    void bfs(int src, int dest){

        queue<int> q;
        bool *vis = new bool[V+1]{0};

        int *dist = new int[V+1]{0};
        int *parent = new int[V+1];

        for(int i = 0; i < V; i++)
            parent[i] = -1;



        q.push(src);
        vis[src] = true;

        while(!q.empty()){
            int node = q.front();
            cout<<node<<" ";   
            q.pop();

            for(int neighbor : adjlist[node]) {
                if(!vis[neighbor]){
                    q.push(neighbor);
                    vis[neighbor] = true;
                    dist[neighbor] = dist[node] + 1;
                    parent[neighbor] = node;
                }
            }
        }
            cout<<endl;
        // Print the distances of every node from source

            for(int i = 0;  i < V; i++)
                cout<<i<<" Node having dist "<<dist[i]<<" "<<endl;

        int temp = dest;
        
        while(temp != -1){
            cout<<temp<<"<-";
            temp = parent[temp];
        }

    }

    void dfs(int src){

        cout<<src<<" ";
        vis[src] = true;

        for(int x : adjlist[src]){
            if(!vis[x])
                dfs(x);
        }
    }
};


int main(){
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 4);
    g.addEdge(0, 4);
    g.addEdge(2, 3);
    g.addEdge(4, 3);
    g.addEdge(3, 5);

    //g.printGraph();

    //cout<<endl;

   // g.bfs(0, 5);
    g.dfs(0);
    return 0;

}