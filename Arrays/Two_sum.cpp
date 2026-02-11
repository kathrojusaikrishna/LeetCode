// Problem: Two Sum
// Difficulty: Easy
// Approach: Two pointers, hashmap
// Time: O(n)
// Space: O(n) - for map


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n = nums.size();

        unordered_map<int,int>arr;
        for(int i=0;i<n;i++){
            int req = target - nums[i];

            auto it = arr.find(req);

            if(it != arr.end()){
                return {it->second,i};
            }
            else{
                arr[nums[i]]=i;
            }
        }

        return {};
    }    
};