#include<iostream>
#include<stack>
using namespace std ;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=next;
    }
};
class Stack{
    public:
    Node* top;
    Stack(){
        top=NULL;
    }
    void push(int data){
        Node* temp=new Node(data);
        temp->next=top;
        top=temp;
    }
    void pop(){
        if(top==NULL){
            cout<<"Empty Stack";
        }
        else{
            Node* temp=top;
            top=top->next;
            delete temp;
        }
    }
    void peek(){
        if(top!=NULL){
            cout<<top->data;
        }
        else{
            cout<<"-1";
        }
    }
    void isempty(){
        if(top==NULL){
            cout<<"Empty stack";
        }
        else{
            cout<<"Not empty";
        }
    }
};
int main(){
    Stack st(5);
    st.push(1);
    st.peek();
    return 0;
}