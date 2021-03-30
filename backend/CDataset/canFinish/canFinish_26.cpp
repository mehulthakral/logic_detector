struct Node {
    int indegrees;
    vector<int> outdegrees;
    Node() : indegrees(0), outdegrees() {}
};

class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        if (empty(prerequisites)) return true;

        // an array to represent the graph
        vector<Node*> nodes(n, nullptr);
        
        // create the graph
        for (const auto& course : prerequisites) {
            if (nodes[course[0]] == nullptr) nodes[course[0]] = new Node();
            if (nodes[course[1]] == nullptr) nodes[course[1]] = new Node();
            nodes[course[0]]->indegrees++;
            nodes[course[1]]->outdegrees.emplace_back(course[0]);
        }

        stack<Node*> to_process;
        int prerequisites_count = 0;
        for (const auto& node : nodes) {
            if (node != nullptr) {
                ++prerequisites_count;
                // if the node have no indegrees
                // we add it to the stack
                if (node->indegrees == 0) {
                    to_process.emplace(node);
                }
            }
        }

        int count = 0;
        // standard depth-first search
        while (!empty(to_process)) {
            auto node = to_process.top();
            to_process.pop();
            count++;
            for (auto next_node : node->outdegrees) {
                // once we process a node, we want to decrement
                // the indegree count for all of its outnodes
                --nodes[next_node]->indegrees;
                if (nodes[next_node]->indegrees == 0) {
                    // if an outnode has an indegree count of 0
                    // it should be processed next
                    to_process.emplace(nodes[next_node]);
                }
            }
        }
        
        // the number of nodes with prerequisites
        // must match the count of the nodes we processed
        return count == prerequisites_count;
    }
};
