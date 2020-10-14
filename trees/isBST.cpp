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
