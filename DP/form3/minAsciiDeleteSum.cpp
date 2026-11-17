// Problem: Minimum ASCII Delete Sum for Two Strings
// Difficulty: Medium
//platform: Leetcode
// Approach: DP
// Time: O(n*m)
// Space: O(n*m)

class Solution {
public:
    vector<vector<int>>dp;
    string s1,s2;
    int solve(int i, int j){

        int n = s1.size();
        int m = s2.size();
        if(i==n || j==m)return 0;

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int ans =0;

        if(s1[i]==s2[j]){
            ans = max(ans, (int)s1[i]+solve(i+1,j+1));
        }
        ans = max(ans, solve(i+1,j));
        ans = max(ans, solve(i,j+1));

        return dp[i][j] = ans;
    }
    int minimumDeleteSum(string s1, string s2) {
        
        this->s1 =s1;
        this->s2 = s2;

        int n =s1.size();
        int m = s2.size();

        dp.assign(n,vector<int>(m,-1));
        
        int sum1=0;
        for(auto& ch : s1){
            sum1 += (int)ch;
        }

        int sum2=0;
        for(auto& ch : s2){
            sum2 += (int)ch;
        }
        
        return sum1 + sum2 - 2*solve(0,0);
    }
};