// Problem: Score of parenthesis
// Difficulty: Medium
//platform: Leetcode
// Approach: using stack
// Time: O(n)
// Space: O(n)

class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.size();
        vector<int>dp(n,0);

        int depth=0;
        stack<int>st;

        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(i);
                depth++;
            }
            else{
                depth--;
                if(st.top()+1==i){
                    dp[depth] += 1;
                }else{
                    dp[depth] += 2*dp[depth+1];
                    dp[depth+1]=0;
                }
                
                st.pop();
            }
        }

        return dp[0];
    }
};