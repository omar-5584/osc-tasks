class Solution {
public:
int min_val=99999999;
int prev=INT_MIN;
void traverse(TreeNode* root)
{
     if (root == nullptr) return;
    traverse(root->left);        

    if (prev != INT_MIN) {      
        min_val = min(min_val, abs(root->val - prev));
    }
    prev = root->val;            

    traverse(root->right); 
}
    int getMinimumDifference(TreeNode* root) {
        traverse(root);
        return min_val;

    }
};