// Problem: Maximum sum of sqaures
// Difficulty: Medium
//platform: Leetcode
// Approach: Greedy
// Time: O(n)
// Space: O(1)

class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        
        string temp="";

        if(num*9 < sum)return temp;
        for(int i=0;i<num;i++){
            int digit = min(sum,9);

            temp += (char)('0' + digit);
            sum -= digit;
        }

        return temp;
    }
};