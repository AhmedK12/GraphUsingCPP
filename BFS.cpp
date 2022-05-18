#include<bits/stdc++.h>

using namespace std;

void BFS(list<int> graph[],int source,int size){
    bool visited[size] = {false};
    queue<int> bfs_queue;
    bfs_queue.push(source);
    visited[source] = true;
    while(!bfs_queue.empty()){
        int front = bfs_queue.front();
        bfs_queue.pop();
        cout<<front<<" ";
        for(int node : graph[front]){
            if(visited[node]==false){
                 bfs_queue.push(node);
                 visited[node] = true;
            }
        }
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
    BFS(graph, 0,7);
    cout<<"\n";
    

}