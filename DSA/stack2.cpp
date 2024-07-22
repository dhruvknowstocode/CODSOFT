#include<iostream>
using namespace std ;
class stack{
    public:
    int top;
    int *arr;
    int size;
    stack(int size){
        this->size=size;
        top=-1;
        arr=new int[size];
    }
    void push(int element){
        if(size-top>=1){
            top++;
            arr[top]=element;
        }
        else{
            cout<<"Stack Overflow"<<endl;
        }
    }
    void pop(){
        if(top>=0){
            top--;
        }
        else{
            cout<<"Stack Underflow"<<endl;
        }
    }
    int peek(){
        if(top>=0&&top<size){
            return arr[top];
        }
        else{
            return -1;
        }
    }
    bool isempty(){
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
    }
};
int main(){
    return 0;
}