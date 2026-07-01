// Problem: Psuedo-palindromic paths in a binary tree
// Difficulty: Medium
//platform: Leetcode
// Approach: top-down dfs & backtracking
// Time: O(n)
// Space: O(n) - map

class Solution {
public:

    void solve(TreeNode* root, int &ans, unordered_map<int,int>& mp){
        if(!root)return;

        mp[root->val]++;
        if(!root->left && !root->right){
            int temp=0;
            for(auto &it:mp){
                if(it.second%2!=0)temp++;
            }

            if(temp<=1)ans++;
            mp[root->val]--;
            return;
        }

        solve(root->left,ans,mp);
        solve(root->right,ans,mp);
        mp[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        
        int ans=0;
        if(!root)return ans;
        unordered_map<int,int>mp;
        solve(root,ans,mp);

        return ans;
    }
};