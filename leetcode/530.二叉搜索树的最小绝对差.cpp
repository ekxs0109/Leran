// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <stack>
#include <limits.h>
#include <cmath>
#include "commoncppproblem530.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
    int getMinimumDifference(TreeNode *root)
    {
        stack<TreeNode*> st;
        int res = INT_MAX;

        TreeNode* lastNode = nullptr;

        while(root !=nullptr || !st.empty()){
            while(root !=nullptr){
                st.push(root);
                root = root->left;
            }
            auto node = st.top();
            st.pop();
            root = node->right;

            if(lastNode !=nullptr){
                res = min(res, abs(lastNode->val - node->val));
            }
            lastNode = node;
        }

        return res;
    }
};
// @lc code=end
