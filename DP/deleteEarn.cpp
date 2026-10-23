// Problem: Delete and Earn
// Difficulty: Medium
//platform: Leetcode
// Approach: DP
// Time: O(max_element)
// Space: O(1)

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {

        int maxi = *max_element(nums.begin(),nums.end());

        vector<int>points(maxi+1,0);
        for(auto& x : nums){
            points[x] +=x;
        }

        int prev1=0;
        int prev2=0;

        for(int i=0;i<=maxi;i++){

            int curr = max(prev1,prev2+points[i]);

            prev2=prev1;
            prev1=curr;
        }

        return prev1;
    }
};