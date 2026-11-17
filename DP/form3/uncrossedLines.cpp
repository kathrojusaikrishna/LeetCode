// Problem: Uncrossed lines
// Difficulty: Medium
//platform: Leetcode
// Approach: DP
// Time: O(n*m)
// Space: O(n*m)

class Solution {
public:
    vector<vector<int>>dp;
    vector<int>nums1,nums2;


    int solve(int i, int j){
        int n = nums1.size();
        int m = nums2.size();
        if(i==n || j==m)return 0;

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int ans = 0;
        
        if(nums1[i]==nums2[j]){
            ans = max(ans, 1 + solve(i+1,j+1));
        }
        ans = max(ans, solve(i+1,j));
        ans = max(ans, solve(i,j+1));

        return dp[i][j] = ans;
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {

        this->nums1 = nums1;
        this->nums2 = nums2;

        int n = nums1.size();
        int m = nums2.size();

        dp.assign(n,vector<int>(m,-1));
        return solve(0,0);
    }
};