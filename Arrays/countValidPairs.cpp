// Problem: Count valid pairs divisivle by K
// Difficulty: Medium
// Platform : Geeksforgeeks
// Approach: hashing
// Time: O(n)
// Space: O(k)

class Solution {
  public:
    int countKdivPairs(vector<int>& arr, int k) {
        // code here
        
        unordered_map<int,int>mp;
        int counter=0;
        
        for(int i=0;i<arr.size();i++){
            
            int rem = arr[i]%k;
            
            int need = (k- rem )%k;
            
            counter +=mp[need];
            
            mp[rem]++;
        }
        
        return counter;
    }
};