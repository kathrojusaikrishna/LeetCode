// Problem: Game of divisible sums
// Difficulty: Medium
//platform: Leetcode
// Approach: Game - DP
// Time: O(n)
// Space: O(n)

class Solution {
public:
    long long maxDifference(vector<int>& nums) {

        int n = nums.size();
        vector<long long>dp(n+2,0);

        for(int i=n-1;i>=0;i--){

            int s1 = nums[i];

            long long choice1;

            if(s1%3==0){
                choice1 = s1 - dp[i+1];
            }else{
                choice1 = s1 + dp[i+1];
            }

            long long choice2=LLONG_MIN;
            if(i+1<n){
                long long s2 = nums[i]+nums[i+1];

                if(s2%3==0){
                    choice2 = s2 - dp[i+2];
                }else{
                    choice2 = s2 + dp[i+2];
                }
            }

            dp[i] = max(choice1,choice2);
        }

        return dp[0];
    }
};