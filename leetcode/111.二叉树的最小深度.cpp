// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <queue>
#include "commoncppproblem111.h"

using namespace std;
// @before-stub-for-debug-end

// 广度优先
// 时间复杂度：O(n)
// 空间复杂度：O(n)

/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    struct QueueNode
    {
        TreeNode * node;
        int dep;
        QueueNode(TreeNode* node ,int dep): node(node), dep(dep){}
    };
    
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        queue<QueueNode> que;

        que.push({root, 1});

        while(!que.empty()){
            auto item = que.front();
            que.pop();

            if(!(item.node->left) && !(item.node->right)){
                return item.dep;
            }
            if(!!(item.node->left)){
                que.push({item.node->left, item.dep+1});
            }
            if(!!(item.node->right)){
                que.push({item.node->right, item.dep+1});
            }
        }
        return 0;
    }
};
// @lc code=end

