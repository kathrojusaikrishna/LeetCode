// Problem: House Robber III
// Difficulty: Medium
//platform: Leetcode
// Approach: using Tree DP (Bottom-down dfs)
// Time: O(n)
// Space: O(1)

class Solution {
public:
    
    struct info{
        int rob;
        int skip;
    };

    info dfs(TreeNode* root){
        if(!root)return{0,0};

        if(!root->left && !root->right){
            return {root->val,0};
        }
        info left = dfs(root->left);
        info right = dfs(root->right);

        return {root->val + left.skip + right.skip, max(left.skip,left.rob)+ max(right.skip,right.rob)};
    }

    int rob(TreeNode* root) {
        return max(dfs(root).rob,dfs(root).skip);
    }
};