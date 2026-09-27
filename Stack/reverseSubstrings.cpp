// Problem: Reverse substrings between each pair of parentheses
// Difficulty: Medium
//platform: Leetcode
// Approach: using stack
// Time: O(n*n)
// Space: O(n)


class Solution {
public:
    void reverse(int l, int r, string& s){
        while(l<=r){
            char temp = s[l];
            s[l]=s[r];
            s[r]=temp;

            l++;
            r--;
        }
    }
    string reverseParentheses(string s) {
        
        stack<int>st;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(i);
            }
            if(s[i]==')'){
                reverse(st.top()+1,i-1,s);
                st.pop();
            }
        }

        string ans="";
        for(auto& ch : s){
            if(ch != '(' && ch!=')'){
                ans += ch;
            }
        }
        return ans;
    }
};