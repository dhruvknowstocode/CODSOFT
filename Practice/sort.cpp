#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=next;
    }
};
void insert(Node* &head,Node* &tail,int data,int position){
    if(position==1){
        Node* temp=new Node(data);
        temp->next=head;
        head=temp;
        tail=temp;
        return;
    }
    else{
        Node* temp=head;
        int cnt=1;
        while(cnt<position-1){
            temp=temp->next;
            cnt++;
        }
        if(temp->next==NULL){
            Node* nodetoinsert=new Node(data);
            temp->next=nodetoinsert;
            nodetoinsert->next=NULL;
            tail=tail->next;
        }
        else{
            Node* nodetoinsert=new Node(data);
            nodetoinsert->next=temp->next;
            temp->next=nodetoinsert;
        }
    }
}
void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main() {
    Node* head=NULL;
    Node* tail=NULL;
    insert(head,tail,1,1);
    insert(head,tail,1,1);
    insert(head,tail,0,3);
    insert(head,tail,2,4);
    insert(head,tail,1,5);
    insert(head,tail,2,6);
    insert(head,tail,0,7);
    return 0;
}