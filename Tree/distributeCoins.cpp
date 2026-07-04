// Problem: Distribute coins in binary tree
// Difficulty: Medium
//platform: Leetcode
// Approach: Bottom-up dfs and Tee DP
// Time: O(n)
// Space: O(1) 

class Solution {
public:

    int dfs(TreeNode* root,int &ans){
        if(!root){
            return 0;
        }

        int left = dfs(root->left,ans);
        int right = dfs(root->right,ans);

        ans+= abs(root->val+left+right-1);

        return (root->val+left+right)-1;
    }
    int distributeCoins(TreeNode* root) {
        
        int ans=0;
        if(!root)return ans;

        dfs(root,ans);

        return ans;
    }
};