// Problem: Evaluate the brace pair of a string
// Difficulty: Medium
// Platform: Leetcode
// Approach: hashmap + iteration
// Time: O(n)
// Space: O(k)  

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        
        unordered_map<string,string>mp;
        int n = knowledge.size();
        
        for(int i=0;i<n;i++){
            mp[knowledge[i][0]] = knowledge[i][1];
        }

        string ans="";

        for(int i=0;i<s.size();){
            if(s[i]==')')continue;
            if(s[i]=='('){
                int j=i+1;

                string temp="";
                while(s[j]!=')'){
                    temp += s[j];
                    j++;
                }

                if(mp.find(temp)!= mp.end()){
                    ans += mp[temp];
                }else{
                    ans += '?';
                }
                i=j+1;
            }
            else{
                ans += s[i];
                i++;
            }
        }

        return ans;
    }
};