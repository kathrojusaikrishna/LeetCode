// Problem: Move Zeros
// Difficulty: Easy
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
    void moveZeroes(vector<int>& nums) {

        int j = -1;

        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                j=i;
                break;
            }
        }

        if(j!= -1){
            for(int i = j+1;i<nums.size();i++){
            if(nums[i]!=0){
                swap(nums,i,j);
                j++;
            }
        }
        }
        
    }
};