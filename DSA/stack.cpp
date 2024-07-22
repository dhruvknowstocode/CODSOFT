#include<iostream>
#include<stack>
using namespace std ;
int main(){
    stack<int> s;
    for(int i=0;i<4;i++){
        s.push(i);
    }
    cout<<s.top();
    return 0;
}