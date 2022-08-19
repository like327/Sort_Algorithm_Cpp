
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

template<class T>
class heapSort{
public:
    // 自定义算法
    void sort(vector<T>& v)
    {
        // 构建初始大顶堆
        buildMaxHeap(v);
        for(int i = v.size()-1; i > 0; i--) 
        {
            // 将最大值(堆顶)交换到数组最后
            swap(v[0], v[i]);
            // 调整剩余数组，使其满足大顶堆
            maxHeapAdjust(v, 0, i);
        }
    }

    // 使用STL提供的算法
    void sort_STL(vector<T>& v)
    {
        make_heap(v.begin(), v.end());
        sort_heap(v.begin(), v.end());
    }

private:
    // 构建初始大顶堆
    void buildMaxHeap(vector<T>& v)
    {
        // 从最后一个非叶子结点（最后一个叶子节点的父节点）开始调整大顶堆，
        // 最后一个非叶子结点的下标就是 v.size() / 2 - 1
        for (int i = v.size() / 2 - 1; i >= 0; i--) 
            maxHeapAdjust(v, i, v.size());
    }

    // 调整大顶堆，第三个参数表示剩余未排序的数字的数量，也就是剩余堆的大小
    void maxHeapAdjust(vector<T>& v, int i, int heapSize)
    {
        int left = 2 * i + 1;       // 左子结点下标
        int right = left + 1;       // 右子结点下标
        int largest = i;            // 记录根结点、左子树结点、右子树结点三者中的最大值下标
        
        // 与左子树结点比较
        if (left < heapSize && v[left] > v[largest]) 
            largest = left;
        
        // 与右子树结点比较
        if (right < heapSize && v[right] > v[largest]) 
            largest = right;
        
        if (largest != i)   // 说明该i节点的左右子树的节点值比i节点值大，要交换
        {  
            swap(v[i], v[largest]);                 // 将最大值交换为根结点
            maxHeapAdjust(v, largest, heapSize);    // 再次调整交换数字后的大顶堆
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
    v.push_back(10);


    heapSort<int>().sort(v);
    for_each(v.begin(), v.end(), printFun<int>);
}

