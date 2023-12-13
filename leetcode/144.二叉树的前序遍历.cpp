// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <stack>
#include "commoncppproblem144.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == nullptr) return {};
        stack<TreeNode*> que;
        que.push(root);
        vector<int> res;
        while(!que.empty()){
            auto node = que.top();
            que.pop();
            res.push_back(node->val);

            if(node->right) que.push(node->right);
            if(node->left) que.push(node->left);
        }

        return res;

    }
};
// @lc code=end

