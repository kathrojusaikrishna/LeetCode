// Problem: Find bottom left tree value
// Difficulty: Medium
// Approach: Queue
// Time: O(n)
// Space: O(n) -> for queue


class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        

        queue<TreeNode* >q;
        TreeNode* curr = root;
        q.push(root);

        while(!q.empty()){

            curr = q.front();
            q.pop();

            if(curr->right)q.push(curr->right);
            if(curr->left)q.push(curr->left);
        }

        return curr->val;
        // vector<vector<int>>ans;

        // if(!root)return -1;


        // queue<TreeNode* >q;
        // q.push(root);

        // while(!q.empty()){
        //     int size = q.size();
        //     vector<int>level;

        //     while(size--){

        //         TreeNode* curr = q.front();
        //         q.pop();

        //         level.push_back(curr->val);

        //         if(curr->left)q.push(curr->left);
        //         if(curr->right)q.push(curr->right);
        //     }

        //     ans.push_back(level);
        // }

        // int n = ans.size();


        // return ans[n-1][0];
    }
};