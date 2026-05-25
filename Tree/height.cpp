// Problem: Height of the tree
// Difficulty: Easy
// Approach: recursion
// Time: O(n)
// Space: O(1)

class Solution {
  public:
  
    int solve(Node* root, int &ans){
        
        if(!root)return -1;
        
        int left = solve(root->left,ans);
        int right = solve(root->right, ans);
        
        return 1+max(left,right);
    }  
    int height(Node* root) {
        // code here
        
        int ans = solve(root,ans);
        
        return ans;
    }
};