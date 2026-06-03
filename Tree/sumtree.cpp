// Problem: Sum Tree
// Difficulty: Easy
//platform: Geeksforgeeks
// Approach: using recursion
// Time: O(n)
// Space: O(h)

class Solution {
  public:
  
    int solve(Node* root){
        
        if(!root)return 0;
        
        int oldVal = root->data;
        
        int left = solve(root->left);
        int right = solve(root->right);
        
        root->data = left+right;
        
        return oldVal + left+right;
        
        
    }
    void toSumTree(Node *root) {
        // code here
        
        solve(root);
    }
};