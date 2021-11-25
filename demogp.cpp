#include <bits/stdc++.h>
using namespace std;

template<typename T>

class Graph{
    
    map<T, list<T>> adjlist;

public:

    Graph(){}

    void addEdge(T u, T v, bool bider = true){
        adjlist[u].push_back(v);
        if(bider)
            adjlist[v].push_back(u);
    }

    void printGraph(){

        for(auto src : adjlist){
            cout<<src.first<<"->";

            for(auto neigh : src.second)
                cout<<neigh<<",";
          cout<<endl;
        }
    }


};


int main(){

    Graph<string> g;
    g.addEdge("Delhi", "Jaipur");
    g.addEdge("Amritsar", "Delhi");
    g.addEdge("Amritsar", "Jaipur");
    g.addEdge("Amritsar", "Siachen");
    g.addEdge("Jaipur", "Agra");

    g.printGraph();

    return 0;
}