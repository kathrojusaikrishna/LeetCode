// Problem: Count the nodes equal to average nodes
// Difficulty: Medium
// platform: Leetcode
// Approach: Tree Dp
// Time: O(n)
// Space: O(1)


class Solution {
public:
    struct info{
        int count;
        int sum;
    };

    info dfs(TreeNode* root, int& ans){
        if(!root){
            return {0,0};
        }

        info left = dfs(root->left, ans);
        info right = dfs(root->right, ans);

        int curr = root->val + left.sum + right.sum;
        int total = 1+ left.count + right.count;

        if(curr/total == root->val)ans++;

        return {total, curr};
    }
    int averageOfSubtree(TreeNode* root) {
        int ans =0;
        if(!root)return 0;

        dfs(root,ans);

        return ans;
    }
};