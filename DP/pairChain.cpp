// Problem: Maximum length of pair chain
// Difficulty: Medium
//platform: Leetcode
// Approach: DP
// Time: O(n*n)
// Space: O(n) -> for dp

class Solution {
public:
    
    vector<int>dp;

    int solve(int index, vector<vector<int>>& pairs){
        int n = pairs.size();
        if(index==n)return 0;

        if(dp[index]!=-1){
            return dp[index];
        }

        int ans = 1;

        for(int prev=0; prev<index;prev++){
            
            if(pairs[prev][1] < pairs[index][0]){
                ans = max(ans, 1+solve(prev,pairs));
            }
        }

        return dp[index] = ans;
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        
        int n = pairs.size();
        sort(pairs.begin(),pairs.end(), [](const vector<int>&a , const vector<int>&b){
            return a[1] < b[1];
        });
        dp.assign(n,-1);

        int ans =1;
        for(int i=0;i<n;i++){
            ans = max(ans, solve(i,pairs));
        }
        return ans;
    }
};