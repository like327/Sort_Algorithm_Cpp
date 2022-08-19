#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

template<class T>
class insertSort{
public:

    // 1、交换法插入排序
        // 在新数字插入过程中，不断与前面的数字交换，直到找到自己合适的位置。
    void sort1(vector<T>& v)
    {
        for(int i=1; i<v.size(); i++)
        {
            int j = i;  //记录j当前的数字下标
            // 当前数字比前一个数字小，则将当前数字与前一个数字交换
            while(j>=1 && v[j]<v[j-1])
            {
                swap(v[j], v[j-1]);
                j--;
            }
        }
    }

    // 2、移动插入排序
    // 在交换法插入排序中，每次交换数字时，swap 函数都会进行三次赋值操作。
    // 但实际上，新插入的这个数字并不一定适合与它交换的数字所在的位置。
    // 也就是说，它刚换到新的位置上不久，下一次比较后，如果又需要交换，它马上又会被换到前一个数字的位置。
    // 由此，我们可以想到一种优化方案：让新插入的数字先进行比较，前面比它大的数字不断向后移动，
    // 直到找到适合这个新数字的位置后，新数字只做一次插入操作即可。
    void sort2(vector<T>& v)
    {
        for(int i=1; i<v.size(); i++)
        {
            int cur = v[i];     //保存待插入的变量
            int j = i - 1;
            // 寻找插入位置的过程中，不断地将比 cur 大的数字向后挪
            while(j>=0 && cur<v[j])
            {
                v[j+1] = v[j];
                j--;
            }
        // 两种情况会跳出循环：
            // 1. 遇到一个小于或等于 cur的数字，跳出循环，cur就坐到它后面。
            // 2. 已经走到数列头部，仍然没有遇到小于或等于 cur的数字，也会跳出循环，
            // 此时 j 等于 -1，cur 就坐到数列头部。
            v[j + 1] = cur;
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
    v.push_back(4);
    v.push_back(2);
    v.push_back(2);
    v.push_back(6);
    v.push_back(1);
    
    // insertSort<int>().sort2(v);
    for_each(v.begin(), v.end(), printFun<int>);
}
