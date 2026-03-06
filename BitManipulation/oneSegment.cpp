// Problem: Check if binary string has at most one segment of ones
// Difficulty: Easy
// Approach: Iteration from back
// Time: O(n)
// Space: O(1)

class Solution {
public:
    bool checkOnesSegment(string s) {

        int i =s.size()-1;

        while(s[i]=='0' && i>=0)i--;

        while(i>=0){
            if(s[i]=='0')return false;
            i--;
        }

        return true;
    }
};