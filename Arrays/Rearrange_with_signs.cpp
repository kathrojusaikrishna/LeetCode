// Problem: Rearrange array elements by sign
// Difficulty: Medium
// Approach: Two pointers
// Time: O(n)
// Space: O(n)




class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int positiveIndex=0;
        int negativeIndex=1;
        vector<int> ans(nums.size(),0);

        for(int i=0;i<nums.size();i++){
            if(nums[i]<0){
                ans[negativeIndex]=nums[i];
                negativeIndex +=2;

            }else{
                ans[positiveIndex] = nums[i];
                positiveIndex +=2;
            }
        }

        return ans;
    }
};