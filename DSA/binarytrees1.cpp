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
Node* buildtree(Node* root){
    cout<<"Enter the data="<<endl;
    int data;
    cin>>data;
    if(data==-1){
        return NULL;
    }
    root=new Node(data);
    cout<<"Enter value of data to be inserted in left of "<<data<<endl;
    root->left=buildtree(root->left);
    cout<<"Enter value of right to be inserted in right of"<<data<<endl;
    root->right=buildtree(root->right);
    return root;
}
void levelordertraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if (!q.empty()) {
                q.push(NULL); // Mark the end of the next level
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
    }
}
void inorder(Node* root){
    if(root==NULL){
        return ;
    }
    inorder(root->left);
    cout<<root->data;
    inorder(root->right);
}
void preorder(Node* root){
    if(root==NULL){
        return ;
    }
    cout<<root->data;
    preorder(root->left);    
    preorder(root->right);
}
void postorder(Node* root){
    if(root==NULL){
        return ;
    }
    postorder(root->left);    
    postorder(root->right);
    cout<<root->data
}
//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
int main(){
    Node* root=NULL;
    root=buildtree(root);
    cout<<"BFS traversal is :"<<endl;
    levelordertraversal(root);
    cout<<endl;
    cout<<"inorder traversal is :"<<endl;
    inorder(root);
    cout<<"preorder traversal is :"<<endl;
    preorder(root);
    cout<<"postorder traversal is :"<<endl;
    postorder(root);
    return 0;
}