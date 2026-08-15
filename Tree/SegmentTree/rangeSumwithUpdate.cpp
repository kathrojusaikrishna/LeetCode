// Problem: Range sum with update
// Difficulty: Medium
// Platform: Geeksforgeeks
// Approach: Segment tree
// Time: O(n+q.log(n))
// Space: O(n)

class SegmentTree{
  public:
    void build(int node, int start, int end, vector<int>& arr){
        
        if(start==end){
            tree[node]=arr[start];
            return;
        }
        
        int mid = start + (end-start)/2;
        
        build(node*2,start,mid,arr);
        build(node*2+1,mid+1,end,arr);
        
        tree[node] = tree[node*2] + tree[node*2+1];
    }
    
    int query(int node,int start, int end, int l, int r){
        
        if(end < l || start > r){
            return 0;
        }
        if (l <= start && end <= r){
            return tree[node];
        }
        
        int mid = start + (end-start)/2;
        
        int left = query(node*2,start,mid,l,r);
        int right = query(node*2+1,mid+1,end,l,r);
        
        return left + right;
    }
    
    void update(int node,int idx,int start, int end, int value){
        
        if(start==end){
            tree[node]=value;
            return;
        }
        int mid = start + (end-start)/2;
        
        if(idx <= mid){
            update(node*2,idx,start,mid,value);
        }else{
            update(node*2+1,idx,mid+1,end,value);
        }
        
        tree[node] = tree[node*2] + tree[node*2+1];
    }
  public:
  vector<int>tree;
    SegmentTree(vector<int>& arr){
        int n = arr.size();
        
        tree.resize(4*n);
        
        build(1,0,n-1,arr);
    }
  
};

class Solution {
  public:
    vector<int> rangeSumQueries(vector<int>& arr, vector<vector<int>>& queries) {
        // code here
        
        SegmentTree A(arr);
        vector<int>ans;
        
        for(int i=0;i<queries.size();i++){
            if(queries[i][0]==1){
                int l = queries[i][1];
                int r = queries[i][2];
                ans.push_back(A.query(1,0,arr.size()-1,l,r));
            }else{
                int index = queries[i][1];
                int value = queries[i][2];
                A.update(1,index,0,arr.size()-1,value);
            }
        }
        
        return ans;
        
        
    }
};