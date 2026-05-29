// Problem: Minimum Element
// Difficulty: Easy
//platform: Leetcode
// Approach: simple iteration
// Time: O(n)
// Space: O(1) 

class Solution {
public:

    
    int solve(int num){

        int sum=0;
        while(num){
            int digit = num%10;
            sum+=digit;
            num /=10;
        }

        return sum;
    }
    int minElement(vector<int>& nums) {
        
        int n = nums.size();
        int ans = INT_MAX;

        for(int i=0;i<n;i++){
            ans = min(ans,solve(nums[i]));
        }
        
        return ans;
    }
};