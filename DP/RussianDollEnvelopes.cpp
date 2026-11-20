// Problem: Russian Doll Envelopes
// Difficulty: Hard
//platform: Leetcode
// Approach: using DP 
// Time: O(n*logn)
// Space: O(n) -> for dp

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& env) {

        int n = env.size();
        sort(env.begin(),env.end(), [](const vector<int>&a, const vector<int>&b){
            if(a[0]==b[0]){
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });

        vector<int>lis;

        for(int i=0;i<n;i++){
            int h = env[i][1];
            if(lis.empty() || h > lis.back()){
                lis.push_back(h);
            }else{
                auto it = lower_bound(lis.begin(),lis.end(),h);
                *it = h;
            }
        }

        return lis.size();
    }
};