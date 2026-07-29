// Problem: Maximum product of two digits
// Difficulty: Easy
// Platform: Leetcode
// Approach: simple iteration and find the largest and second largest digit
// Time: O(n)
// Space: O(1)

class Solution {
public:
    int maxProduct(int n) {
        
        string temp = to_string(n);

        int maxi = INT_MIN;
        int second = INT_MIN;
        for(auto ch :  temp){
            int num = ch-'0';

            if(num >= maxi){
                second = maxi;
                maxi = num;
            }

            if(num >= second && num < maxi){
                second = num;
            }
        }

        return maxi * second;
    }
};