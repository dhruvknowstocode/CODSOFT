#include<iostream>
#include<list>
#include<unordered_map>
#include<vector>
using namespace std ;
void addedge(int u,int v,vector<vector<int>> &ans){
    ans[v].push_back(u);
    ans[u].push_back(v);
}
void print(vector<vector<int>> arr){
    for(int i=0;i<arr.size();i++){
        cout << "Adjacency list of node " << i << ": ";
        for(int j=0;j<arr[0].size();j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int n;
    cout<<"Enter number of nodes :";
    cin>>n;
    int m;
    cout<<"Enter number of edges :";
    cin>>m;
    vector<vector<int>> ans(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        addedge(u,v,ans);
    }
    print(ans);
    return 0;
}