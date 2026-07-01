// Problem: Path sum II
// Difficulty: Medium
//platform: Leetcode
// Approach: top-down dfs
// Time: O(n)
// Space: O(n) - for ans


class Solution {
public:

    void solve(TreeNode* root, vector<int> path,int currentSum, vector<vector<int>>& ans,int target){
        if(!root)return;

        currentSum +=root->val;
        path.push_back(root->val);
        if(!root->left && !root->right && currentSum==target){
            ans.push_back(path);
            path.pop_back();
            return;
        }

        solve(root->left,path,currentSum,ans,target);
        solve(root->right,path,currentSum,ans,target);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<vector<int>>ans;
        vector<int>path;
        if(!root)return ans;

        solve(root,path,0,ans,targetSum);

        return ans;
    }
};