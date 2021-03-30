class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) return {}; // If there is no root return empty.
        
        vector<int> resVec; // Store results here
        stack<TreeNode*> ourStack; // Store the nodes we traverse here
        TreeNode* currentNode = root; // Set a pointer ot the first node.
        
        while (1) { // Continue running until our break condition is reached
            if (currentNode) { // If the node exists, push it into the stack
                ourStack.push(currentNode);
                currentNode = currentNode->left; // Move left.
            } else { // If there is no left, and the stack isn't empty, push the topmost element
                if (ourStack.empty()) break; // into our result (this is the last number that entered the stack)
                resVec.push_back(ourStack.top()->val);
                currentNode = ourStack.top(); // take this same node and see if you can go right with it
                ourStack.pop(); // Now that it's captured in currentNode, you can remove it from the stack
                currentNode = currentNode->right;
            } // If you can't go right with it, then you take the next top element, push its value into the
        } // result vector, and see whether you can go right with it. This ccontinues until your stack is empty.
        return resVec;
    }
};