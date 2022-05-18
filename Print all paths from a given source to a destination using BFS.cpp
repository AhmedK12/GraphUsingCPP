#include<bits/stdc++.h>
using namespace std;

bool check_path(vector<int> &path){
unordered_set<int> set;
for(int i:path){
   if(set.find(i)==set.end()){
       set.insert(i);
   }
   else{
       return false;
   }
}
return true;
}


void printgraph(vector<int> &path){
   for(int i : path){
       cout<<i<<" ";
   }
   cout<<endl;
}

void extende_bfs(int sources,int destination, list<int> graph[]){
   queue<vector<int>> bfsqueue;
   vector<int> path;
   path.push_back(sources);

   bfsqueue.push(path);
   while(!bfsqueue.empty()){
      path = bfsqueue.front();
      int node = path.back();
      vector<int> newpath;
      if(node == destination)
         printgraph(path);
      bfsqueue.pop();
      for(int i : graph[node]){
           newpath = path;
           newpath.push_back(i);
        //    printgraph(newpath);
           if(check_path(newpath))
             bfsqueue.push(newpath);
           
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
    add(graph,1,2);
    extende_bfs(0,6,graph);
    // vector<int> vec = {1,2,3,4};
    // cout<<check_path(vec);
    
    
}       