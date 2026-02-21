class Solution {
public:
vector<int>vec;
void traverse(TreeNode* root)
{
        if(root==NULL)
{
    return;
}
traverse(root->left);
vec.push_back(root->val);
traverse(root->right);
}

    vector<int> inorderTraversal(TreeNode* root) {
traverse(root);
return vec;


    }
};