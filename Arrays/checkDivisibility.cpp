// Problem: Check the divisibility by digit sum and product
// Difficulty: Easy
// Platform: Leetcode
// Approach: simple iteration
// Time: O(n)
// Space: O(1)

class Solution {
public:

    vector<int> solve(int n){
        int ans=0;
        int pro=1;

        while(n>0){
            int digit = n%10;
            ans += digit;
            pro *=digit;
            n/=10;
        }
        return {ans,pro};
    }
    bool checkDivisibility(int n) {
        auto ans = solve(n);
        return (n%(ans[0] + ans[1])==0);
    }
};