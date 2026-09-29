// Problem: Bitwise XOR of adjacent elements
// Difficulty: Easy
// Approach: Iteration
// Time: O(n )
// Space: O(1)

class Solution {
public:
    vector<int> orArray(vector<int>& A) {
       // User code goes here
       
       vector<int>ans;
       int n = A.size();
       for(int i=0;i<n-1;i++){
        ans.push_back(A[i] | A[i+1]);
       }
       return ans;
    }
}; 