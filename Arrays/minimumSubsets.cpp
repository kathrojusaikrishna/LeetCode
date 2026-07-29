// Problem: Split the array into minimum subsets
// Difficulty: Easy
// Approach: using set
// Time: O(n)
// Space: O(n) 

class Solution {
  public:
    int minSubsets(vector<int>& arr) {
        // code here
        
        unordered_set<int>st(arr.begin(),arr.end());
        int counter=0;
        for(auto x : arr){
            
            if(st.find(x-1)==st.end())counter++;
        }
     
     return counter;
     
    }
};
