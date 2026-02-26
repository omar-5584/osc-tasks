class Solution {
public:

long long prev=LLONG_MIN;
bool validate_BST=true;
void traverse(TreeNode* root)
{
     if (root == nullptr ||!validate_BST) return;
    traverse(root->left);        

    if (prev != LLONG_MIN && prev>=root->val ) {      
        validate_BST=false;

    }
    prev = root->val;            

    traverse(root->right); 
}
    bool isValidBST(TreeNode* root) {
        traverse(root);
        return validate_BST;
    }
};