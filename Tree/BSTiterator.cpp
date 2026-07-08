// Problem: Binary search tree iterator
// Difficulty: Medium
// Platform: Leetcode
// Approach: stack
// Time: O(h)
// Space: O(h)

class BSTIterator {
public:

    stack<TreeNode* >st;
    BSTIterator(TreeNode* root) {
        moveLeft(root);
    }

    void moveLeft(TreeNode* root){
        while(root){
            st.push(root);
            root=root->left;
        }
    }
    
    int next() {
        TreeNode* top = st.top();
        st.pop();

        TreeNode* current = top->right;

        moveLeft(current);

        return top->val;
    }
    
    bool hasNext() {
        return st.size()!=0;
    }
};

