#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

template<class T>
class shellSort{
public:
    void sort(vector<T>& v)
    {
        // 增量序列
        for(int gap = v.size() / 2; gap > 0; gap /= 2)
        {
            // 分组
            for(int groupStartIndex = 0; groupStartIndex < gap; groupStartIndex++)
            {
                for(int currentIndex = groupStartIndex + gap; currentIndex < v.size(); currentIndex += gap)
                {
                    int currentNumber = v[currentIndex];
                    int preIndex = currentIndex - gap;
                    while (preIndex >= groupStartIndex && currentNumber < v[preIndex]) 
                    {
                        // 向后挪位置
                        v[preIndex + gap] = v[preIndex];
                        preIndex -= gap;
                    }
                    // currentNumber 找到了自己的位置
                    v[preIndex + gap] = currentNumber;
                }
            }
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
    
    shellSort<int>().sort(v);
    for_each(v.begin(), v.end(), printFun<int>);
}
