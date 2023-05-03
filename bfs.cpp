
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int vis[N];
vector<int> graph[N];


int main() {
    int n,m,start,goal;
    cin>>n>>m>>start>>goal;
    for(int i=0; i<m; ++i){
        int p,q;
        cin>>p>>q;
        graph[p].push_back(q);
        graph[q].push_back(p);
    }
    
    queue<int>q;
    q.push(start);
    vis[start]=1;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout<<node<<" ";
        if(node==goal)break;
        for(auto child:graph[node]){
            if(vis[child])continue;
            vis[child]=1;
            q.push(child);
        }
    }
}