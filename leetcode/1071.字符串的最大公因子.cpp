// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem1071.h"

using namespace std;
// @before-stub-for-debug-end

// str1 = "ABABA" str2 = "AB"
// str1+str2 == str2+str1 // 如果能整除，str1+str2和str2+str1应该是一致的
// 求公因数，C++ 内置__gcd 

// 时间复杂度：O(n) 字符串比较是O(n)复杂度， 公因数计算是O(log n)
// 空间复杂度：O(1)


/*
 * @lc app=leetcode.cn id=1071 lang=cpp
 *
 * [1071] 字符串的最大公因子
 */

// @lc code=start
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if((str1 + str2) != (str2+ str1)) return "";
        return str1.substr(0, __gcd((int)str1.length(), (int)str2.length())); // __gcd 辗转相除法取公约数gcd(a,b) = gcd(b,a mod b)
    }
};
// @lc code=end

