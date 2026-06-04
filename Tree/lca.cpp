// Problem: Lowest common ancesstor
// Difficulty: Medium
// Approach: recursion
// Time: O(n)
// Space: O(n) 
class Solution {
  public:
  
    bool path(Node* root, vector<Node*>& ans, int num){
        if(!root)return false;
        
        ans.push_back(root);
        
        if(root->data == num)return true;
        
        if(path(root->left,ans,num) || path(root->right,ans,num))return true;
        
        ans.pop_back();
        return false;
    }
    Node* lca(Node* root, int n1, int n2) {
        //  code here
        Node* ans=nullptr;
        vector<Node*>a,b;
        if(!root)return ans;;
        
        path(root,a,n1);
        path(root,b,n2);
        
        for(int i=0;i<min(a.size(),b.size());i++){
            if(a[i]==b[i])ans=a[i];
            
            else break;
        }
        
        return ans;
        
    }
};