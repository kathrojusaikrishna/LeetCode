// Problem: Check if a string contains all binary codes of size k
// Difficulty: Medium
// Approach: Sliding window
// Time: O(n)
// Space: O(2^k)

class Solution {
public:
    bool hasAllCodes(string s, int k) {

        int total = 1<<k;
        int mask = total -1;
        vector<bool>ans(total,false);

        int n = s.size();
        int num=0;

        if(n-k+1 < total)return false;

        for(int i=0;i<n;i++){
            num = ((num<<1)& mask) | (s[i]-'0'); 

            if(i>= k-1)ans[num]=true;
        }

        for(auto x : ans){
            if(!x)return false;
        }

        return true;
    }
};