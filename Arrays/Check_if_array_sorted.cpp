// Problem: Check if array is sorted and rotated
// Difficulty: Easy
// Approach: simple iteration
// Time: O(n)
// Space: O(1)


#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(vector<int>& nums) {

        int n = nums.size();
        int counter=0;

        for(int i=0;i<n;i++){
            if(nums[i]>nums[(i+1)%n])counter++;
        }

        if(counter <=1)return true;
        return false;
    }
};