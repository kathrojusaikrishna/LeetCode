// Problem: Construct Uniform parity II
// Difficulty: easy
// Platform: Leetcode
// Approach: Find the min odd, and check if we can produce a neg number
// Time: O(n)
// Space: O(1)

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mini = INT_MAX;
        int n=nums1.size();
        int pos=-1;
        for(int i=0;i<n;i++){
            if(nums1[i]%2==1 && nums1[i]<mini){
                pos = i;
                mini = nums1[i];
            }
        }
        if(pos==-1)return true;

        for(int i=0;i<n;i++){
            if(nums1[i]-mini <0)return false;
        }
        return true;
    }
};