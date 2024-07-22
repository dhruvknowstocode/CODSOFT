void findpath(Node* root,int node,vector<int> &path,bool &check){
    if(root==NULL&&check!=true){
        return ;
    }
    path.push_back(root->data);
    if (root->data == node) {
        check=true;
        return;
    }
    if (root->left&&check!=true){
        findpath(root->left, node, path,check);
    }
    if(root->right&&check!=true){
        findpath(root->right,node,path,check);
    }
    if(check!=true){
    path.pop_back();
    }
}
int kthAncestor(Node *root, int k, int node){
    vector<int> path;
    bool check=false;
    findpath(root,node,path,check);
    if (k >= path.size()) {
        return -1; 
    }
    return path[path.size()-k-1];
}
 