#include<iostream>
#include<vector>
using namespace std;

template<class T>
class selectSort{
public:

    void sort1(vector<T>& v)
    {
        int min_index;
        for(int i=0; i<v.size()-1; i++) // 最后一轮一定是已经有序了, 所以v.size()-1
        {
            min_index = i;                      //保留最小值所在的下标
            for(int j=i+1; j<v.size(); j++)     // 找到最小值下标
            {
                if(v[min_index] < v[j])
                    min_index = j;
            }
            swap(v[i], v[min_index]);           // 完成一轮，交换一次
        }
    }

    // 二元选择排序
    void sort2(vector<T>& v)
    {
        int min_index, max_index;       // 记录每轮遍历最小值和最大值的下标
        for(int i=0; i<v.size()/2; i++)   // 只需要遍历一半
        {
            min_index = i;
            max_index = i;
            for(int j=i+1; j<v.size()-i; j++)   //这里的范围要注意; 
            {
                if(v[min_index] > v[j])
                    min_index = j;
                if(v[max_index] < v[j])
                    max_index = j;
            }

            // 如果 minIndex 和 maxIndex 都相等，那么他们必定都等于 i，
            // 且后面的所有数字都与 v[i] 相等，此时已经排序完成
            if (min_index == max_index) break;
            swap(v[i], v[min_index]);               //  最小元素交换到首位
            // 如果最大值的下标刚好是 i，由于 v[i] 和 v[minIndex] 已经交换了，
            // 所以这里要更新 maxIndex 的值。
            if (max_index == i) 
                max_index = min_index;
            swap(v[v.size()-1-i], v[max_index]);    // 最大元素交换到末尾
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

int main()
{
    vector<int> v;
    v.push_back(4);
    v.push_back(2);
    v.push_back(2);
    v.push_back(6);
    v.push_back(1);

    selectSort<int>().sort1(v);
    printFun<int>(v);
}
