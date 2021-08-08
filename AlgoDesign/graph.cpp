//Undireected Graph
//Adjacency List

#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adjList[], int u, int v){
    adjList[u].push_back(v);
    adjList[v].push_back(u);
} 

void print(vector<int> adjList[], int n){
    for(int i = 0; i < n; i++){
        cout<<"\nAdjacency List " <<i<<"\n Head ";
        for(auto x : adjList[i]){
            cout<<"-> "<<x;
            printf("\n");
        }
    }
}

int main(){

    int n = 5;
    vector<int> adjList[n];
    addEdge(adjList, 0, 1);
    addEdge(adjList, 1, 2);
    addEdge(adjList, 0, 4);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 1, 4);
    addEdge(adjList, 2, 3);
    addEdge(adjList, 3, 4);
    print(adjList, n);
    return 0;
}