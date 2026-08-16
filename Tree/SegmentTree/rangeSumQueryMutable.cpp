// Problem: Range sum query mutable
// Difficulty: Medium
// Platform: Leetcode
// Approach: Segment tree
// Time: O(q.log(n))
// Space: O(n)

class NumArray {
public:
    vector<int>tree;
    int n;
    NumArray(vector<int>& nums) {
        
        n = nums.size();
        tree.resize(4*n);

        build(1,0,nums.size()-1,nums);
    }
    
    void build(int node, int start, int end, vector<int>& nums){

        if(start==end){
            tree[node] = nums[start];
            return;
        }
        int mid = start + (end-start)/2;
        build(node*2,start,mid,nums);
        build(node*2+1,mid+1,end,nums);

        tree[node] = tree[node*2] + tree[node*2+1];
    }

    
    void update(int index, int val) {
        updateS(1,index,0,n-1,val);
    }
    void updateS(int node, int idx, int start, int end, int value){

        if(start==end){
            tree[node]=value;
            return;
        }

        int mid = start + (end-start)/2;

        if(idx<=mid){
            updateS(node*2,idx,start,mid,value);
        }else{
            updateS(node*2+1,idx,mid+1,end, value);
        }

        tree[node] = tree[node*2] + tree[node*2+1];
    }

    int query(int node, int start, int end, int l, int r){

        if(end<l || start>r){
            return 0;
        }

        if(l <= start && end <= r){
            return tree[node];
        }

        int mid = start + (end-start)/2;

        int left = query(node*2,start,mid,l,r);
        int right = query(node*2+1,mid+1,end,l,r);

        return left+right;
    }
    
    int sumRange(int left, int right) {
        return query(1,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */