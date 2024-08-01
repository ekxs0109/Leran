// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <list>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=705 lang=cpp
 *
 * [705] 设计哈希集合
 */

// @lc code=start
class MyHashSet
{
private:
    vector<list<int>> data;
    static const int base = 769; // 质数
    static int hash(int key)
    {
        return key % base;
    }

public:
    MyHashSet() : data(base)
    {
    }

    void add(int key)
    {
        int h = hash(key);
        for (auto it = data[h].begin(); it != data[h].end(); it++)
        {
            if (*it == key)
                return;
        }
        data[h].push_back(key);
    }

    void remove(int key)
    {
        int h = hash(key);
        for (auto it = data[h].begin(); it != data[h].end(); it++)
        {
            if (*it == key)
            {
                data[h].erase(it);
            }
        }
    }

    bool contains(int key)
    {
        int h = hash(key);
        for (auto it = data[h].begin(); it != data[h].end(); it++)
        {
            if (key == *it)
                return true;
        }
        return false;
    }
};

int main()
{
    MyHashSet myHashSet = MyHashSet();
    myHashSet.add(1);      // set = [1]
    myHashSet.add(2);      // set = [1, 2]
    myHashSet.contains(1); // 返回 True
    myHashSet.contains(3); // 返回 False ，（未找到）
    myHashSet.add(2);      // set = [1, 2]
    myHashSet.contains(2); // 返回 True
    myHashSet.remove(2);   // set = [1]
    myHashSet.contains(2);

    return 0;
}

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
// @lc code=end
