// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem112.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    int backtrack(TreeNode *node, int target, int cur )
    {
        if(node ==nullptr) return false;
        cur += node->val;
        if (node->left ==nullptr && node->right ==nullptr)
        {
            if (cur == target)
            {
                return true;
            }
            if (cur > target)
            {
                return false;
            }
        }

        if ( backtrack(node->left, target, cur ))
            return true;
        if (backtrack(node->right, target, cur))
            return true;
        return false;
    }
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        return backtrack(root, targetSum, 0);
    }
};
// @lc code=end
