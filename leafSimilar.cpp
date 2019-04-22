#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
int i;
bool leafSimilar(struct TreeNode *root1, struct TreeNode *root2)
{
    int leaves[200];
    dfs(root1,leaves);
    dfs(root2,leaves);
    int flag = true;
    for (int j = 0; i < 200; i++)
    {
        if (leaves[2*i] != leaves[2*i+1])
        {
            flag = 0;
            break;
        }
    }
    if (flag)
    {
        return true;
    }
    else
    {
        return false;
    }
}


void dfs(struct TreeNode *root,  int *leaves)
{
    if (root==NULL)
        return;
    if (root->left == NULL && root->right == NULL)
        leaves[i++]=root->val;
    dfs(root->left, leaves);
    dfs(root->right,leaves);
}
