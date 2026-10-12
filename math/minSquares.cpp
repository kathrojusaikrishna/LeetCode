// Problem: Minimum Squares
// Difficulty: Medium
// Platform: Geeksforgeeks
// Approach: ans += n/m && n-= (n/m)*m
// Time: O(log(min(m,m)))
// Space: O(1) 

class Solution {
  public:
    int minSquares(int n, int m) {
        // code here
        int ans=0;
        while(n>0 && m>0){
            if(m>n)swap(n,m);
            
            ans += n/m;
            n -= (n/m)*m;
        }
        return ans;
    }
};