// Problem: Sum of root to leaf binary numbers
// Difficulty: Easy
// Approach: Recursion
// Time: O(n)
// Space: O(1)

class Solution {
public:
    int dfs(TreeNode* root, int curr){
        if(!root)return 0;

        curr = curr*2 + root->val;

        if(!root->left && !root->right){
            return curr;
        }

        return dfs(root->left,curr) + dfs(root->right,curr);
    }
    int sumRootToLeaf(TreeNode* root) {
        
        int ans = dfs(root,0);
        return ans;
    }
};