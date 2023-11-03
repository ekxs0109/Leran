#include <semaphore.h>


// 使用semaphore信号量

/*
 * @lc app=leetcode.cn id=1114 lang=cpp
 *
 * [1114] 按序打印
 */

// @lc code=start
class Foo
{
protected:
    sem_t job1Done;
    sem_t job2Done;

public:
    Foo()
    {
        sem_init(&job1Done,0,0);
        sem_init(&job2Done,0,0);
    }

    void first(function<void()> printFirst)
    {
        printFirst();

        sem_post(&job1Done);
    }

    void second(function<void()> printSecond)
    {

        sem_wait(&job1Done);
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        sem_post(&job2Done);
    }

    void third(function<void()> printThird)
    {
        
        sem_wait(&job2Done);
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};
// @lc code=end
