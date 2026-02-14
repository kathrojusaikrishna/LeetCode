// Problem: Greatest sum divisible by 2
// Difficulty: Medium
// Approach: sorting
// Time: O(nlogn)
// Space: O(n) - worst case


class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum=0;

        vector<int>r1;
        vector<int>r2;

        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(nums[i]%3==1)r1.push_back(nums[i]);
            if(nums[i]%3==2)r2.push_back(nums[i]);
        }

        sort(r1.begin(),r1.end());
        sort(r2.begin(),r2.end());

        if(sum %3==0)return sum;

        if(sum%3==1){
            int remove1 = r1.size()>=1 ? r1[0] : INT_MAX;
            int remove2 = r2.size()>=2 ? r2[0] + r2[1] : INT_MAX;
            return sum - min(remove1, remove2);
        }

        int remove1 = r2.size()>=1 ? r2[0] : INT_MAX;
        int remove2 = r1.size()>=2 ? r1[0] + r1[1] : INT_MAX;
        return sum - min(remove1, remove2);
        
    }
};