// Problem: Interleaving strings
// Difficulty: Medium
//platform: Leetcode
// Approach: DP
// Time: O(n*m)
// Space: O(n*m)

class Solution {
public:
    vector<vector<int>>dp;
    string s1,s2,s3;
    int z;

    int solve(int i, int j){

        int k = i+j;
        if(k==z)return 1;

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int ans=0;

        if(i<s1.size() && s1[i]==s3[k]){
            ans |= solve(i+1,j);
        }

        if(j<s2.size() && s2[j]==s3[k]){
            ans |= solve(i,j+1);
        }

        return dp[i][j] = ans;
    }
    bool isInterleave(string s1, string s2, string s3) {

        int n = s1.size();
        int m = s2.size();

        this->s1=s1;
        this->s2 =s2;
        this->s3 = s3;
        this->z = s3.size();

        if(n+m != s3.size())return 0;

        dp.assign(n+1,vector<int>(m+1,-1));

        return solve(0,0);
    }
};