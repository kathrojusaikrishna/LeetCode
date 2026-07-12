// Problem: Rank transform of an array
// Difficulty: Easy
// Approach: sort and check index
// Time: O(nlogn)
// Space: O(n)

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        
        
        vector<int>ans;
        vector<int>temp = arr;
        sort(temp.begin(),temp.end());

        unordered_map<int,int>mp;
        int rank=1;

        for(int i=0;i<temp.size();i++){
            if(mp.find(temp[i])==mp.end()){
                mp[temp[i]]=rank++;
            };
        }

        for(int i=0;i<arr.size();i++){
            ans.push_back(mp[arr[i]]);
        }
        return ans;
    }
};