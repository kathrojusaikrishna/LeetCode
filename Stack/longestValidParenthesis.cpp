// Problem: longest valid parenthesis
// Difficulty: Hard
// Platform: Leetcode
// Approach: using stack
// Time: O(n)
// Space: O(n)

class Solution {
public:
    int longestValidParentheses(string s) {

        stack<int>st;
        st.push(-1);
        int n = s.size();
        int ans=0;

        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(i);
            }else{
                st.pop();

                if(st.empty()){
                    st.push(i);
                }
                else{
                    ans = max(ans, i-st.top());
                }
            }
        }
        return ans;
    }
};