// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <stack>
#include <unordered_set>
#include "commoncppproblem733.h"

using namespace std;
// @before-stub-for-debug-end

// [1,1,1]
// [1,1,0]
// [1,0,1]

// [0,0,0]
// [0,0,0]

/*
 * @lc app=leetcode.cn id=733 lang=cpp
 *
 * [733] 图像渲染
 */

// @lc code=start

struct XY
{
    int X;
    int Y;
};

class Solution
{
public:
    string xy_to_string(XY node)
    {
        return to_string(node.X) + "*" + to_string(node.Y);
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        unordered_set<string> usedXY;
        stack<XY> stk;
        int xLen = image.size()-1;
        int yLen = image[0].size()-1;

        XY item;
        item.X = sr;
        item.Y = sc;

        stk.push(item);

        int init = image[sr][sc];

        while (!stk.empty())
        {
            auto node = stk.top();
            stk.pop();
            if(usedXY.count(xy_to_string(node))|| init != image[node.X][node.Y]) continue;
            usedXY.insert(xy_to_string(node));
            image[node.X][node.Y] = color;
            if ((node.X - 1) >= 0)
            {
                XY item = {node.X - 1, node.Y};
                stk.push(item);
            }
            if ((node.X + 1) <= xLen)
            {
                XY item = {node.X + 1, node.Y};
                stk.push(item);
            }
            if ((node.Y - 1) >= 0)
            {
                XY item = {node.X, node.Y - 1};
                stk.push(item);
            }
            if ((node.Y + 1) <= yLen)
            {
                XY item = {node.X, node.Y + 1};
                stk.push(item);
            }
        }

        return image;
    }
};
// @lc code=end
