// Problem: Longest consequitive sequence
// Difficulty: Medium
//platform: takeUfarword
// Approach: Top-down dfs
// Time: O(n)
// Space: O(1)


class Solution {
public:
    void solve(TreeNode* root, TreeNode* parent, int& ans, int counter){
        if(!root)return;

        if(parent){
            if(parent->val+1 == root->val){
                counter++;
            }
            else{
                counter=1;
            }
        }

        ans = max(ans,counter);
        solve(root->left,root,ans,counter);
        solve(root->right, root,ans, counter);
        
    }
    int longestConsecutive(TreeNode* root) {
        // Your code goes here

        int ans =0;
        if(!root)return ans;

        solve(root,nullptr,ans,1);

        return ans;
    }
};