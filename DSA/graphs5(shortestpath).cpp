#include<iostream>
#include<list>
#include<unordered_map>
#include<stack>
#include<limits.h>
#include<vector>
using namespace std ;
class graph{
    public:
    unordered_map<int,list<pair<int,int>>> adj;
    void addedge(int u,int v,int weight){
        adj[u].push_back({v,weight});
    }
    void printedge(){
        for(auto i:adj){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<"("<<j.first<<","<<j.second<<")"<<",";
            }
            cout<<endl;
        }
    }
    void dfs(int n,unordered_map<int,bool> &visited,stack<int> &s){
        visited[n]=true;
        for(auto i:adj[n]){
            if(!visited[i.first]){
                dfs(i.first,visited,s);
            }
        }
        s.push(n);
    }
    void shortestpath(int src,vector<int> &distance,stack<int> &s){
        distance[src]=0;
        while(!s.empty()){
            int topa=s.top();
            s.pop();
            if(distance[topa]!=INT_MAX){
                for(auto i:adj[topa]){
                    if(distance[topa]+i.second<distance[i.first]){
                        distance[i.first]=distance[topa]+i.second;
                    }
                }
            }
        }
    }
};
int main(){
    graph g;
    g.addedge(0,1,5);
    g.addedge(1,3,6);
    g.addedge(3,4,-1);
    g.addedge(4,5,-2);
    g.addedge(2,5,2);
    g.addedge(2,4,4);
    g.addedge(2,3,7);
    g.addedge(1,2,2);
    g.addedge(0,2,3);
    unordered_map<int,bool> visited;
    stack<int> s;
    for(int i=0;i<6;i++){
        if(!visited[i]){
            g.dfs(i,visited,s);
        }
    }
    g.printedge();
    vector<int> distance(6);
    for(int i=0;i<6;i++){
        distance[i]=INT_MAX;
    }
    int src=1;
    g.shortestpath(src,distance,s);
    cout<<"Answer is :"<<endl;
    for(int i=0;i<6;i++){
        cout<<distance[i]<<" ";
    }
    return 0;
}