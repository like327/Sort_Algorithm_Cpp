#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

// 将两个有序数组合并为一个有序数组
// 1 5 10      3 4 7 12 13
template<class T>
vector<T> merge(vector<T> v1, vector<T> v2)
{
    vector<T> res(v1.size() + v2.size());   // 初始化合并数组
    int index1 = 0, index2 = 0;
    while(index1 < v1.size() && index2 < v2.size()) // 将共同长度的元素插入到结果数组中
    {
        if(v1[index1] <= v2[index2])
            res[index1 + index2] = v1[index1++];
        else
            res[index1 + index2] = v2[index2++];
    }

    while(index1 < v1.size())       // 将v1剩余的元素插入（满足的时候一定是v2都插入了）
    {
        res[index1 + index2] = v1[index1++];
    }
       
    while(index2 < v2.size())       // 将v2剩余的元素插入（满足的时候一定是v1都插入了）
    {
        res[index1 + index2] = v2[index2++];
    }

    return res;
}

template<class T>
class mergeSort {
public:
    vector<T> tmp;  // 保存排好序的数组

    vector<T> sort(vector<T>& v) 
    {
        tmp.resize(v.size(), 0);
        sortRange(v, 0, v.size() - 1);
        // 如果需要返回原来的数组，直接调用swap函数，交换v和tmp的数据
        // swap(v, tmp);
        return v;
    }

    void sortRange(vector<T>& v, int left, int right) 
    {
        if (left >= right) return;
        int mid = (left + right) >> 1;
        sortRange(v, left, mid);        // 排序左区间
        sortRange(v, mid + 1, right);   // 排序右区间

        merge(v, left, mid, right);
    }

    void merge(vector<T>& v, int left, int mid, int right)
    {
        // 合并2个排好序的数组 v[left, mid] 和 v[mid+1, right]
        int index_tmp = 0;
        int index1 = left, index2 = mid+1;  // 排好序的数组v的2个区间的起始值为 index1 和 index2 
        while(index1 <= mid && index2 <= right)
        {
            if(v[index1] <= v[index2])
                tmp[index_tmp++] = v[index1++];
            else
                tmp[index_tmp++] = v[index2++];
        }

        while(index1 <= mid)
        {
            tmp[index_tmp++] = v[index1++];
        }
        while(index2 <= right)
        {
            tmp[index_tmp++] = v[index2++];
        }

        for(int i=0; i<right-left+1; i++)
            v[i+left] = tmp[i];
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
    v.push_back(10);

    mergeSort<int>().sort(v);
    for_each(v.begin(), v.end(), [](int v){cout << v << " ";});
    // for_each(v.begin(), v.end(), printFun<int>);
    return 0;
}

