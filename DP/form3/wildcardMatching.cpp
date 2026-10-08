// Problem: Wildcard matching
// Difficulty: Hard
//platform: leetcode
// Approach: DP
// Time: O(n*m)
// Space: O(n*m)

class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i, int j, string& s, string& p){

        if(i==s.size() && j==p.size())return 1;

        if(j==p.size()){
            return 0;
        }
        if(i==s.size()){
            for(int k=j;k<p.size();k++){
                if(p[k]!='*')return 0;
            }
            return 1;
        }

        //cache 
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int ans=0;

        if(p[j]=='?' || s[i]==p[j]){
            ans = solve(i+1,j+1,s,p);
        }
        else if(p[j]=='*'){

            ans |= solve(i+1,j,s,p);

            ans |= solve(i,j+1,s,p);
        }

        return dp[i][j] = ans;
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        dp.assign(n,vector<int>(m,-1));

        return solve(0,0,s,p);
    }
};