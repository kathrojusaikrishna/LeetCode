// Problem: Remove outermost parenthesis
// Difficulty: Easy
//platform: Leetcode
// Approach: using stack
// Time: O(n)
// Space: O(n)

#include<bits/stdc++.h>

class Solution {
public:
    string removeOuterParentheses(string s) {
        
        stack<char>st;
        string ans = "";


        for(char c : s){
            if(c == '('){
                if(!st.empty()){
                    ans += c;
                }
                st.push(c);
            }else{

                st.pop();
                if(!st.empty()){
                    ans += c;
                }
            }
        }

        return ans;

    }
};