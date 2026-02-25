// Problem: Sort the array based on set bits
// Difficulty: Easy
// Approach: priority queue
// Time: O(nlogn )
// Space: O(n)


class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        
        vector<int>ans;

        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<>>pq;

        for(auto x : arr){
            int bits = __builtin_popcount(x);
            pq.push({bits,x});
        }

        while(!pq.empty()){
            auto [bits, value] = pq.top();
            pq.pop();
            ans.push_back(value);
        }

        return ans;

    }
};