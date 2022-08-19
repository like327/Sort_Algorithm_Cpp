#include<iostream>
#include<vector>
using namespace std;

template<class T>
class bubbleSort{
public:
    //一边比较一边向后两两交换，将最大值 / 最小值冒泡到最后一位
    void sort1(vector<T>& v)
    {
        for(int i=0; i<v.size()-1; i++)
        {
            for(int j=0; j<v.size()-1-i; j++)
            {
                // 如果左边的数大于右边的数，则交换，保证右边的数字最大
                if(v[j] > v[j+1])
                    swap(v[j], v[j+1]);
            }
        }
    }
    // 经过优化的写法：使用一个变量记录当前轮次的比较是否发生过交换，
    // 如果没有发生交换表示已经有序，不再继续排序；
    void sort2(vector<T>& v)
    {
        bool flag = true;

        for(int i=0; i<v.size()-1; i++)
        {
            // 如果没有发生过交换，说明剩余部分已经有序，排序完成
            if(!flag) break;
            // 设置 flag 为 false，如果发生交换，则将其置为 true
            flag = false;
            for(int j=0; j<v.size()-1-i; j++)
            {
                if(v[j] > v[j+1])
                {
                    swap(v[j], v[j+1]);
                    flag = true;
                }
            }
        }
    }
};


template<class T1>
void printFun(vector<T1>& v)
{
    for(int i=0; i<v.size(); i++)
    {
        cout << v[i] << "  ";
    }
    cout << endl;
}

// 无需临时变量的两数交换
void swap(vector<int>& v, int i, int j)
{
    v[i] = v[i] ^ v[j];
    v[j] = v[j] ^ v[i];
    v[i] = v[i] ^ v[j];
}

int main()
{
    vector<int> v;
    v.push_back(4);
    v.push_back(2);
    v.push_back(6);
    v.push_back(1);

    bubbleSort<int>().sort1(v);
    printFun<int>(v);

    bubbleSort<int>().sort2(v);
    printFun<int>(v);
}