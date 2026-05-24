// Problem: Password Strength
// Difficulty: Mediium
// Approach: set and iteration
// Time: O(n)
// Space: O(n) - using set for distinct characters

class Solution {
public:

    bool isspcl(char ch){
        if(ch=='!' || ch=='@' || ch=='#' || ch=='$')return true;

        return false;
    }
    int passwordStrength(string password) {

        int ans=0;

        unordered_set<char>st;

        for(auto ch : password){
            st.insert(ch);
        }

        for(auto ch : st){
            if(isdigit(ch))ans +=3;
            else if(islower(ch))ans += 1;
            else if(isupper(ch))ans += 2;
            else if(isspcl(ch))ans += 5;
        }

        return ans;
    }
};