// Problem: Open the lock
// Difficulty: Medium
//platform: Leetcode
// Approach: BFS for minimum steps and creating our own adj list
// Time: O(10^4 * 8)
// Space: O(10^4)

class Solution {
public:

    void up(char &ch){
        int num = ch-'0';

        num = (num+1)%10;

        ch = num + '0';
    }

    void down(char &ch){
        int num = ch-'0';

        if(num==0)num=9;
        else num -=1;

        ch = num + '0';
    }
    int openLock(vector<string>& deadends, string target) {
        
        unordered_set<string>deadEnd(deadends.begin(), deadends.end());

        if(deadEnd.count("0000"))return -1;
        if(target=="0000")return 0;
        queue<string>q;
        q.push("0000");
        deadEnd.insert("0000");

        int steps=0;

        while(!q.empty()){

            int size =q.size();

            while(size--){
                string lock = q.front();
                q.pop();

                for(int i=0;i<4;i++){

                    string upWord = lock;
                    string downWord = lock;

                    up(upWord[i]);

                    if(!deadEnd.count(upWord)){
                        if(upWord==target)return 1+steps;

                        deadEnd.insert(upWord);
                        q.push(upWord);
                    }

                    down(downWord[i]);
                    if(!deadEnd.count(downWord)){
                        if(downWord==target)return 1+steps;

                        deadEnd.insert(downWord);
                        q.push(downWord);
                    }
                }
            }

            steps++;
        }

        return -1;
    }
};