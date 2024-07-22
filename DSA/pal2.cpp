#include<iostream>
#include<vector>    
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
void insert(Node* &head,Node* &tail,int d,int pos){
    if(pos==1){
        Node* nodetoinsert=new Node(d);
        nodetoinsert->next=head;
        head=nodetoinsert;
        tail=nodetoinsert->next;
    }
    else{
        Node* temp=head;
        int cnt=1;
        while(cnt<pos-1){
            temp=temp->next;
            cnt++;
        }
        if(temp->next=NULL){
            Node* nodetoinsert=new Node(d);
            nodetoinsert->next=temp->next;
            temp->next=nodetoinsert;
            tail=temp->next;
        }
        else{
            Node* nodetoinsert=new Node(d);
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
Node* getmid(Node* head){
    Node* slow=head;
    Node* fast=head->next;
    while(fast!=NULL&&fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}
Node* reverse(Node* head){
    Node* curr=head;
    Node* prev=NULL;
    Node* forward=NULL;
    while(curr!=NULL){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    return prev;
}
bool checkpal(Node* head){
    Node* mid=getmid(head);
    Node* temp=mid->next;
    mid->next=reverse(temp);
    Node* head1=head;
    Node* head2=mid->next;
    while(head2!=NULL){
        if(head1->data!=head2->data){
            return 0;
        }
        head1=head1->next;
        head2=head2->next;
    }
    return 1;
}
int main(){   
    Node* head=NULL;    
    Node* tail=NULL;    
    insert(head,tail,1,1);
    insert(head,tail,0,2);
    insert(head,tail,2,3);
    insert(head,tail,0,4);
    insert(head,tail,1,5);
    print(head);
    if(checkpal(head)){
        cout<<"palindrome";
    }
    else{
        cout<<"not palindrome";
    }
    return 0;
}