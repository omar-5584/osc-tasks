class Solution {
public:
vector<vector<int>>res;
void handleNode(TreeNode* node,int level)
{
if(node==NULL)
{
    return;
}
 if(res.size()==level)
{
    res.push_back({});
}
 if(level&1)
{
res[level].insert(res[level].begin(), node->val);
}
else
{
    res[level].push_back(node->val);
}

handleNode(node->left, level + 1);
handleNode(node->right, level + 1);

}

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
handleNode(root,0);
        return res;
    }
};