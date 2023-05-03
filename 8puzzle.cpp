
#include<bits/stdc++.h>
using namespace std;

const vector<int> dr = {0, 0, -1, 1} ;
const vector<int> dc = {1, -1, 0, 0} ;

vector<vector<vector<int>>> path ;

void dfs(vector<vector<int>>& initial,vector<vector<int>>& goal,int& r, int& c, set<vector<vector<int>>>& vis, bool& found)
{
    if(vis.find(initial)!=vis.end())
        return;
    vis.insert(initial);
    if(initial == goal){
        found = true;
        path.push_back(initial);
        return;
    }
    for(int i=0; i<4; ++i){
        int newr = r+dr[i];
        int newc = c+dc[i];
        if(newr >= 0 && newr < 3 && newc >= 0 && newc < 3){
            swap(initial[r][c],initial[newr][newc]);
            dfs(initial,goal,newr,newc,vis,found);
            swap(initial[r][c],initial[newr][newc]);
            if(found){
                path.push_back(initial);
                return;
            }
        }
    }

}

void bfs(vector<vector<int>>& initial,vector<vector<int>>& goal,int& r, int& c, set<vector<vector<int>>>& vis, bool& found){
    queue<vector<vector<int>>>q;
    q.push(initial);
    while(!q.empty()){
        vector<vector<int>> matrix = q.front();
        q.pop();
        vis.insert(matrix);
        path.push_back(matrix);
        if(matrix==goal){
            found = true;
            return;
        }
        for(int i=0; i<4; ++i){
            int newr = r+dr[i];
            int newc = c+dc[i];
            if(newr >= 0 && newr < 3 && newc >= 0 && newc < 3){
                swap(matrix[r][c],matrix[newr][newc]);
                if(vis.find(matrix)!= vis.end())continue;
                q.push(matrix);
            }
        }
    }
}

int main() {

    vector<vector<int>> initial(3, vector<int>(3)) ;
    vector<vector<int>> final(3, vector<int>(3)) ;

    cout<<"enter 0 for BFS and 1 for DFS: ";
    int method;
    cin>> method;
    cout<<endl;

    for(int i = 0; i<3; i++)
        for(int j = 0; j<3; j++)
            cin >> initial[i][j] ;
    for(int i = 0; i<3; i++)
        for(int j = 0; j<3; j++)
            cin >> final[i][j] ;

    set<vector<vector<int>>> visited ;

    bool found = false ;
    int indexi=0,indexj=0;


    switch(method){
    case 0:
        bfs(initial,final,indexi,indexj,visited,found);
        break;
    case 1:
        dfs(initial,final,indexi,indexj,visited,found);
        break;
    default:
        cout<< "Enter correct option";
    }
    

    if(!found) {
        cout << "Not possible\n" ;
        return 0;
    }

    reverse(path.begin(), path.end()) ;

    for(auto &i : path) {
        for(int j = 0; j<3; j++) {
            for(int k = 0; k<3; k++) {
                cout << i[j][k] << ' ' ;
            }
            cout << '\n' ;
        }

        cout << '\n' ;
    }

}