#include<iostream>
#include<stack>
using namespace std ;
class Stack{
    public:
        int top;
        int *arr;
        int size;
    Stack(int size){
        this->size=size;
        arr=new int[size];
        top=-1;
    }    
    void push(int data){
        if(size-top>1){
            top++;
            arr[top]=data;
        }
        else{
            cout<<"Stack OVerflow "<<endl;
        }
    }
    void peek(){
        if(top>=0&&top<size){
            cout<<arr[top]<<endl;
        }
        else{
            cout<<"empty stack"<<endl;
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
    void empty(){
        if(top==-1){
            cout<<"Empty stack"<<endl;
        }
        else{
            cout<<"Not empty"<<endl;
        }
    }  
};
int main(){
    Stack st(5);
    st.push(1);
    st.push(2);
    st.peek();
    st.pop();
    st.peek();
    st.pop();
    st.empty();
    return 0;
}