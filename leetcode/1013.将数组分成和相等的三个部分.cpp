// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <numeric>
#include "commoncppproblem1013.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=1013 lang=cpp
 *
 * [1013] 将数组分成和相等的三个部分
 */

// @lc code=start
class Solution
{
public:

    bool canThreePartsEqualSum(vector<int> &arr)
    {
        int initSum = accumulate(arr.begin(), arr.end(), 0),
        len = arr.size();
        if(initSum%3 !=0){
            return false;
        }

        int target = initSum/3, i = 0, curSum =0 ;

        while(i< len-2){
            curSum += arr[i++];
            if(target == curSum){
                break;
            }
        }
        if(target!=curSum){
            return false;
        }
        curSum = 0;
        while(i<len-1){
            curSum += arr[i++];
            if(target == curSum){
                return true;
            }
        }
        return false;
    }
};
// @lc code=end
