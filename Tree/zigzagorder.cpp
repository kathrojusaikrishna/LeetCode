// Problem: Zig-zag order traversal
// Difficulty: Medium
//platform: Leetcode
// Approach: using queue
// Time: O(n)
// Space: O(n) - queue

class Solution {
public:

    void swapVec(vector<int>& ans, int low, int high){
        int temp = ans[low];
        ans[low] =ans[high];
        ans[high]=temp;
    }
    void reverseVec(vector<int>& ans){
        int low=0;
        int high= ans.size()-1;

        while(low < high){
            swapVec(ans,low,high);
            low++;
            high--;
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>>ans;

        if(!root)return ans;

        queue<TreeNode* >q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int>Level;
            while(size--){
                TreeNode* curr = q.front();
                q.pop();

                Level.push_back(curr->val);

                if(curr->left)q.push(curr->left);
                if(curr->right)q.push(curr->right);
            }

            ans.push_back(Level);
        }

        for(int i=1;i<ans.size();i+=2){
            reverseVec(ans[i]);
        }

        return ans;
    }
};