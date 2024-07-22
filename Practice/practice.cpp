#include<bits/stdc++.h>
using namespace std;

void mul(int mat1[][2],int mat2[][2]){
    int rslt[2][2];
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            rslt[i][j]=0;
            for(int k=0;k<2;k++){
                rslt[i][j]+=mat1[i][k]*mat2[k][j];
            }
            cout<<rslt[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main() {
    int mat1[2][2] = { { 4, 4 },
                        { 5, 3 } };
    int mat2[2][2] = { { 4, 7 },
                        { 6, 2 } };
    mul(mat1, mat2);                
    return 0;
}