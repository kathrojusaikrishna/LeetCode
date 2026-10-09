// Problem: Clone n-ary tree
// Difficulty: Medium
//platform: takeUfarword
// Approach: recursion + hashmap
// Time: O(n)
// Space: O(n)

class Solution {
public:
    unordered_map<TreeNode* , TreeNode*>mp;
    TreeNode* cloneTree(TreeNode* root) {
        if(!root)return nullptr;

        if(mp.count(root)){
            return mp[root];
        }

        TreeNode* clone = new TreeNode(root->val);

        for(TreeNode* ch : root->children){
            clone->children.push_back(cloneTree(ch));
        }

        return clone;
    }
};

/**
 * Definition for an n-ary tree node.
 * class TreeNode {
 * public:
 *     int val;
 *     vector<TreeNode*> children;
 * 
 *     TreeNode() {}
 * 
 *     TreeNode(int _val) {
 *         val = _val;
 *     }
 * 
 *     TreeNode(int _val, vector<TreeNode*> _children) {
 *         val = _val;
 *         children = _children;
 *     }
 * };
 **/