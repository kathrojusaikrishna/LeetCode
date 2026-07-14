// Problem: Word ladder
// Difficulty: Hard
//platform: Leetcode
// Approach: BFS and adj is changing every single char
// Time: O(n*m*26)
// Space: O(n*m) 

class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {

        unordered_set<string> dict(wordList.begin(), wordList.end());

        queue<string> q;
        q.push(beginWord);
        dict.erase(beginWord);

        if(dict.count(endWord)==0)return 0;

        int steps = 1;

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                string word = q.front();
                q.pop();
                for (int i = 0; i < word.size(); i++) {
                    for (char ch = 'a'; ch <= 'z'; ch++) {

                        string newWord = word;
                        if (ch == newWord[i])
                            continue;
                        newWord[i] = ch;

                        if (newWord == endWord)
                            return 1 + steps;
                        if (dict.count(newWord)) {
                            dict.erase(newWord);
                            q.push(newWord);
                        }
                    }
                }
            }

            steps++;
        }

        return 0;
    }
};