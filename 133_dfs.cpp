/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

/*
    1、dfs递归的方式进行
        cur_copy_node = copy(cur_node);
        for neighbor in cur_node->neighbors:
            if not visited:
                cur_copy_node->neighbors.push_back(dfs(neighbor))
            else:
                cur_copy_node->neighbors.push_back(already_node);

    2、dfs迭代的方式
        push (node 1, node 1 copy) into stack;
        pop one pair out of the stack
        for neighbor in the neighbors of cur_node:
            copy neighbor and push it into cur_node_copy->neighbors
            if neighbor not visited, push the pair relation of neighbor and copy_neighbor into stack
*/

// class Solution {
// private:
//     unordered_map<int, Node*> visited;
// public:
//     Node* cloneGraph(Node* node) {
//         if (node == nullptr) return nullptr;
//         Node* node_copy = new Node(node->val);
//         visited.emplace(node->val, node_copy);
//         for (auto neighbor : node->neighbors) {
//             if (visited.find(neighbor->val) != visited.end()) {
//                 Node* neighbor_copy = visited[neighbor->val];
//                 node_copy->neighbors.emplace_back(neighbor_copy);
//             } else {
//                 node_copy->neighbors.emplace_back(cloneGraph(neighbor));
//             }
//         }
//         return node_copy;
//     }
// };

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;
        stack<pair<Node*, Node*>> stk;
        unordered_map<int, Node*> visited;
        Node* node_copy = new Node(node->val);
        stk.push(make_pair(node, node_copy));
        visited.emplace(node->val, node_copy);
        while (!stk.empty()) {
            auto cur_pair = stk.top();
            stk.pop();
            Node* cur_node = cur_pair.first;
            Node* cur_node_copy = cur_pair.second;
            for (auto neighbor : cur_node->neighbors) {
                int val = neighbor->val;
                if (visited.find(val) == visited.end()) {
                    Node* neighbor_copy = new Node(val);
                    visited.emplace(val, neighbor_copy);
                    stk.push(make_pair(neighbor, neighbor_copy));
                }
                Node* neighbor_copy = visited[val];
                cur_node_copy->neighbors.emplace_back(neighbor_copy);
                // cout<< "cur_node: " << cur_node_copy->val << ", copy neighbor: " << neighbor_copy->val << endl;
            }
        }
        // cout << "node_copy val: " << node_copy->val << ", neighbor num :" << node_copy->neighbors.size() << endl;
        return node_copy;
    }
};
