// Problem: Count the good nodes.
// Difficulty: Medium
//platform: Leetcode
// Approach: using top-down dfs
// Time: O(n)
// Space: O(1)

class Solution {
public:

    void solve(TreeNode* root, int maxValseen, int &ans){
        if(!root)return;

        if(root->val >= maxValseen)ans++;

        maxValseen = max(maxValseen,root->val);

        solve(root->left,maxValseen,ans);
        solve(root->right,maxValseen,ans);
    }
    int goodNodes(TreeNode* root) {
        int ans=0;
        if(!root)return ans;
        solve(root,root->val,ans);
        return ans;
    }
};