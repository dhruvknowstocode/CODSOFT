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
Node* add(Node* head1,Node* head2){
    Node* ptr1=head1;
    Node* ptr2=head2;
    Node* root=ptr1;
    while(ptr1->next!=NULL){
        ptr1=ptr1->next;
    }
    ptr1->next=ptr2;
    return root;
}
int main(){
    Node* head1=NULL;
    Node* head2=NULL;
    Node* tail1=NULL;
    Node* tail2=NULL;
    insert(head1,tail1,1,1);
    insert(head1,tail1,2,2);
    insert(head1,tail1,3,3);
    insert(head1,tail1,4,4);
    insert(head2,tail2,5,1);
    insert(head2,tail2,6,2);
    insert(head2,tail2,7,3);
    insert(head2,tail2,8,4);
    print(head1);
    print(head2);
    Node* ans=add(head1,head2);
    print(ans);
    return 0;
}