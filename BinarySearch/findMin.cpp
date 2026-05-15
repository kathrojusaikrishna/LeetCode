// problem : Find minimum in rotated array
// Level : Medium
// Time complexity : O(log n)
// space complexity : O(1)

class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int low=0;
        int high = nums.size()-1;

        int ans=INT_MAX;

        while(low <= high){

            int mid = low + (high-low)/2;

            if(nums[mid] >= nums[low]){
                ans = min(ans,nums[low]);
                low = mid+1;
            }
            else{
                ans = min(ans,nums[mid]);
                high = mid-1;
            }
        }

        return ans;
    }
};