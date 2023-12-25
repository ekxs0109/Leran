// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem543.h"
#include <stack>
#include <algorithm>
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
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

private:
    int res = 1;
public:

    int deep(TreeNode* node){
        if(node == nullptr){
            return 0;
        }

        int leftCout = deep(node->left);
        int rightCount = deep(node->right);

        res = max(res, leftCout + rightCount + 1);
        return max(leftCout,rightCount) +1 ;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        deep(root);
        return res -1;
    }
};
// @lc code=end

