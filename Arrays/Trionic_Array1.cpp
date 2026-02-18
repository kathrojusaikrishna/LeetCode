// Problem: Trionic Array 1
// Difficulty: Easy
// Approach: Simple iteration
// Time: O(n)
// Space: O(1)


class Solution {
public:
    bool isTrionic(vector<int>& nums) {

        int n= nums.size();
        if(n<3)return false;

        int i=1;
        while(i<n && nums[i]>nums[i-1])i++;
        if(i==1 || i==n)return false;

        int mid =i;
        while(i<n && nums[i]<nums[i-1])i++;
        if(i==mid || i==n)return false;

        while(i<n && nums[i]>nums[i-1])i++;

        return i==n;


    }
};