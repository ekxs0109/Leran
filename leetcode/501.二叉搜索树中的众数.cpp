// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem501.h"
#include <stack>
#include <unordered_map>

using namespace std;
// @before-stub-for-debug-end

// 时间复杂度：O(n)
// 空间复杂度：O(n)

// TODO: 优化空间复杂度为O(1)
/*

 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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

    vector<int> findMode(TreeNode* root) {
        unordered_map<int , int > hash;
        stack<TreeNode*> stk;
        while(root !=nullptr || !stk.empty()){
            while(root!=nullptr){
                stk.push(root);
                root = root->left;
            }
            auto node = stk.top();
            stk.pop();
            if(node->right){
                root = node->right;
            }

            hash[node->val] ++;
        }

        vector<int> res;
        int max = 0;
        for(auto it:hash){
            if(it.second >max){
                max = it.second;
                res.clear();
                res.push_back(it.first);
            }else if(it.second == max){
                res.push_back(it.first);
            }
        }
        return res;
    }
};
// @lc code=end

