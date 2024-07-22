class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root==NULL){
          return result;
        }       
        queue<TreeNode*> q;
        q.push(root);
        bool lefttoright=true;
        while(!q.empty()){
            int levelsize=q.size();
            vector<int> currentlvl(levelsize);
            for(int i=0;i<levelsize;i++){
              TreeNode* frontnode=q.front();
              q.pop();
              int index;
              if (lefttoright) {
                index = i;
              } 
              else{
                index = levelsize - 1 - i;
              }
              currentlvl[index] = frontnode->val;
              if(frontnode->left!=NULL){
                q.push(frontnode->left);
              }
              if(frontnode->right!=NULL){
                q.push(frontnode->right);
              }
            }             
            result.push_back(currentlvl);
            lefttoright=!lefttoright;
        }
        return result;
    }
    vector<int> verticalOrder(Node *root){
        vector<int> ans;
        map<int,map<int,vector<int>>> nodes;
        queue<pair<Node*,pair<int,int>>> q;
        q.push(make_pair(root,make_pair(0,0)));
        while(!q.empty()){
            pair<Node*,pair<int,int>> temp=q.front();
            q.pop();
            Node* frontnode=temp.first;
            int hd=temp.second.first;
            int lvl=temp.second.second;
            nodes[hd][lvl].push_back(frontnode->data);
            if(frontnode->left){
                q.push(make_pair(frontnode->left,make_pair(hd-1,lvl+1)));
            }
            if(frontnode->right){
                q.push(make_pair(frontnode->right,make_pair(hd+1,lvl+1)));
            }
        }
        for(auto i:nodes){
            for(auto j:i.second){
                for(auto k:j.second){
                    ans.push_back(k);
                }
            }
        }
        return ans;
    } };