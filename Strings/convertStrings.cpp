// Problem: Convert one string to another with constraints
// Difficulty: Easy
// Platform: Geeksforgeeks
// Approach: two-pointer
// Time: O(n+m)
// Space: O(1)  

class Solution {
  public:
    bool isItPossible(string &s1, string &s2) {
        // code here
        
        if(s1.size()!=s2.size())return false;
        int i=0;
        int j=0;
        
        while(i<s1.size() && j<s2.size()){
            while(s1[i]=='#')i++;
            while(s2[j]=='#')j++;
            
            if(i==s1.size() || j==s2.size()){
                return i==s1.size() && j==s2.size();
            }
            
            if(s1[i] != s2[j])return false;
            
            if(s1[i]=='A' && i<j)return false;
            if(s1[i]=='B' && j<i)return false;
            i++;
            j++;
            
        }
        
        while(i<s1.size() && s1[i]=='#')i++;
        while(j<s2.size() && s2[j]=='#')j++;
        
        return i==s1.size() && j==s2.size();
    }
};