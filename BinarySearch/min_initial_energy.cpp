// problem : minimum initial energy to finish tasks
// Level : Hard
// Time complexity : O(n log n)
// space complexity : O(1)

class Solution {
public:

    bool solve(int energy, vector<vector<int>>& tasks){

        int n =tasks.size();

        for(int i=0;i<n;i++){
            int actual = tasks[i][0];
            int minimum = tasks[i][1];

            if(energy < minimum)return false;

            energy -= actual;
        }

        return true;
    }

    int minimumEffort(vector<vector<int>>& tasks) {
        
        int low = 0;
        int high = 0;

        sort(tasks.begin(),tasks.end(), [](vector<int>&a, vector<int>&b){
            return (a[1]-a[0])>(b[1]-b[0]);
        });

        for(int i=0;i<tasks.size();i++){
            low = max(tasks[i][1], low); 
            high += tasks[i][1];
        }
        while(low < high){

            int mid = low + (high-low)/2;

            bool value = solve(mid,tasks);

            if(value)high=mid;
            else low=mid+1;

        }

        return low;
    }
};