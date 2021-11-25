#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printGraph(vector<int> adj[], int V){
    for(int v = 0; v < V; v++){
        cout<<"Adjacency list of the vertex "
            <<v<<"\n head ";
            for(int x: adj[v])
                cout<<"-> "<< x;
            printf("\n");
    }
}

void dfs(vector<int> adj[], int s, vector<bool> &vis){
    vis[s] = true;
    cout<<s<<" ";

    for(auto x: adj[s]){
        if(!vis[x])
            dfs(adj, x, vis);
    }
}

void bfs(vector<int> adj[], int s, vector<bool> &vis){
    queue<int> q;

    q.push(s);
    vis[s] = true;

    while(!q.empty()){
        int u = q.front();
        q.pop();
        cout<<u<<" ";

        for(auto x : adj[u]){
            if(!vis[x]){
                q.push(x);
                vis[x] = true;
            }
        }
    }
}

void topoSort(vector<int> adj[], int V){
    vector<int> in(V, 0);
    queue<int> q;
    
    for(int i=0; i<V; i++){
        for(auto x: adj[i])
            in[x]++;
    }

    for(int i = 0; i<V; i++){
        if(in[i] == 0)
            q.push(i);
    }

    while(!q.empty()){
        int u = q.front();
        q.pop();
        cout<<u<<" ";

        for(auto x : adj[u]){
            in[x]--;
            if(in[x] == 0)
                q.push(x);
        }
    }
}


int main(){
    int V = 5;

    vector<int> adj[V];

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);

    printGraph(adj, V);

    vector<bool> vis(V, false);

    //dfs(adj, 0, vis);

    fill(vis.begin(), vis.end(), false);
    cout<<"\n";

    //bfs(adj, 0, vis);

    topoSort(adj, V);


    

}