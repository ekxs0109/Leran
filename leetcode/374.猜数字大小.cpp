/*
 * @lc app=leetcode.cn id=374 lang=cpp
 *
 * [374] 猜数字大小
 */

// @lc code=start
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int p =0, q = n;
        auto res = -2;
        while(true){
            auto mid = ((q-p)>>1) +p;
            res = guess(mid);
            if(res==1){
                p=mid+1;
            }else if (res == -1){
                q= mid -1;
            }else{
                return mid;
            }
        }

    }
};
// @lc code=end

