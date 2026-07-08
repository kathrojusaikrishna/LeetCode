// Problem: Delete a node in binary search tree
// Difficulty: Medium
// Platform: Leetcode
// Approach: recursion
// Time: O(h)
// Space: O(h)

class Solution {
public:

    TreeNode* findMin(TreeNode* root){
        while(root->left){
            root=root->left;
        }

        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(!root)return nullptr;

        if(key > root->val){
            root->right = deleteNode(root->right,key);
            return root;
        }
        else if(key < root->val){
            root->left = deleteNode(root->left,key);
            return root;
        }
        else{

            if(!root->left && !root->right){
                return nullptr;
            }
            else if((!root->left && root->right) || (root->left && !root->right)){
                return root->left ? root->left : root->right;
            }
            else {
                TreeNode* min = findMin(root->right);
                root->val = min->val;
                root->right = deleteNode(root->right,min->val);

            }
        }

        return root;
    }
};