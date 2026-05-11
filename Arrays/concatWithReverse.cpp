// Problem: Concat with reverse
// Difficulty: Easy
// Approach: simple iteration
// Time: O(n)
// Space: O(1)

class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        int n= nums.size();
        vector<int>result(2*n,0);

        for(int i=0;i<n;i++){
            result[i]=nums[i];
            result[2*n-i-1]=nums[i];
        }
\

        return result;
    }
};