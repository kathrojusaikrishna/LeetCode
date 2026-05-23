// Problem: Check if the array is rotated and sorted
// Difficulty: Easy
// Approach: simple iteration, and checking no.of break points
// Time: O(n)
// Space: O(1)

class Solution {
public:
    bool check(vector<int>& nums) {

        int n = nums.size();
        int counter=0;

        for(int i=0;i<n;i++){
            if(nums[i]>nums[(i+1)%n])counter++;
        }

        return counter<=1;
    }
};