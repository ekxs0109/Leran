// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <stack>
#include <cmath>
#include "commoncppproblem559.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=559 lang=cpp
 *
 * [559] N 叉树的最大深度
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
struct StackNode
{
    Node *node;
    int deep;
};

class Solution
{
public:
    int maxDepth(Node *root)
    {
        stack<StackNode> stk;
        if (root != nullptr)
        {
            StackNode node;
            node.deep = 1;
            node.node = root;
            stk.push(node);
        }

        int res = 0;
        while (!stk.empty())
        {
            StackNode cur = stk.top();
            stk.pop();

            for (auto item : cur.node->children)
            {
                StackNode node;
                node.deep = cur.deep + 1;
                node.node = item;
                stk.push(node);
            }
            res = max(cur.deep, res);
        }

        return res;
    }
};
// @lc code=end
