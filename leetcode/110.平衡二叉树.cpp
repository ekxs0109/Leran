// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem110.h"

using namespace std;
// @before-stub-for-debug-end

// 时间复杂度：O(n^2)
// 空间复杂度：O(n)

/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    int dfs(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        return max(dfs(root->left), dfs(root->right)) + 1;
    }
    bool isBalanced(TreeNode *root)
    {
        if(root == nullptr)
            return true;
        return abs(dfs(root->left) - dfs(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
};
// @lc code=end
