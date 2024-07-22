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
int count(Node* head,int target){
    Node* temp=head;
    int cnt=0;
    while(temp!=NULL){
        if(temp->data==target){
            cnt++;
        }
        temp=temp->next;
    }
    return cnt;
}
Node* sort(Node* &head){
    int zerocnt=count(head,0);
    int onecnt=count(head,1);
    int twocnt=count(head,2);
    Node* temp=head;
    while(temp!=NULL){
        if(zerocnt>0){
            temp->data=0;
            zerocnt--;
        }
        else if(onecnt>0){
            temp->data=1;
            onecnt--;
        }
        else{
            temp->data=2;
            twocnt--;
        }
        temp=temp->next;
    }
    return head;
}
void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
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
    sort(head);
    print(head);
    return 0;
}