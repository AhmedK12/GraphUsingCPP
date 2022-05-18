#include<bits/stdc++.h>
using namespace std;
bool visited[100]{false};

void DFS(list<int> graph[], int source){

    visited[source] = true;
    cout<<source<<endl;
    for(int node : graph[source]){
        if(visited[node]==false)
           DFS(graph,node);
    }

}

void add(list<int> graph[],int a,int b){
graph[a].push_back(b);
graph[b].push_back(a);
}

int main(){

    list<int> graph[7];// bydirectional
    add(graph,0,1);
    add(graph,0,2);     
    add(graph,0,4);
    add(graph,4,3);
    add(graph,4,5);
    add(graph,4,6);
    
    add(graph,2,5);
    
    DFS(graph,0);
    cout<<"\n";
    

}