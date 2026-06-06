// Problem: Non-Attacking Black and White Knights
// Difficulty: Medium
//platform: Geeksforgeeks
// Approach: formula
// Time: O(1)
// Space: O(1) 

class Solution {
  public:
    int numOfWays(int n, int m) {
        // code here
        
        long long cells = 1LL * n * m;
        long long totalWays = cells * (cells -1);
        long long attacking = 4LL * (
            1LL * max(0,n-1)*max(0,m-2)+
            1ll * max(0,n-2)*max(0,m-1)
            );
        return (int)(totalWays - attacking);
        
    }
};