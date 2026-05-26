// Problem: Count special characters 1
// Difficulty: Easy
// Approach: hashing
// Time: O(n)
// Space: O(1)

class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<bool>lower(26,false);
        vector<bool>upper(26,false);
        int ans=0;

        for(auto ch : word){
            if(islower(ch))lower[ch-'a']=true;
            if(isupper(ch))upper[ch-'A']=true;
        }

        for(int i=0;i<26;i++){
            if(lower[i] && upper[i])ans++;
        }

        return ans;
    }
};