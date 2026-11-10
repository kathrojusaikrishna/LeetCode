// Problem: First element time
// Difficulty: Easy
// Approach: hashing
// Time: O(n)
// Space: O(n)

class Solution {
  public:
    int firstElementKTime(vector<int>& arr, int k) {
        // code here
        
        unordered_map<int,int>f;
        int first=-1;
        for(auto x : arr){
            f[x]++;
            if(f[x]==k)return x;
        }
        
        return -1;
        
        
    }
};