// Problem: Maximum product of two elements of an array
// Difficulty: Easy
// Platform: Leetcode
// Approach: simple iteration
// Time: O(n)
// Space: O(1)


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int largest=INT_MIN;
        int second = INT_MIN;
        int n = nums.size();

        for(int i=0;i<n;i++){
            if(nums[i] >= largest){
                second = largest;
                largest = nums[i];
            }
            else if(nums[i] >= second){
                second = nums[i];
            }
        }

        return (largest-1)*(second-1);
    }
};