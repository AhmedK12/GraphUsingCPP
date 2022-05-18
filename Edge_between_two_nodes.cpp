#include<bits/stdc++.h>

using namespace std;

int Distance(list<int> graph[], int source, int destination){
    queue<int> bfs_queue;
    bool visited[100]={false};
    int distance[100]={0};
    distance[source]=0;
    bfs_queue.push(source);
    visited[source] = true;

    while(!bfs_queue.empty()){
        int front = bfs_queue.front();
        bfs_queue.pop();
        for(int i : graph[front]){
            if(visited[i]==false){
                bfs_queue.push(i);
                distance[i] = distance[front]+1;
                visited[i]= true;

            }
        }
    }
    return distance[destination];
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
    cout<<Distance(graph,0,6);
    cout<<"\n";
    

}