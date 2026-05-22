// problem : Search in rotated sorted array
// Level : Medium
// Time complexity : O(log n)
// space complexity : O(1)

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int low=0;
        int high = nums.size()-1;

        while(low <= high){

            int mid = low + (high-low)/2;

            if(nums[mid]==target)return mid;

            if(nums[mid]>= nums[low]){
                if(target >= nums[low] && target <= nums[mid])high = mid-1;
                else low = mid+1;
            }else{

                if(target >= nums[mid] && target <= nums[high]) low = mid+1;
                else high = mid-1;
            }
        }

        return -1;
    }
};