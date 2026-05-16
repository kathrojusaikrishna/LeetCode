// problem : Find minimum in rotated array 2
// Level : Hard
// Time complexity : O(log n)
// space complexity : O(1)

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low =0;
        int high =nums.size()-1;


        while(low <= high){
            
            int mid = low + (high-low)/2;

            if(nums[mid]>nums[high]){
                low = mid+1;
            }
            else if(nums[mid]<nums[high]){
                high = mid;
            }
            else{
                high--;
            }
        }

        return nums[low];
    }
};