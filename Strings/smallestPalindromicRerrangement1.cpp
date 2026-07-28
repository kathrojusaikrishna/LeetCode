// Problem: Smallest Palindromic Rearrangement I
// Difficulty: Medium
//platform: Leetcode
// Approach: find the first half, then add other by reversing first half
// Time: O(n)
// Space: O(1)

class Solution {
public:
    string smallestPalindrome(string s) {

        if(s.size()==1)return s;

        vector<int>a(26,0);
        string ans="";
        char mid=0;

        for(auto ch : s){
            a[ch-'a']++;
        }

        for(int i=0;i<26;i++){
            ans += string(a[i]/2 , char(i+'a'));
            
            if(a[i]%2){
                mid = char(i+'a');
            }
        }

        string right=ans;
        reverse(right.begin(),right.end());

        if(mid)return ans + mid + right;
        else return ans + right;


    }
};