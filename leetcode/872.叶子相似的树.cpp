// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <stack>
#include "commoncppproblem872.h"
#include <iostream>

using namespace std;
// @before-stub-for-debug-end

//  遍历root1 和root2 添加最子树到字符串，最后对比字符串是否相同
// 时间复杂度：O(n1+n2)
// 空间复杂度：O(n1+n2)

/*
 * @lc app=leetcode.cn id=872 lang=cpp
 *
 * [872] 叶子相似的树
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
    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        string root1Str;
        string root2Str;

        stack<TreeNode *> st;
        st.push(root1);

        while (!st.empty())
        {
            auto node = *st.top();
            st.pop();
            if (node.left)
                st.push(node.left);
            if (node.right)
                st.push(node.right);
            if (!node.left && !node.right)
            {
                root1Str += to_string(node.val);
            }
        }

        st.push(root2);
        while (!st.empty())
        {
            auto node = *st.top();
            st.pop();
            if (node.left)
                st.push(node.left);
            if (node.right)
                st.push(node.right);
            if (!node.left && !node.right)
            {
                root2Str += to_string(node.val);
            }
        }

        // cout<< root1Str << " --- " << root2Str << endl;

        return root1Str == root2Str;
    }
};
// @lc code=end
