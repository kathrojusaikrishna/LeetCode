// Problem: Minimum cost pizza selection
// Difficulty: Medium
//platform: Geeksforgeeks
// Approach: Dp - form 1
// Time: O(x)
// Space: O(x)

class Solution {
  public:
  
    vector<int>dp;
    int solve(int area, int s, int m, int l, int cs, int cm, int cl,int x){
        //pruning
        
        //base case
        if(area >= x)return 0;
        
        //cache 
        if(dp[area]!=-1){
            return dp[area];
        }
        //compute
        int ans = 1e9;
        
        ans = min(ans, cs + solve(area+s,s,m,l,cs,cm,cl,x));
        ans = min(ans, cm + solve(area+m,s,m,l,cs,cm,cl,x));
        ans = min(ans, cl + solve(area+l,s,m,l,cs,cm,cl,x));
        
        //save and return
        return dp[area] = ans;
    }
    int minimumCost(int x, int s, int m, int l, int cs, int cm, int cl) {
        // code here
        
        dp.assign(x+1,-1);
        int ans = solve(0,s,m,l,cs,cm,cl,x);
        
        return ans==1e9 ? 0 :  ans;
        
    }
};