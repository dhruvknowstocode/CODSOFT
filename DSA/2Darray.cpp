#include <iostream>
using namespace std;
int main() {
    int row;
    cout<<"enter value row"<<endl;;
    cin>>row;
    int col;
    cout<<"enter value col"<<endl;
    cin>>col;
    int **arr=new int*[row];
    for(int i=0;i<row;i++){
        arr[i]=new int[col];
    }
    cout<<"Enter your elements :";
    for(int i=0;i<row;i++){
        for(int j=0;j<row;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<row;j++){
            cout<<arr[i][j];
        }
        cout<<endl;
    }
    return 0;
}