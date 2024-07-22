#include<iostream>
#include<queue>
using namespace std ;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};
Node* insertinbst(Node* root,int data){
    if(root==NULL){
        root=new Node(data);
        return root;
    }
    if(data<root->data){
        root->left=insertinbst(root->left,data);
    }
    if(data>root->data){
        root->right=insertinbst(root->right,data);
    }
    return root;
}
void takeinput(Node* &root){
    int data;
    cin>>data;
    while(data!=-1){
        root=insertinbst(root,data);
        cin>>data;
    }
}
void levelordertraversal(Node* &root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp=q.front();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        q.pop();
    }
}
int minval(Node* root){
    if(root==NULL){
        return -1;
    }
    Node* temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp->data;
}
Node *deleteNode(Node *root, int X) {
    if(root==NULL){
        return root;
    }
    if(root->data==X){
        //0child
        if(root->left==NULL&&root->right==NULL){
            delete root;
            return NULL;
        }
        //1child
        //leftchild
        if(root->left!=NULL&&root->right==NULL){
            Node* temp=root->left;
            delete root;    
            return temp;
        }
        //rightchild
        if(root->left==NULL&&root->right!=NULL){
            Node* temp=root->right;
            delete root;
            return temp;
        }
        //2child
        if(root->left!=NULL&&root->right!=NULL){
            int min=minval(root->right);
            root->data=min;
            root->right=deleteNode(root->right,min);
            return root;
        }
    }
    else if(X<root->data){
        root->left=deleteNode(root->left,X);
        return root;
    }
    else{
        root->right=deleteNode(root->right,X);
        return root;
    }
}

bool searchInBST(BinaryTreeNode<int> *root, int x) {
    if(root==NULL){
        return false;
    }
    if(root->data==x){
        return true;
    }
    if(x<root->data){
        return searchInBST(root->left,x);
    }
    if(x>root->data){
        return searchInBST(root->right,x);
    }
}
int main(){
    Node* root=NULL;
    cout<<"Enter the data ";
    takeinput(root);
    cout<<"Bfs traversal is: "<<endl;
    levelordertraversal(root);
    return 0;
}