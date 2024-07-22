#include<iostream>
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
        if(temp->next==NULL){
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
Node* merge(Node* head1,Node* head2){
    Node* root=new Node(-1);
    Node* tail=root;
    if(head1->data<head2->data){
        tail->next=head1;
        head1=head1->next;
        tail=tail->next;
    }
    else{
        tail->next=head2;
        head2=head2->next;
        tail=tail->next;
    }
    while(head2!=NULL&&head1!=NULL){
        if(head1->data>head2->data){
            tail->next=head2;
            head2=head2->next;
            tail=tail->next;
        }
        else if(head1->data<head2->data){
            tail->next=head1;
            head1=head1->next;
            tail=tail->next;
        }
    }
    return (root->next);
}
int main(){
    Node* head1=NULL;
    Node* head2=NULL;
    Node* tail1=NULL;
    Node* tail2=NULL;
    insert(head1,tail1,1,1);
    insert(head1,tail1,3,2);
    insert(head1,tail1,5,3);
    insert(head1,tail1,7,4);
    insert(head2,tail2,2,1);
    insert(head2,tail2,4,2);
    insert(head2,tail2,6,3);
    insert(head2,tail2,8,4);
    print(head1);
    print(head2);
    Node* ans=merge(head1,head2);
    print(ans);
    return 0;
}