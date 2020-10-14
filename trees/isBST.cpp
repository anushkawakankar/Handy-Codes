void traverse(Node* root, int l, int r, bool &b)
{
    if(!b || !root) return;
    if(root->data < l || root->data > r)
        b = 0;
    traverse(root->left,l,root->data-1,b);
    traverse(root->right, root->data+1,r,b);
}

// return true if the given tree is a BST, else return false
bool isBST(Node* root) {
    // Your code here
    bool b = 1;
    traverse(root, INT_MIN,INT_MAX,b);
    return b;
}

// return true if FullBst
bool isFullTree (struct Node* root)
{
    // If empty tree
    if (root == NULL)
        return true;

    // If leaf node
    if (root->left == NULL && root->right == NULL)
        return true;

    // If both left and right are not NULL, and left & right subtrees
    // are full
    if ((root->left) && (root->right))
        return (isFullTree(root->left) && isFullTree(root->right));

    // We reach here when none of the above if conditions work
    return false;
}
