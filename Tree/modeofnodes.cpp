// Problem: Mode of nodes
// Difficulty: Easy
//platform: Leetcode
// Approach: recursion, hashing-map
// Time: O(n)
// Space: O(n)

class Solution {
public:

    void solve(TreeNode* root, map<int,int>& mp){
        if(!root)return;

        mp[root->val]++;
        solve(root->left,mp);
        solve(root->right,mp);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int>ans;

        if(!root)return ans;
        map<int,int>mp;
        solve(root,mp);

        int maxi = INT_MIN;
        for(auto p:mp){
            maxi = max(maxi,p.second);
        }

        for(auto x : mp){
            if(x.second == maxi)ans.push_back(x.first);
        }

        return ans;
    }
};