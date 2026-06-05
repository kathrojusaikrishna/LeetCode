// Problem: Maximum width of the binary tree
// Difficulty: Medium
//platform: Leetcode
// Approach: level order
// Time: O(n)
// Space: O(n) - queue

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        long long ans=0;
        if(!root)return 0;

        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});


        while(!q.empty()){
            int size=q.size();
            long long start,end;
            long long mmin = q.front().second;

            for(int i=0;i<size;i++){

                long long curr_id = q.front().second - mmin;
                TreeNode* temp =q.front().first;
                q.pop();

                if(i==0)start = curr_id;
                if(i==size-1)end = curr_id;

                if(temp->left)q.push({temp->left,curr_id*2+1});
                if(temp->right)q.push({temp->right,curr_id*2+2});

            }

            ans = max(ans,end-start+1);
        }

        return (int)ans;
    }
};