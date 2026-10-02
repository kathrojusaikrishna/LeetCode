// Problem: Generate parenthesis
// Difficulty: Medium
//platform: Leetcode
// Approach: using recursion
// Time: O(4*n/sqrt(n))
// Space: O(n) -> for ans

class Solution {
public:
    void solve(string curr,int n, vector<string>& ans, int opening, int closing){
        //pruning

        //base case
        if(curr.size()/2==n){
            ans.push_back(curr);
            return;
        }
        //compute

        if(opening < n){
            solve(curr+"(",n,ans,opening+1,closing);
        }
        if(closing < opening){
            solve(curr+")",n,ans, opening,closing+1);
        }
    }
    vector<string> generateParenthesis(int n) {
        
        vector<string>ans;

        solve("",n,ans,0,0);

        return ans;
    }
};