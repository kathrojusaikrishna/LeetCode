// Problem: Has path sum
// Difficulty: Easy
//platform: Leetcode
// Approach: using recursion
// Time: O(n)
// Space: O(1)

class Solution {
public:

    bool solve(TreeNode* root, int targetSum){
        if(!root)return false;

        if(!root->left && !root->right && root->val == targetSum)return true;

        return solve(root->left, targetSum - root->val) || solve(root->right, targetSum - root->val);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        return solve(root,targetSum);
    }
};