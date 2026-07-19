// Problem: Smallest subsequence with distinct elements
// Difficulty: Medium
// Platform: Leetcode
// Approach: using stack and map
// Time: O(n)
// Space: O(n)


class Solution {
public:
    string smallestSubsequence(string s) {
        
        vector<int>last(26);
        int n = s.size();

        for(int i=0;i<n;i++){
            last[s[i]-'a']=i;
        }

        vector<bool> inStack(26,false);
        string st;

        for(int i=0;i<n;i++){
            char ch = s[i];

            if(inStack[ch-'a'])continue;

            while(!st.empty() && st.back()> ch && last[st.back()-'a'] > i){
                inStack[st.back()-'a']=false;
                st.pop_back();
            }

            st.push_back(ch);
            inStack[ch-'a'] = true;
        }

        return st;
    }
};