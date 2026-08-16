// Problem: Maximum sum subarray with queries
// Difficulty: Medium
// Platform: Geeksforgeeks
// Approach: Segment tree
// Time: O(n+ q.log n)
// Space: O(n)

class SegmentTree{
  public:
    
    struct Node{
      int sum;
      int prefix;
      int suffix;
      int ans;
    };
    
    vector<Node>tree;
    
    Node merge(Node left, Node right){
        
        Node parent;
        
        parent.sum = left.sum + right.sum;
        parent.prefix = max(left.prefix, left.sum + right.prefix);
        
        parent.suffix = max(right.suffix, right.sum + left.suffix);
        
        parent.ans = max({
            left.ans,
            right.ans,
            left.suffix+right.prefix
        });
        
        return parent;
    }
    
    void build(int node, int start, int end, vector<int>&arr){
        if(start ==end){
            tree[node]={
                arr[start],
                arr[start],
                arr[start],
                arr[start]
            };
            return;
        }
        
        int mid = start + (end-start)/2;
        
        build(node*2, start,mid,arr);
        build(node*2+1, mid+1,end,arr);
        
        tree[node] = merge(tree[node*2],tree[node*2+1]);
    }
    
    Node query(int node, int start, int end, int l, int r){
        
        if(end<l || start>r){
            return {
                0,-1000000000,-1000000000,-1000000000
            };
        }
        
        if(l<= start && end <= r){
            return tree[node];
        }
        
        int mid = start + (end-start)/2;
        Node left = query(node*2, start,mid,l,r);
        Node right = query(node*2+1,mid+1,end,l,r);
        
        return merge(left,right);
    }
    
    void update(int node, int idx, int start, int end, int value){
        
        if(start == end){
            tree[node] = {value,value,value,value};
            return;
        }
        int mid = start + (end-start)/2;
        
        if(idx<=mid){
            update(node*2,idx,start,mid,value);
        }else{
            update(node*2+1,idx,mid+1,end,value);
        }
        
        tree[node] = merge(tree[node*2], tree[node*2+1]);
    }
    
    SegmentTree(vector<int>& arr){
        int n = arr.size();
        
        tree.resize(4*n);
        
        build(1,0,arr.size()-1,arr);
    }
};

class Solution {
  public:
    vector<int> largestSumQueries(vector<int>& arr, vector<vector<int>>& queries) {
        // code here
        
        SegmentTree A(arr);
        vector<int>ans;
        
        for(auto& q : queries){
            if(q[0]==1){
                int index = q[1];
                int value = q[2];
                
                A.update(1,index,0,arr.size()-1,value);
            }else{
                int l = q[1];
                int r = q[2];
                ans.push_back(A.query(1,0,arr.size()-1,l,r).ans);
            }
        }
        
        return ans;
       
    }
};