// Problem: Minimum steps to reach n from 1
// Difficulty: Easy
//platform: Geeksforgeeks
// Approach: Greedy
// Time: O(logn)
// Space: O(1)


class Solution {
  public:
    int minimumStep(int n) {
        // code here
        
        // vector<int>dist(n+1,-1);
        // queue<int>q;
        // q.push(1);
        // dist[1]=0;
        
        
        // while(!q.empty()){
        //     int node = q.front();
        //     q.pop();
            
        //     if(node==n)return dist[n];
        //     if(node+1 <=n && dist[node+1]==-1){
        //         dist[node+1]=dist[node]+1;
        //         q.push(node+1);
        //     }
            
        //     if(node*3 <= n && dist[node*3]==-1){
        //         dist[node*3] = dist[node]+1;
        //         q.push(node*3);
        //     }
        // }
        // return -1;
        
        int ans=0;
        while(n>1){
            if(n%3==0){
                n /= 3;
            }else{
                n--;
            }
            ans++;
        }
        return ans;
        
    }
};