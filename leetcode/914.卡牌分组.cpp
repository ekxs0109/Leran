// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <algorithm>
#include "commoncppproblem914.h"


using namespace std;
// @before-stub-for-debug-end

// [1,1,1,2,2,2,3,3]
//        i         x1 = 3
//        i         x1 = 3
//          i       x1 = 3 count=2
//            i     x1 = 3 count=3
//              i   x1 = 3 count=3 x1==count next

// [1,1,1,1,2,2,2,2,2,2,3,3]
//                    i     x1 =4 count=6  count> x1  x1 = __gcd(count,x1)

// 疯狂打补丁完成
// 时间复杂度：O(nlogn) 排序n log n, 下面只循环了一次，因数计算是O(log n)
// 空间复杂度：O(1)
/*
 * @lc app=leetcode.cn id=914 lang=cpp
 *
 * [914] 卡牌分组
 */

// @lc code=start
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        if(deck.size() <2) return false;
        sort(deck.begin(), deck.end());

        int x1 =0, count =1;
        bool flag = false;

        for(int i = 1; i<deck.size(); i++){
            if(!flag){
                if(deck[i] != deck[i-1]){
                    x1 = count;
                    count = 1;
                    flag = true;
                    continue;
                }
                count++;
                continue;
            }


            if(deck[i] != deck[i-1]){
                    int gcd = __gcd(count, x1);
                    if(gcd<2 || count % gcd !=0){
                        return false;
                    }
                    x1 = gcd;
       
                count = 1;
            }else{
                count++;
            }
        }
        if(flag == false){
            return true;
        }
        if(count<x1){
            return false;
        }

        int gcd = __gcd(count, x1);

        return gcd<2?false : count % gcd ==0;
    }
};
// @lc code=end

