// Problem: sum of deepest level
// Difficulty: Medium
//platform: Leetcode
// Approach: using queue
// Time: O(n)
// Space: O(h) -> for queue

class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        
        vector<vector<int>>levels;
        if(!root)return 0;

        queue<TreeNode*>q;
        q.push(root);


        while(!q.empty()){

            int size = q.size();
            vector<int>level;

            while(size--){

                TreeNode* temp = q.front();
                q.pop();

                level.push_back(temp->val);

                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
            }

            levels.push_back(level);
        }

        int n = levels.size();
        int sum=0;

        for(auto x : levels[n-1]){
            sum += x;
        }

        return sum;
    }
};