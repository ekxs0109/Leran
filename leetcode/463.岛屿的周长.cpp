// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem463.h"

using namespace std;
// @before-stub-for-debug-end

// 遍历
// 时间复杂度：O(m*n)
// 空间复杂度：O(1)

/*
 * @lc app=leetcode.cn id=463 lang=cpp
 *
 * [463] 岛屿的周长
 */

// @lc code=start
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int col = grid.size()-1, row= grid[0].size()-1;

        int res = 0;

        for(int i = 0 ; i <= col ; i ++){
            for(int j = 0 ; j <= row ; j ++){
                if(grid[i][j] != 1) continue;
                bool hasLeft =  j>0 && grid[i][j-1] == 1;
                bool hasTop = i>0 && grid[i-1][j] == 1;
                bool hasRight = j<row  && grid[i][j+1] ==1;
                bool hasBottom = i<col && grid[i+1][j] == 1;
                if(!hasLeft) res++;
                if(!hasTop) res++;
                if(!hasRight) res++;
                if(!hasBottom) res++;

            }
        }
        return res;

    }
};
// @lc code=end

