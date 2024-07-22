#include<iostream>
#include<vector>
using namespace std ;
class graph{    
    public:
    vector<vector<int>> mat;
    graph(int n) {
        mat.assign(n, vector<int>(n, 0));
    }
    void addedge(int u,int v,bool direction){
            mat[u][v]=1;
            if(direction==0){
                mat[v][u]=1;
            }
    }
    void print(int v){
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                cout<<"["<<i<<"]"<<"["<<j<<"]"<<"="<<mat[i][j];
                cout<<endl;
            }
        }
    }
};
int main(){
    int n;
    cout<<"Enter number of nodes :";
    cin>>n;
    int m;
    cout<<"Enter number of edges :";
    cin>>m;
    graph g(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g.addedge(u,v,0);
    }
    g.print(n);
    return 0;
}