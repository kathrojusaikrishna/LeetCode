// Problem: Range vowel count queries
// Difficulty: Medium
//platform: Geeksforgeeks
// Approach: Prefix count of vowels
// Time: O(n)
// Space: O(n)

class Solution {
  public:
    
    bool isVowel(char ch){
        
        if(ch=='a' || ch=='e' ||ch=='i' ||ch=='o' || ch=='u')return true;
        
        return false;
    }
    vector<int> countVowels(string &s, vector<vector<int>> &queries) {
        // code here
        
        vector<int>ans;
        int n = s.size();
        vector<int>prefix(n,0);
        
        for(int i=0;i<n;i++){
            
            if(i==0 && isVowel(s[i])){
                prefix[i]++;
            }else{
                if(isVowel(s[i])){
                    prefix[i] = prefix[i-1]+1;
                }else{
                    prefix[i] =prefix[i-1];
                }
            }
        }
        
        for(auto& q : queries){
            int l = q[0];
            int r = q[1];
            
            ans.push_back(prefix[r]-prefix[l-1]);
        }
        
        return ans;
    }
};