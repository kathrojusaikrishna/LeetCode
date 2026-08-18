// Problem: maximum length of subarray with atmost 2 occurences of each character
// Difficulty: Easy
// Platform: Leetcode
// Approach: sliding window
// Time: O(n)
// Space: O(1)


class Solution {
public:
    int maximumLengthSubstring(string s) {
        
        vector<int>a(26,0);

        int left=0;
        int len=0;

        for(int right=0;right<s.size();right++){
            a[s[right]-'a']++;

            while(a[s[right]-'a']>2){
                a[s[left]-'a']--;
                left++;
            }

            len = max(len,right-left+1);
        }

        return len;
    }
};