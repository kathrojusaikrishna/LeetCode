// Problem: Longest string chain
// Difficulty: Medium
//platform: Leetcode
// Approach: using DP
// Time: O(n*n)
// Space: O(n) -> for dp

class Solution {
public:
    
    vector<int>dp;

    bool predecessor(string& a, string& b){

        if(a.size()+1!= b.size())return false;

        int i=0;
        int j=0;

        while(i<a.size() && j<b.size()){
            if(a[i]==b[j]){
                i++;
                j++;
            }else{
                j++;
            }
        }
        
        return i==a.size();
    }
    int solve(int i, vector<string>& words){
        int n = words.size();

        if(i==n)return 0;

        if(dp[i]!=-1){
            return dp[i];
        }

        int ans=1;
        for(int prev=0;prev<i;prev++){
            if(predecessor(words[prev],words[i])){
                ans = max(ans, 1+solve(prev,words));
            }
        }

        return dp[i] = ans;
    }
    int longestStrChain(vector<string>& words) {

        int n = words.size();

        sort(words.begin(), words.end(), [](const string &a, const string &b){
            return a.size() < b.size();
        });
        dp.assign(n,-1);

        int ans = 1;
        for(int i=0;i<n;i++){
            ans = max(ans, solve(i,words));
        }   

        return ans;
    }
};