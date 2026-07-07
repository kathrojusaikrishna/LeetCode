// Problem: Clone graph
// Difficulty: Medium
//platform: Leetcode
// Approach: hash map
// Time: O(V+E)
// Space: O(V+E)

class Solution {
public:
    unordered_map<Node*, Node*>mp;
    Node* cloneGraph(Node* node) {

        if(!node)return nullptr;

        if(mp.count(node)){
            return mp[node];
        }

        Node* clone = new Node(node->val);

        mp[node]=clone;

        for(Node* &neighbor : node->neighbors){
            clone->neighbors.push_back(cloneGraph(neighbor));
        }

        return clone;
    }
};