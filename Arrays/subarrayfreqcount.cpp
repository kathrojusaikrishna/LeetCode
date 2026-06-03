// Problem: Subarray frequency count queries
// Difficulty: Medium
// Approach: map and binary search
// Time: O(nlogn)
// Space: O(n) 

class Solution {
  public:
    
    int upper_bound(vector<int>& v, int &target){
        int low =0;
        int high = v.size()-1;
        int ans = v.size();
        
        while(low<= high){
            int mid = low + (high-low)/2;
            
            if(v[mid]>target){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        
        return ans;
    }
    
    int lower_bound(vector<int>& v, int &target){
        int low =0;
        int high = v.size()-1;
        int ans = v.size();
        
        while(low<= high){
            int mid = low + (high-low)/2;
            
            if(v[mid]>=target){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        
        return ans;
    }
    vector<int> freqInRange(vector<int>& arr, vector<vector<int>>& queries) {
        // code here
        
        vector<int>ans;
        unordered_map<int,vector<int>>mp;
        int n = arr.size();
        
        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }
        
        int m = queries.size();
        
        for(int i=0;i<m;i++){
            int l = queries[i][0];
            int r = queries[i][1];
            int x = queries[i][2];
            
            auto& v = mp[x];
            
            int upper = upper_bound(v,r);
            int lower = lower_bound(v,l);
            
            ans.push_back(upper-lower);
        }
        
        return ans;
    }
};