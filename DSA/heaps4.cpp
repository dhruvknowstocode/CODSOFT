int countNodes(Node* root){
        if(root==NULL){
            return 0;
        }
        int ans=1+countNodes(root->left)+countNodes(root->right);
        return ans;
    }
    bool isCBT(Node* root,int index,int count){
         if(root==NULL){
             return true;
         }
         if(index>=count){
             return false;
         }
         else{
             bool checkleft=isCBT(root->left,2*index+1,count);
             bool checkright=isCBT(root->right,2*index+2,count);
             return (checkleft&&checkright);
         }
    }
    bool isCompleteBT(Node* root){
        int index=0;
        int count=countNodes(root);
        if(isCBT(root, index, count))
        {
            return true;
        }
        else
        {
            return false;
        }
    }