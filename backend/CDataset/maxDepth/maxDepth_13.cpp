int maxDepth(Node *root) {
    int leftHeight, rightHeight;

    if (!root)
        return 0;

    leftHeight = maxDepth(root->left);
    rightHeight = maxDepth(root->right);

    return max(leftHeight, rightHeight) + 1;
}
