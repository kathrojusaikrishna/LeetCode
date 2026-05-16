// Problem: Find valid elements in the array
// Difficulty: Easy
// Approach: simple iteration
// Time: O(n)
// Space: O(n)

class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        ans.push_back(nums[0]);

        vector<int>maxi(n);
        maxi[n-1]=nums[n-1];


        for(int i=n-2;i>=0;i--){
            maxi[i]=max(nums[i],maxi[i+1]);
        }
        int max_num = nums[0];

        for(int i=1;i<n-1;i++){
            if(nums[i]>max_num || nums[i]>maxi[i+1])ans.push_back(nums[i]);
            max_num = max(nums[i],max_num);
        }

       if(n-1 != 0) ans.push_back(nums[n-1]);

        return ans;
    }
};