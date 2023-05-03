
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int vis[N];
vector<int>ans;
vector<int> graph[N];

void dfs(int vertex,int goal,bool signal=false){
    vis[vertex]=1;
    for(auto child:graph[vertex]){

        if(vis[child])continue;
        if(!signal)ans.push_back(child);
        if(child == goal)signal=true;
        dfs(child,goal,signal);
    }
}

int main() {
    int n,m,start,goal;
    cin>>n>>m>>start>>goal;
    for(int i=0; i<m; ++i){
        int p,q;
        cin>>p>>q;
        graph[p].push_back(q);
        graph[q].push_back(p);
    }
    dfs(start,goal);
    for(auto v:ans){
        cout<<v<<" ";
    }
}