// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <stack>
#include "commoncppproblem222.h"

using namespace std;
// @before-stub-for-debug-end

// 时间复杂度
// 广度优先暴力解 TODO: 优化成 <O(n)的算法
// 时间复杂度：O(n)
// 空间复杂度：O(1)

/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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
    int countNodes(TreeNode* root) {
        stack<TreeNode*> st;
        st.push(root);
        int res = 0;
        while(!st.empty()){
            auto it = st.top();
            st.pop();
            if(it==nullptr) continue;
            st.push(it->left);
            st.push(it->right);

            res ++;
        }
        return res;
    }
};
// @lc code=end

