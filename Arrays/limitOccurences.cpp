// Problem: Limit Occurences
// Difficulty: Easy
// Approach: Two pointers
// Time: O(n)
// Space: O(1)

class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {

        vector<int> ans;

        int n = nums.size();

        int i=0;
        int j=0;

        while(i<n){
            int counter=0;

            while(j<n && nums[i]==nums[j]){
                counter++;
                if(counter <=k)ans.push_back(nums[i]);
                j++;
            }
            i=j;
        }

        return ans;
    }
};