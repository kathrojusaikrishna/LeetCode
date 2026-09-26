// Problem: Palindromic partitioning
// Difficulty: Hard
//platform: Geeksforgeeks
// Approach: DP
// Time: O(n*n)
// Space: O(n)

class Solution {
  public:
    vector<int>dp;
    
    bool isPalindrome(int l, int r, string& s){
        if(l>=r)return true;
        return s[l]==s[r] && isPalindrome(l+1,r-1,s);
    }
    
    int solve(int i, string& s){
        
        if(i==s.size()){
            return -1;
        }
        
        if(dp[i]!=-1){
            return dp[i];
        }
        int ans = 1e9;
        
        for(int j=i;j<s.size();j++){
            if(isPalindrome(i,j,s)){
                ans = min(ans, 1+solve(j+1,s));
            }
        }
        return dp[i] = ans;
    }
    int palPartition(string &s) {
        // code here
        int n =s.size();
        dp.assign(n,-1);
        
        return solve(0,s);
    }
};