// Problem: Range min query
// Difficulty: Medium
// Platform: Geeksforgeeks
// Approach: Segment tree
// Time: O(q.log(n))
// Space: O(n)

class SegmentTree{
  public:
    vector<int>tree;
    
    void build(int node, int start, int end, vector<int>&arr){
        if(start == end){
            tree[node] = arr[start];
            return;
        }
        
        int mid = start + (end-start)/2;
        
        build(node*2,start,mid,arr);
        build(node*2+1,mid+1,end,arr);
        
        tree[node] = min(tree[node*2],tree[node*2+1]);
    }
    
    int query(int node, int start, int end, int l, int r){
        
        if(end < l || start > r){
            return INT_MAX;
        }
        if(l <= start && end <= r){
            return tree[node];
        }
        
        int mid = start + (end-start)/2;

        int left = query(node*2,start,mid,l,r);
        int right = query(node*2+1,mid+1,end,l,r);
        
        return min(left,right);
    }
    
    SegmentTree(vector<int>& arr){
        int n = arr.size();
        
        tree.resize(4*n);
        
        build(1,0,arr.size()-1,arr);
        
    }
};

class Solution {
  public:
    vector<int> rangeMinQuery(vector<int>& arr, vector<vector<int>>& queries) {
        // code here
        
        SegmentTree A(arr);
        
        vector<int>ans;
        for(auto& q : queries){
            int l = q[0];
            int r = q[1];
            
            ans.push_back(A.query(1,0,arr.size()-1,l,r));
        }
        
        return ans;
        
    }
};