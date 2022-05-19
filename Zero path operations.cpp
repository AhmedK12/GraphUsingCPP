#include<bits/stdc++.h>
using namespace std;
int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        list<int> graph[n];
        vector<int> weights;
        for(int i=0;i<n-1;i++){
            int a,b;cin>>a>>b;
            a=a-1;
            b=b-1;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        for(int i=0;i<n;i++){
            int wi;
            cin>>wi;
            weights.push_back(wi);
        }
    
        int ans=0;
        int i=0;
        for(list<int> listt : graph){
            if(listt.size()>1&&weights[i]!=0)
               ans++;
            i++;
        }
        cout<<ans<<"\n";
    }
    
}