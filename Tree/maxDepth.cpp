// Problem: Maximum depth of a binary tree
// Difficulty: Easy
//platform: Geeksforgeeks
// Approach: using recursion
// Time: O(n)
// Space: O(1)

class Solution {
  public:
    int solve(Node* root){
        if(!root)return 0;
        
        int left = solve(root->left);
        int right = solve(root->right);
        
        return 1+max(left,right);
    }
    int maxDepth(Node *root) {
        // code here
        
        int ans = solve(root);
        
        return ans;
    }
};
