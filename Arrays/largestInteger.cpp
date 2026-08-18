// Problem: Find the largesr almost missing integer
// Difficulty: Easy - hard
//platform: Leetcode
// Approach: check for k=1,n , betwwen 0 and n
// Time: O(n)
// Space: O(n) 

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        vector<int>a(51,0);
        int n = nums.size();

        if(k==1){
            for(int i=0;i<n;i++){
                a[nums[i]]++;
            }
            for(int i=50;i>=1;i--){
                if(a[i]==1)return i;
            }
        }else if(k==n){
            return *max_element(nums.begin(),nums.end());
        }else{
            bool first=true;
            bool last = true;
            for(int i=1;i<n;i++){
                if(nums[i]==nums[0])first=false;
            }

            for(int i=0; i<n-1;i++){
                if(nums[i]==nums[n-1])last=false;
            }

            int ans =-1;

            if(first){
                ans = max(ans,nums[0]);
            }
            if(last){
                ans = max(ans,nums[n-1]);
            }
            return ans;
        }

        return -1;

    }
};