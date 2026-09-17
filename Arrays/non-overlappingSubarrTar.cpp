// Problem: Find Two Non-overlapping Sub-arrays Each With Target Sum
// Difficulty: Medium
// Approach: prefix , suffix -> each store the min len whose sum=target till [0...i]
// Time: O(n)
// Space: O(n)

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        if(n==1)return -1;
        const int INF = 1e9;
        vector<int>prefix(n,INF);
        vector<int>suffix(n,INF);

        int l=0;
        int sum=0;

        for(int r=0;r<n;r++){
            sum += arr[r];

            while(sum > target){
                sum -= arr[l++];
            }

            if(sum==target){
                prefix[r] = r-l+1;
            }
        }

        for(int i=1;i<n;i++){
            prefix[i] = min(prefix[i], prefix[i-1]);
        }

        int r=n-1;
        sum=0;

        for(int l = n-1;l>=0;l--){
            sum += arr[l];

            while(sum > target){
                sum -= arr[r--];
            }
            if(sum==target){
                suffix[l] = r-l+1;
            }
        }

        for(int i=n-2;i>=0;i--){
            suffix[i] = min(suffix[i], suffix[i+1]);
        }

        int ans = INF;

        for(int i=0;i<n-1;i++){
            if(prefix[i]!=INF && suffix[i]!=INF){
                ans = min(ans, prefix[i]+suffix[i+1]);
            }
        }

        return ans==INF? -1 : ans;
    }
};