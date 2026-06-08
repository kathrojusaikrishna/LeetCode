// Problem: Partition the array acoording to pivot
// Difficulty: Medium
//platform: Leetcode
// Approach: simple iteration
// Time: O(n)
// Space: O(n) 

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        
        vector<int>smaller,larger,ans;

        int n = nums.size();
        int counter=0;

        for(int i=0;i<n;i++){
            if(nums[i] < pivot)smaller.push_back(nums[i]);
            else if(nums[i]==pivot)counter++;
            else larger.push_back(nums[i]);
        }

        for(int i=0;i<smaller.size();i++){
            ans.push_back(smaller[i]);
        }

        while(counter){
            ans.push_back(pivot);
            counter--;
        }

        for(int i=0;i<larger.size();i++){
            ans.push_back(larger[i]);
        }


        return ans;
    }
};