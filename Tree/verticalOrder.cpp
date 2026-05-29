// Problem: Vertical order traversal
// Difficulty: Hard
//platform: Leetcode
// Approach: queue, map
// Time: O(nlogn)
// Space: O(n)

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        vector<vector<int>>ans;
        if(!root)return ans;

        map<int,map<int,multiset<int>>>mp;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});

        while(!q.empty()){
            int size = q.size();

            for(int i=0;i<size;i++){

                auto p = q.front();
                q.pop();

                TreeNode* temp = p.first;
                int vertical = p.second.first;
                int level = p.second.second;

                mp[vertical][level].insert(temp->val);

                if(temp->left)q.push({temp->left,{vertical-1,level+1}});
                if(temp->right)q.push({temp->right,{vertical+1,level+1}});
            }
        }

        for(auto vertical : mp){
            vector<int>col;
            for(auto level : vertical.second){
                for(auto val : level.second){
                    col.push_back(val);
                }
            }
            ans.push_back(col);
        }

        return ans;
    }
};