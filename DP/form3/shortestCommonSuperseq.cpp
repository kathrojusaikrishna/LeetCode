// Problem: Shortest common super sequence
// Difficulty: Hard
//platform: Leetcode
// Approach: DP
// Time: O(n*m)
// Space: O(n*m)

class Solution {
public:
    vector<vector<int>> dp;
    string str1, str2;
    int solve(int i, int j) {
        int n = str1.size();
        int m = str2.size();
        if (i == n || j == m)
            return 0;

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int ans = 0;
        if (str1[i] == str2[j]) {
            ans = max(ans, 1 + solve(i + 1, j + 1));
        }

        ans = max(ans, solve(i + 1, j));
        ans = max(ans, solve(i, j + 1));

        return dp[i][j] = ans;
    }
    string shortestCommonSupersequence(string str1, string str2) {

        int n = str1.size();
        int m = str2.size();

        this->str1 = str1;
        this->str2 = str2;

        dp.assign(n + 1, vector<int>(m + 1, -1));

        solve(0,0);
        string LCS = "";
        int i=0;
        int j=0;

        while(i<n && j<m){

            if(str1[i]==str2[j]){
                LCS += str1[i];
                i++;
                j++;
            }
            else if(solve(i+1,j) > solve(i,j+1) ){
                i++;
            }else{
                j++;
            }
        }

        string ans="";
        i=0;
        j=0;
        for(auto& ch : LCS){

            while(str1[i]!=ch){
                ans += str1[i++];
            }

            while(str2[j]!=ch){
                ans += str2[j++];
            }

            ans += ch;
            i++;
            j++;
        }

        while(i<n){
            ans += str1[i++];
        }
        while(j<m){
            ans += str2[j++];
        }

        return ans;
    }
};