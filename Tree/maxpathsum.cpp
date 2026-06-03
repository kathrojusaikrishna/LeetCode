// Problem: Maximum path sum
// Difficulty: Hard
//platform: Leetcode
// Approach: using recursion
// Time: O(n)
// Space: O(1)

class Solution {
public:

    int solve(TreeNode* root, int &ans){

        if(!root)return 0;
        int leftMax = max(0,solve(root->left,ans));
        int rightMax = max(0,solve(root->right,ans));

        ans = max(ans,root->val+leftMax+rightMax);
        return root->val + max(leftMax, rightMax);
    }
    int maxPathSum(TreeNode* root) {
        
        int ans=INT_MIN;
        solve(root,ans);
        return ans;
    }
};