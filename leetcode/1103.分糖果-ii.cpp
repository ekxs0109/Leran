// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <iostream>
#include "commoncppproblem1103.h"

using namespace std;
// @before-stub-for-debug-end
// candies = 20, num_people = 3
// [0] = 1 + 4  5 
// [1] = 2 + 5  7
// [2] = 3 + 5  8(9)

// 1 2 3 4 5
// 0 1 3 5 7 . (x -1)*2+1

// candies = 20, num_people = 4
// [0] = 1 + 5  6
// [1] = 2 + 6  8
// [2] = 3 + 7  10(6)
// [2] = 4 + 8  12(4)

// 暴力解 
// 时间复杂度：O(max(根号G, N)), G为糖果数量，N为人数
// 空间复杂度：O(1)

// TODO: 使用等差数列解

/*
 * @lc app=leetcode.cn id=1103 lang=cpp
 *
 * [1103] 分糖果 II
 */

// @lc code=start
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res;
        int i = 0;
        while(candies>0||i<num_people){
            i++;
            if(i<= num_people){
                res.push_back(max(candies-i <0? candies:i, 0) );
                candies-=i;
            }else{
                int cur = (int)(i/num_people) * num_people + i%num_people;;
                int index = i%num_people ==0 ? (num_people-1): i%num_people-1; // 如果是最后一个，取总人数-1
                res[index]+= candies-i<0?candies:cur;
                candies-=cur;
            }
        }
        return res;
    }
};
// @lc code=end

