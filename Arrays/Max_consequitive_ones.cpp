// Problem: Maximum Consequitive Ones
// Difficulty: Easy
// Approach: Simple Iteration
// Time: O(n)
// Space: O(1)


class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max=0;
        int counter=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                counter++;
            }
            else{
                if(counter > max) max = counter;
                counter =0 ;
            }
        }

        if(counter > max) max = counter;

        return max;
    }
};