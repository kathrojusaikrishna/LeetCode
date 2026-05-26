
// Problem: check if tree is balanced
// Difficulty: Easy
// Approach: recursion
// Time: O(h)
// Space: O(1)

class Solution {
  public:
  
    int height(Node* root){
        
        if(!root)return -1;
        
        int left = height(root->left);
        int right = height(root->right);
        
        return 1+max(left,right);
    }
    
    
    bool solve(Node* root){
        if(!root)return true;
        
        int left = height(root->left);
        int right = height(root->right);
        
        if(abs(left - right)>1)return false;
        
        return solve(root->left) && solve(root->right);
    }
    
    bool isBalanced(Node* root) {
        // code here
        
        return solve(root);
        
    }
};