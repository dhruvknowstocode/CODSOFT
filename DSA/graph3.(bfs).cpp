#include<iostream>
using namespace std ;
vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    vector<int> ans;
    unordered_map<int,bool> visited;
    queue<int> q;
    q.push(0);
    visited[0]=true;
    while(!q.empty()){
        int front=q.front();
        q.pop();
        ans.push_back(front);
        for(auto i:adj[front]){
            if(!visited[i]){
                q.push(i);
                visited[i]=true;
            }
        }
    }
    return ans;
}
int main(){
    
    return 0;
}
