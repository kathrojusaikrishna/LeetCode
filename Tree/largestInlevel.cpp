// Problem: Find largest in each level
// Difficulty: Medium
//platform: Leetcode
// Approach: using queue
// Time: O(n)
// Space: O(h) -> for queue

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        
        vector<int>ans;
        if(!root)return ans;

        queue<TreeNode*>q;
        q.push(root);


        while(!q.empty()){

            int size = q.size();
            int maxi=INT_MIN;

            for(int i=0;i<size;i++){

                TreeNode* temp= q.front();
                q.pop();

                maxi = max(maxi,temp->val);

                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
            }

            ans.push_back(maxi);
        }

        return ans;
    }
};