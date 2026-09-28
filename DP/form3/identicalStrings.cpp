// Problem: Min Cost To Make Two Strings Identical
// Difficulty: Medium
//platform: Geeksforgeeks
// Approach: DP
// Time: O(n*m)
// Space: O(n*m)

class Solution {
  public:
    vector<vector<int>>dp;
    
    int solve(int i, int j, string& s1, string& s2, int costS1, int costS2){
        //pruning
        //base case
        if(i==s1.size()){
            return (s2.size()-j)*costS2;
        }
        if(j==s2.size()){
            return (s1.size()-i)*costS1;
        }
        
        //cache
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        //compute
        if(s1[i]==s2[j]){
            return dp[i][j] = solve(i+1,j+1,s1,s2,costS1,costS2);
        }
        
        int ans = 1e9;
        
        ans = min(ans, costS1 + solve(i+1,j,s1,s2,costS1,costS2));
        ans = min(ans, costS2 + solve(i,j+1,s1,s2,costS1,costS2));
        
        //save and return
        return dp[i][j] = ans;
    }
    int findMinCost(string &s1, string &s2, int costS1, int costS2) {
        // code here
        
        int n = s1.size();
        int m = s2.size();
        
        dp.assign(n,vector<int>(m,-1));
        
        return solve(0,0,s1,s2,costS1,costS2);
        
    }
};