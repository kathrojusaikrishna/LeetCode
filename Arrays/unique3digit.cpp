// Problem: Unique 3-digit even numbers
// Difficulty: Easy
// Platform: Leetcode
// Approach: Brute force
// Time: O(n^3)
// Space: O(n) 

class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        
        unordered_set<int>st;
        int n = digits.size();

        for(int i=0;i<n;i++){
            if(digits[i]==0)continue;
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(i==j || j==k || i==k)continue;
                    if(digits[k]%2!=0)continue;

                    int num = digits[i]*100+digits[j]*10+digits[k];

                    st.insert(num);

                }
            }
        }

        return st.size();
    }
};