// Problem: Count valid Prefixes
// Difficulty: Easy
// Approach: simple iteration and observation on number of ones and zeros
// Time: O(n)
// Space: O(1)

class Solution {
public:
    int countValidPrefixes(string s) {

        int ans=0;
        int zeros=0;
        int ones=0;

        for(auto& ch : s){
            int digit = ch-'0';

            if(digit==0)zeros++;
            else ones++;

            ans += (abs(ones-zeros)<2) ? 1 : 0;
        }

        return ans;
    }
};