// Problem: Balanced String 1
// Difficulty: Medium
// Approach: Brute force
// Time: O(n^2 * k) - k is the size of substring
// Space: O(n) - for hashing


class Solution {
public:
    int longestBalanced(string s) {

        int n = s.size();
        int maxLen=0;
        vector<int>count(26);
        for(int i=0;i<n;i++){
            fill(count.begin(),count.end(),0);
            for(int j=i;j<n;j++){
                bool balanced = true;
                count[s[j]-'a']++;

                for(auto x:count){
                    if(x>0 && x!=count[s[j]-'a']){
                        balanced=false;
                        break;
                    }
                }
                if(balanced)maxLen = max(maxLen,j-i+1);
            }
        }

        return maxLen;
    }
};