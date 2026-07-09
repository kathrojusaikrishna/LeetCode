// Problem: Path existence queries in a graph I
// Difficulty: Medium
//platform: Leetcode
// Approach: Connected components
// Time: O(n)
// Space: O(n)

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int>connected(n);
        vector<bool>ans;
        connected[0]=0;
        int id=0;

        for(int i=1;i<nums.size();i++){
            if(abs(nums[i]-nums[i-1])>maxDiff)id++;
            connected[i]=id;
        }

        for(auto& query : queries){
            int u = query[0];
            int v = query[1];

            if(connected[u]!=connected[v])ans.push_back(false);
            else ans.push_back(true);
        }

        return ans;
    }
};