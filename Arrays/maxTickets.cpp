// Problem: Max Amount by Selling K Tickets
// Difficulty: Medium
// Approach: use max heap to find the largest values (Greedy)
// Time: O(nlogn)
// Space: O(n) - max heap worst case

class Solution {
  public:
    int maxAmount(vector<int>& arr, int k) {
        // code here
        
        priority_queue<int,vector<int>>pq;
        const int MOD = 1e9+7;
        int ans=0;
        
        for(auto x : arr){
            pq.push(x);
        }
        
        while(k--){
            if(!pq.empty()){
                long long temp = pq.top();
                pq.pop();
                
                ans = (ans + temp) % MOD;
                
                temp--;
                if(temp>0)pq.push(temp);
                
                
            }
        }
        
        return ans % MOD;
    }
};