// Problem: Shortest and lexicographically smallest beautiful string
// Difficulty: Medium
// Platform: Leetcode
// Approach: simple iteration
// Time: O(n^2)
// Space: O(1) 


class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {

        string ans="";
        int n = s.size();
        for(int i=0;i<n;i++){
            int counter=0;
            string temp="";
            for(int j=i;j<n;j++){
                temp += s[j];
                if(s[j]=='1')counter++;
                if(counter>k)break;

                if(counter==k){
                    if(ans =="" || temp.size()<ans.size() || (temp.size()==ans.size() && temp < ans)){
                        ans = temp;
                    }
                }
            }
        }

        return ans;
    }
};