#include<iostream>
using namespace std ;
class Node{
    public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
class stack{
    public:
    Node* top;
    stack(){
        top=NULL;
    }
    void push(int data){
        Node* temp=new Node(data);
        temp->next=top;
        top=temp;
    }
    void pop(){
        if(top == NULL){
            cout << "Stack UnderFlow!" << endl;
        }
        else{
            Node *temp = top;
            top = top->next;
            delete temp;
        }
    }
    int peek(){
        if(top!=NULL){
            return top->data;
        }
        else{
            return -1;
        }
    }
    bool isempty(){
        if(top==NULL){
            return true;
        }
        else{
            return false;
        }
    }
    void print(){
        Node* temp=top;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
};
int main(){
    stack s;
    int ch;
    while(1){
        cout << "Menu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Check if stack is empty\n";
        cout << "5. Print stack\n";
        cout << "6. Quit\n";
        cout << "Enter your choice: ";
        cin >> ch;
        if(ch==1){
            int data;
            cout<<"Enter data to be pushed :";
            cin>>data;
            s.push(data);
            cout<<"Pushed"<<data<<"On the stack"<<endl;
        }
        else if(ch==2){
            if(!s.isempty()){
                cout << "Popped " << s.peek() << " from the stack."<<endl;
                s.pop();
            }
            else{
                cout<<"Stack is empty "<<endl;;
            }
        }
        else if(ch == 3) {
            if(!s.isempty()){
                cout << "Top element of the stack: " << s.peek() << endl;
            } else {
                cout <<"Stack is empty."<<endl;
            }
        } 
        else if(ch == 4) {
            if (s.isempty()) {
                cout << "Stack is empty.\n";
            } else {
                cout << "Stack is not empty.\n";
            }
        } 
        else if (ch == 5) {
            cout << "Stack elements: ";
            s.print();
            cout << endl;
        } 
        else if (ch == 6) {
            cout << "Exiting the program.\n";
            break; // Exit the while loop
        } 
        else {
            cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}