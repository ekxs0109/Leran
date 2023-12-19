// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <unordered_map>
#include "commoncppproblem509.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
class Solution {
private:
    unordered_map<int,int> cache;
public:
    int fib(int n) {
        if(n <2) return n;
        if(!cache[n]) {
            cache[n] = fib(n-1) + fib(n-2);
        }
        return cache[n];
    }
};
// @lc code=end

