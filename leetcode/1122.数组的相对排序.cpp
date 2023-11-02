// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <iostream>

using namespace std;
// @before-stub-for-debug-end

// 自定义排序解， 自己实现的插入排序较慢，leetcode官方解法为自定义std::sort

// 时间复杂度：O(n^2) 插入排序的时间
// 空间复杂度：O(n) n是arr2的长度

/*
 * @lc app=leetcode.cn id=1122 lang=cpp
 *
 * [1122] 数组的相对排序
 */

// @lc code=start
class Solution
{
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {
        unordered_map<int, int> sortMap;

        for (int i = 0; i < arr2.size(); i++)
        {
            sortMap[arr2[i]] = i;
        }

        int n = arr1.size();

        for (int i = 0; i < n - 1; i++)
        {
            int minIndex = i;
            for (int j = i + 1; j < n; j++)
            {
                if (sortMap.count(arr1[j]) > 0)
                {
                    if(sortMap.count(arr1[minIndex])>0){
                        minIndex = (sortMap[arr1[minIndex]] <sortMap[arr1[j]]) ?minIndex: j;
                    }else{
                        minIndex = j;
                    }
                }
                else if ( sortMap.count(arr1[minIndex]) ==0 && arr1[j] < arr1[minIndex])
                {
                    minIndex = j;
                }
            }
            swap(arr1[i], arr1[minIndex]);
        }

        return arr1;
    }
};
// @lc code=end
