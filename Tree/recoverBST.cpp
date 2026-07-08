// Problem: Recover BST
// Difficulty: Medium
//platform: Leetcode
// Approach: Inorder 
// Time: O(n)
// Space: O(n)

class Solution {
public:
    vector<TreeNode* >nodes;
    
    void inOrder(TreeNode* root){
        if(!root)return;

        inOrder(root->left);
        nodes.push_back(root);
        inOrder(root->right);
    }
    void recoverTree(TreeNode* root) {
        inOrder(root);

        TreeNode* first = nullptr;
        TreeNode* second = nullptr;

        for(int i=1;i<nodes.size();i++){
            if(nodes[i-1]->val > nodes[i]->val){
                if(!first)first = nodes[i-1];
                second = nodes[i];
            }
        }

        swap(first->val,second->val);
    }
};