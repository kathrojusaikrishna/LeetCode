// Problem: First Missing Positive integer
// Difficulty: Hard
// Approach: swapping and iteration
// Time: O(n)
// Space: O(1)

class Solution {

private:
    void swap(vector<int> &arr, int low ,int high){
        int temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;
    }
public:
    int firstMissingPositive(vector<int>& nums) {

        for(int i=0;i<nums.size();i++){
            while(nums[i]>=1 && nums[i]<=nums.size() && nums[i]!=nums[nums[i]-1]){
                swap(nums,i,nums[i]-1);
            }
        }

        for(int i=0;i<nums.size();i++){
            if(nums[i]!= i+1)return i+1;
        }

        return nums.size()+1;
        
    }
};