int findCeil(struct Node* root, int x) {
 if (root == NULL) return -1;

    if (root->data == x) return root->data;

   
    if (root->data < x) {
        return findCeil(root->right, x);
    }

    int ceil = findCeil(root->left, x);
    
    
    return (ceil >= x) ? ceil : root->data;
    
}