// Problem: Remove Duplicates
// Difficulty: Easy
// Approach: Two pointers
// Time: O(n)
// Space: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void swap(vector<int> &arr, int left, int right){
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
    }    
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        int j=1;
        int n = nums.size();

        while(j<n){
            if(nums[i]==nums[j]){
                j++;
            }else{
                ++i;
                swap(nums,i,j);
                j++;
            }
        }

        return i+1;
    }
};