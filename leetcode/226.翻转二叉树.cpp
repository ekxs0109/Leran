// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <stack>
#include "commoncppproblem226.h"

using namespace std;
// @before-stub-for-debug-end

// 时间复杂度：O(n)
// 空间复杂度：O(n)

/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
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
    TreeNode* invertTree(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode* tempNode;
        stk.push(root);

        while(!stk.empty()){
            TreeNode* node  = stk.top();
            stk.pop();
            if(node ==nullptr) continue;
            tempNode = node->left;
            node->left = node->right;
            node->right = tempNode;
            
            stk.push(node->left);
            stk.push(node->right);
        }
        return root;
    }
};
// @lc code=end

