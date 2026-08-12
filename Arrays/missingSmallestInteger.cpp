// Problem: Smallest missing integer greater than sequential prefix sum
// Difficulty: Easy
// platform: Leetcode
// Approach: simple iteration and set
// Time: O(n)
// Space: O(n)

class Solution {
public:
    int missingInteger(vector<int>& nums) {

        int n = nums.size();

        int sum=nums[0];

        unordered_set<int>st(nums.begin(),nums.end());

        for(int i=1;i<n;i++){
            if(nums[i-1]+1 == nums[i]){
                sum += nums[i];
            }else{
                break;
            }
        }
        
        while(st.count(sum)){
            sum+=1;
        }

        return sum;
    }
};