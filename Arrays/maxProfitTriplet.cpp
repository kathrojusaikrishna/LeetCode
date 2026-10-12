// Problem: Maximum profit triplet
// Difficulty: Medium
// Platform: takeUfarword
// Approach: for every 0<mid <n-1, find left<mid and right>mid
// Time: O(n*n)
// Space: O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices, vector<int>& profits) {
        //your code goes here

        int n = prices.size();
        int ans = -1;

        for(int j=1;j<n-1;j++){
            int left = -1;
            int right = -1;
            int mid = profits[j];

            for(int i=0;i<j;i++){
                if(prices[i]<prices[j]){
                    left = max(left,profits[i]);
                }
            }
            for(int k=j+1;k<n;k++){
                if(prices[j]<prices[k]){
                    right = max(right,profits[k]);
                }
            }
            if(left !=-1 && right !=-1){
                ans = max(ans, left+mid+right);
            }

        }
        return ans;
    }
};