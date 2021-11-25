#include <bits/stdc++.h>
using namespace std;

class Graph{

    int V;
    list<int> *adjlist; 

public:
    Graph(int v){
        V = v;
        adjlist = new list<int>[V];
    }

    void addEdge(int u, int v, bool bidr = true){
        adjlist[u].push_back(v);
        if(bidr)
            adjlist[v].push_back(u);
    }

    void printGraph(){
        for(int i = 0; i< V; i++){
            cout<<i<<"->";
                for(auto x: adjlist[i])
                    cout<<x<<",";
            cout<<endl;
        }
    }    

    void findShortestPath(int src, int dest, vector<int> &bfstra, int &shortestdist, vector<int> &shortestpath){

        queue<int> q;
        bool *vis = new bool[V+1]{0};
        int *dist = new int[V+1]{0};
        int *parent = new int[V+1];

        for(int i = 0; i < V+1; i++)
            parent[i] = -1;

        q.push(src);
        vis[src] = true;

        while(!q.empty()){
            int node = q.front();
            bfstra.push_back(node);
            q.pop();

                for(auto neigh : adjlist[node]){
                    if(!vis[neigh]){
                        q.push(neigh);
                        vis[neigh] = true;
                        parent[neigh] = node;
                        dist[neigh] = dist[node] + 1;
                    }
                }
            }

            cout<<endl;

            shortestdist = dist[dest];

                int temp = dest;
                while(temp != -1){
                    shortestpath.push_back(temp);
                    temp = parent[temp];
                }            
        }

};



int main(){

    int board[50] = {0};
    board[2] = 13;
    board[5] = 2;
    board[9] = 18;
    board[18] = 11;
    board[17] = -13;
    board[20] = -14;
    board[24] = -8;
    board[25] = -10;
    board[32] = -2;
    board[34] = -22;

    Graph g(50);
    
    for(int u = 0; u < 36; u++){
        for(int dice = 1; dice <= 6; dice++){
            int v = u + dice + board[u+dice];
            g.addEdge(u, v, false);
        }
    }

   //g.printGraph();

    int shortestdist = 0;
    vector<int> bfstra;
    vector<int> shortestpath;

    
    g.findShortestPath(0, 36, bfstra, shortestdist, shortestpath);

    cout<<"Shortest distance is : "<<shortestdist<<endl;
    cout<<endl;

    cout<<"Shortest Path : ";
    for(int x : shortestpath)
        cout<<x<<"<-";

    cout<<endl;
    cout<<endl;

    cout<<"BFS TRAVERSAL : ";
    for(int x : bfstra)
        cout<<x<<" ";

    return 0;
}