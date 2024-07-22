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
bool check(vector<int> arr){
    int s=0;
    int e=arr.size()-1;
    while(s<e){
        if(arr[s]!=arr[e]){
            return 0;
        }
        else{
            s++;
            e--;
        }
    }
}
bool checkpal(Node* head){
    vector<int> arr;
    Node* temp=head;
    while(temp!=NULL){
        arr.push_back(temp->data);
        temp=temp->next;
    }
    return check(arr);
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