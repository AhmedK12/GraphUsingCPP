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

void allpaths(list<int> graph[],vector<int> &path, int destination){

    int node1 = path.back();
    if(node1==destination)
       printgraph(path);
    vector<int> newpath;
    for(int node : graph[node1]){
         newpath = path;
         newpath.push_back(node);
         if(check_path(newpath)){
             allpaths(graph,newpath,destination);
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
    vector<int> vec;
    vec.push_back(0);
    allpaths(graph,vec,6);
    // vector<int> vec = {1,2,3,4};
    // cout<<check_path(vec);
    
    
}       