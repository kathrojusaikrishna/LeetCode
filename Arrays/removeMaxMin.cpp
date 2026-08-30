// Problem: Removing the maximum and minimum elements from an array
// Difficulty: Medium
// Platform: Leetcode
// Approach: find the positions and check for 3 possibilities
// Time: O(n)
// Space: O(1)

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        
        int n = nums.size();
        int maxi=INT_MIN;
        int maxPos=-1;

        int mini = INT_MAX;
        int minPos = -1;

        for(int i=0;i<n;i++){
            if(nums[i]<mini){
                mini = nums[i];
                minPos=i;
            }
            if(nums[i]>maxi){
                maxi = nums[i];
                maxPos = i;
            }
        }

        int option1 = max(minPos,maxPos)+1;
        int option2 = n -min(minPos,maxPos);
        int option3 = min(minPos,maxPos)+1 + n- max(minPos,maxPos);

        return min({option1,option2,option3});
    }
};