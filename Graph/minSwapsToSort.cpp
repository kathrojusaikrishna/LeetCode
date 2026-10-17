// Problem: Minimum swaps to sort by the digit sum
// Difficulty: Medium
//platform: Leetcode
// Approach: Sort + cycle decompose
// Time: O(nlogn)
// Space: O(n)

class Solution {
public:
    int sumOfDigits(int n){
        int sum=0;
        string temp = to_string(n);
        for(auto& ch : temp){
            sum += ch-'0';
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        
        int n = nums.size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){

            v.push_back({sumOfDigits(nums[i]),i});
        }

        sort(v.begin(), v.end(), [&](const pair<int,int>&a, const pair<int,int>&b){
            if(a.first != b.first){
                return a.first < b.first;
            }
            return nums[a.second] < nums[b.second];
        });

        vector<bool>vis(n,false);

        int swaps=0;

        for(int i=0;i<n;i++){

            if(vis[i] || v[i].second==i)continue;

            int j=i;
            int cycleSize=0;

            while(!vis[j]){
                vis[j]=true;
                j=v[j].second;
                cycleSize++;

            }
            swaps += cycleSize-1;
        }

        return swaps;
    }
};