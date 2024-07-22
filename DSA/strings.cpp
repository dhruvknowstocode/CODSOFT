#include<iostream>
using namespace std ;
int getlen(char name[]){
    int cnt=0;
    for(int i=0;name[i]!='\0';i++){
        cnt++;
    }
    return cnt;
}
void reverse(char s[],int l){
        int i=0;
        int j=l-1;
        while(i<j){
            swap(s[i],s[j]);
            i++;
            j--;
        }
    }
int main(){
    char name[10];
    cout<<"Enter your name :"<<endl;
    cin>>name;
    cout<<"Your name is :"<<endl;
    cout<<name<<endl;
    int len=getlen(name);
    cout<<"After reverse is: ";
    reverse(name,len);
    cout<<name;
    return 0;
}