
#include<iostream>
#include<vector>
#include<algorithm>
#include<time.h>
#include<windows.h>
using namespace std;

template<class T>
class quickSort{
public:
    // 自定义算法
    void sort(vector<T>& v, int left, int right)
    {
        if (left >= right) return;  // 子数组长度为 1 时终止递归

        int mid = partition(v, left, right);  // 获取哨兵位置(划分左右边界的位置)

        sort(v, left, mid - 1);       // 递归排序哨兵左边数组
        sort(v, mid + 1, right);       // 递归排序哨兵右边数组
    }

private:
    // 返回哨兵位置
    int partition(vector<T>& v, int left, int right) {
        // 以 nums[left] 作为基准数
        int i = left, j = right, mid = v[left];
        while (i < j) 
        {
            while (i < j && v[j] >= mid) j--;       // 从右向左找一个小于 mid 的数
            while (i < j && v[i] <= mid) i++;       // 从左向右找一个大于 mid 的数

            swap(v[i], v[j]);                       // 确定大于和小于mid数的位置，交换这两个数
        }
        swap(v[i], v[left]);        // 此时i=j跳出循环,也就是确定了基准的位置, 把基准值放在i位置

        return i;                   // 返回基准的位置
    }

public:
    // 洗牌操作
    void shuffle(vector<T>& v)
    {
        srand((unsigned)time(NULL));        // 随机数种子
        for(int i=0; i<v.size()-1; i++)
        {
            int rand_num = rand() % (v.size()-1 - 0 + 1) + 0; // 
            if(rand_num != i)
                swap(v[i], v[rand_num]);
        }
    }
};



template<class T1>
void printFun(T1 v)
{
    cout << v << "  ";
}

int main()
{   
    vector<int> v;
    // v.push_back(4);
    // v.push_back(2);
    // v.push_back(2);
    // v.push_back(6);
    // v.push_back(1);
    // v.push_back(10);
    for(int i=0; i<10000; i++)
    {
        v.push_back(i);
    }

    long start = GetTickCount();
    // for_each(v.begin(), v.end(), printFun<int>);
    // cout << endl;

    quickSort<int>().shuffle(v);    // 如果是有序数据，打乱再排序 0ms
    quickSort<int>().sort(v, 0, v.size()-1);    // 不打乱 78ms

    long end = GetTickCount();  

    cout << end - start << endl; // 94
    // for_each(v.begin(), v.end(), printFun<int>);
}