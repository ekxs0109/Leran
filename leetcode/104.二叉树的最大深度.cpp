// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <queue>
#include "commoncppproblem104.h"

using namespace std;
// @before-stub-for-debug-end

// 深度优先遍历
// 时间复杂度：O(n)
// 空间复杂度：O(1)

/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        return max(maxDepth(root->left), maxDepth(root->right))+1;
    }
};
// @lc code=end

