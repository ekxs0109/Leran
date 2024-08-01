// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem766.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=766 lang=cpp
 *
 * [766] 托普利茨矩阵
 */


// [1,2,3,4]
// [5,1,2,3]
// [9,5,1,2]
// rang1
// tempX =2,tempY=0 xLen=2,yLen=2, match = 9
// rang2
// tempX =2,tempY=1 xLen=2,yLen=2, match = 5
// tempX =1,tempY=0 xLen=2,yLen=2, match = 5
// range3
// tempX =2,tempY=2 xLen=2,yLen=2, match = 1
// tempX =1,tempY=1 xLen=2,yLen=2, match = 1
// tempX =0,tempY=0 xLen=2,yLen=2, match = 1
// range4
// tempX =2,tempY=3 xLen=2,yLen=2, match = 2
// ...
// range5
// tempX =1,tempY=3 xLen=2,yLen=2, match = 3
// tempX =0,tempY=2 xLen=2,yLen=2, match = 3
// range6
// tempX =0,tempY=3 xLen=2,yLen=2, match = 4



// [1,2]
// [2,2]

// @lc code=start
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int xLen = matrix.size()-1;
        int yLen = matrix[xLen].size()-1;
        int x = xLen;
        int y = 0;
        while(x>=0){
            int match = matrix[x][y];
            int tempX = x-1;
            int tempY = y-1;
            while(tempX>=0 && tempY>=0){
                if(match != matrix[tempX][tempY]){
                    return false;
                }
                tempX--;
                tempY--;
            }

            if(y<yLen){
                y++;
            }else{
                x--;
            }
        }
        return true;

    }
};
// @lc code=end

