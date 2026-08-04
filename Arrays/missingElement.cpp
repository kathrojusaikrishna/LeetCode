// Problem: Find the missing elements
// Difficulty: Easy
// Approach: simple iteration
// Time: O(n)
// Space: O(n)

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        
        vector<int>ans;

        int mini = *min_element(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(),nums.end());

        vector<int>a(maxi+1,0);
        for(int i=0;i<nums.size();i++){
            a[nums[i]]=1;
        }
        for(int i=mini;i<=maxi;i++){
            if(a[i]==0)ans.push_back(i);
        }

        return ans;
    }
};