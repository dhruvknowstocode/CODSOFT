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
void levelorder(Node* &root){
    queue<Node*> q;
    int data;
    cout<<"Enter data =";
    cin>>data;
    root=new Node(data);
    q.push(root);
    while(!q.empty()){   
        Node* temp=q.front();
        int leftdata;
        cout<<"Enter data inserted left of :"<<temp->data<<endl;
        cin>>leftdata;
        if(leftdata!=-1){
            Node* lefty=new Node(leftdata);
            temp->left=lefty;
            q.push(lefty);
        }   
        int rightdata;
        cout<<"Enter data inserted right of :"<<temp->data<<endl;
        cin>>rightdata;
        if(rightdata!=-1){
            Node* righty=new Node(rightdata);
            temp->right=righty; 
            q.push(righty);
        }
        q.pop();   
    }
}
int inorder(Node* &root,int& cnt){
    if(root==NULL){
        return 0;
    }
    inorder(root->left,cnt);
    if(root->left==NULL&&root->right==NULL){
        cnt++;
    }
    inorder(root->right,cnt);
    return cnt;
}
int countLeaves(Node* root){
  int cnt=0;
  inorder(root,cnt);
  return cnt;
}
int height(Node* node){
        if(node==NULL){
            return 0;
        }
        int leftsubtree=height(node->left);
        int rightsubtree=height(node->right);
        int ans=max(leftsubtree,rightsubtree)+1;
        return ans;
    }
    int height(struct Node* node){
        if(node==NULL){
            return 0;
        }
        int leftsubtree=height(node->left);
        int rightsubtree=height(node->right);
        int ans=max(leftsubtree,rightsubtree)+1;
        return ans;
    }
    pair<int,int> fastdiameter(Node* root){
        if(root==NULL){
            return {0,0};
        } 
        pair<int,int> left=fastdiameter(root->left);
        pair<int,int> right=fastdiameter(root->right);
        int op1=left.first;
        int op2=right.first;
        int op3=left.second+right.second+1;
        pair<int,int> ans;
        ans.first=max(op1,max(op2,op3));
        ans.second=max(left.second,right.second)+1;
        return ans;
    }
    int diameter(Node* root) {
        return fastdiameter(root).first;
    }
    pair<int,bool> check(Node* root){
        if(root==NULL){
            return {0,true};
        }
        pair<int,bool> lefttree=check(root->left);
        pair<int,bool> righttree=check(root->right);
        int hleft=lefttree.first;
        int hright=righttree.first;
        pair<int,bool> ans={0,false};
        int op3=max(hleft,hright)+1;
        if(lefttree.second&&righttree.second&&(abs(hleft-hright))<=1){
            ans.second=true;
        }
        ans.first=op3;
        return ans;
    }
    bool isBalanced(Node *root){
        return check(root).second;
    }
    bool isIdentical(Node *r1, Node *r2){
        if (r1 == NULL && r2 == NULL) {
            return true;
        }
        if (r1 == NULL || r2 == NULL) {
            return false;
        }
        if (r1->data != r2->data) {
            return false;
        }
        bool left=isIdentical(r1->left,r2->left);
        bool right=isIdentical(r1->right,r2->right);
        bool ans=false;
        if(left&&right){
            ans=true;
        }
        return ans;
    }
};
int main(){
    Node* root=NULL;
    levelorder(root);
    return 0;
}