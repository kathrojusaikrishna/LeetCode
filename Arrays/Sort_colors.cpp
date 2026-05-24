// Problem: Sort Colors
// Difficulty: Medium
// Approach: Two pointers
// Time: O(n)
// Space: O(1)


class Solution {

private:
    void swap(vector<int> &arr, int left, int right){
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
    }    
public:
    void sortColors(vector<int>& nums) {
        int low=0;
        int mid=0;
        int high = nums.size()-1;

        while(mid <= high){
            if(nums[mid]==0){
                swap(nums,mid,low);
                low++;
                mid++;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else{
                swap(nums,mid,high);
                high--;
            }
        }
    }
};