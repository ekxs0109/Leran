// @before-stub-for-debug-begin
#include <vector>
#include <queue>
#include <string>
#include "commoncppproblem101.h"

using namespace std;
// @before-stub-for-debug-end

// 时间复杂度：O(n)
// 空间复杂度：O(n)

/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    bool isSymmetric(TreeNode *root)
    {
        queue<TreeNode *> rightStack;
        queue<TreeNode *> leftStack;

        rightStack.push(root->right);
        leftStack.push(root->left);

        while (rightStack.size() != 0 && leftStack.size() != 0)
        {
            TreeNode *right = rightStack.front();
            TreeNode *left = leftStack.front();
            rightStack.pop();
            leftStack.pop();

            if((!!right && !left) || (!!left&& !right )){
                return false;
            }
            if (!!right  && !!left  &&  right->val != left->val)
            {
                return false;
            }

            bool state = false;

            if(!!right ){
                rightStack.push(right->left);
                rightStack.push(right->right);
            }
            if(!!left ){
                leftStack.push(left->right);
                leftStack.push(left->left);
            }

        }
        return true;
    }
};
// @lc code=end
