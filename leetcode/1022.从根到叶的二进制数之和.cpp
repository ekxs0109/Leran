// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <iostream>
#include "commoncppproblem1022.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=1022 lang=cpp
 *
 * [1022] 从根到叶的二进制数之和
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
    uint reverseBits(uint n, uint dep)
    {
        uint reversedNum = 0;
        for (int i = 0; i < dep; i++) {
            reversedNum = (reversedNum << 1) | (n & 1);
            n >>= 1;
        }
        return reversedNum;
    }
    int sumRootToLeaf(TreeNode *root)
    {
        int sum = 0;
        auto func = [&sum, this](auto &&self, TreeNode *inode, uint val, uint dep) -> void
        {
            auto node = *inode;
            if ((node.val) == 1)
            {
                val ^= node.val << dep;
            }
            if (node.left)
            {
                self(self, node.left, val, dep + 1);
            }
            if (node.right)
            {
                self(self, node.right, val, dep + 1);
            }
            if (!node.right && !node.left)
            {
                sum += this->reverseBits(val,dep+1);
            }
        };
        func(func, root, 0, 1);
        return sum;
    }
};
// @lc code=end
