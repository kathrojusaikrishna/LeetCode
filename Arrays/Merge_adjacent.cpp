// Problem: Merge adjacent equal elements
// Difficulty: Medium
// Approach: simple iteration
// Time: O(n)
// Space: O(n) - for returning the answers worst case


class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {

        vector<long long> st;

        for(long long num : nums){

            while(!st.empty() && st.back()==num){
                num += st.back();
                st.pop_back();
            }

            st.push_back(num);
        }

        return st;
    }
};