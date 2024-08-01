// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem572.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一棵树的子树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    bool vail(TreeNode *l, TreeNode *r)
    {
        if ((l == nullptr && r != nullptr) || (l != nullptr && r == nullptr))
            return false;
        if(l==nullptr && r== nullptr)
            return true;
        if (l->val != r->val)
            return false;
        return vail(l->left, r->left) && vail(l->right, r->right);
    }
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        return root != nullptr &&
               (vail(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot));
    }
};
// @lc code=end
