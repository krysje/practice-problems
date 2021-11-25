#include<bits/stdc++.h>
using namespace std;

void input(map<int,list<int>> &g)
{
    int n,e;
    cin>>n>>e;
    while(e--){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
}

void print(map<int,list<int>> &g){
    for(auto src:g){
        cout<<src.first<<"=>";
        for(int neigh: src.second){
            cout<<neigh<<",";
        }
        cout<<endl;
    }
    cout<<endl;
}

void bfs_helper(int src,map<int,list<int>> &g,map<int,bool> &visited){
    queue<int> q;
    q.push(src);
    while(!q.empty()){
        cout<<q.front()<<" ";
        int cur_node = q.front();
        q.pop();
        for(int neigh:g[cur_node]){
            if(visited[neigh]==false){
                q.push(neigh);
                visited[neigh]=true;
            }
        }
    }
}

void bfs(map<int,list<int>> &g){
    map<int,bool> visited;
    for(auto src:g){
        if(visited[src.first]==false){
            visited[src.first]=true;
            bfs_helper(src.first,g,visited);
        }
    }
}

void dfs_helper(int src,map<int,list<int>> &g,map<int,bool> &visited){
    visited[src]=true;
    cout<<src<<" ";
    for(int neigh:g[src]){
        if(visited[neigh]==false){
            dfs_helper(neigh,g,visited);
        }
    }
}

void dfs(map<int,list<int>> &g){
    map<int,bool> visited;
    for(auto src:g){
        if(visited[src.first]==false){
            dfs_helper(src.first,g,visited);
        }
    }
}

int main()
{
    map<int,list<int>> g;
    input(g);
    cout<<"Graph printing"<<endl;
    print(g);
    cout<<"Graph bfs"<<endl;
    bfs(g);
    cout<<"Graph dfs"<<endl;
    dfs(g);
    return 0;
}