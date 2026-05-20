// Problem: Find the prefix common array of two arrays
// Difficulty: Medium
// Approach: use set data structure
// Time: O(n)
// Space: O(n) - for returning the answer array

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        
        int n = A.size();
        vector<int>ans(n,0);
        unordered_set<int>st;

        for(int i=0;i<n;i++){
            st.insert(A[i]);
            st.insert(B[i]);

            ans[i] = 2*(i+1) - st.size();
        }

        return ans;
    }
};