#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> minLheap;  // 小顶堆
    // 小顶堆，堆顶元素是队列中最小值，保存较大部分的数据
    priority_queue<int, vector<int>, less<int>> maxRheap;    // 大顶堆
    // 大顶堆，堆顶元素是队列中的最大值，保存较小部分的数据
    // 小顶堆 -------->顶       顶--------->  大顶堆
    // 优先插入左堆，保证左堆元素m与右堆元素满足： m=n+1 或者 m=n

    MedianFinder() {}
    
    void addNum(int num) 
    {
        // 左右堆 队列元素相等，最终要插入到左堆（小顶堆）
        // 先插入右（大顶堆）,将大顶堆的堆顶元素出堆插入左堆（小顶堆）
        if(minLheap.size() == maxRheap.size()) 
        {
            maxRheap.push(num);
            minLheap.push(maxRheap.top());
            maxRheap.pop();
        }
        else{ // 先插入左边，再把左边的堆顶元素拿出来插入到右堆
            minLheap.push(num);
            maxRheap.push(minLheap.top());
            minLheap.pop();
        }
    }
    
    double findMedian() 
    {
        if(minLheap.size() == maxRheap.size())
            return (minLheap.top() + maxRheap.top()) / 2.0;
        else
            return minLheap.top();
    }

};


int main()
{
    priority_queue<int, vector<int>, less<int>> maxheadp;   // 大顶堆，降序
    maxheadp.push(10);
    maxheadp.push(1);
    maxheadp.push(2);
    maxheadp.push(1);
    maxheadp.push(8);
    maxheadp.push(22);
    while(!maxheadp.empty())
    {
        cout << maxheadp.top() << "  ";
        maxheadp.pop();
    }
    return 0;
}


class Merge {

    // 用于辅助合并有序数组
    private static int[] temp;

    public static void sort(int[] nums) {
        // 先给辅助数组开辟内存空间
        temp = new int[nums.length];
        // 排序整个数组（原地修改）
        sort(nums, 0, nums.length - 1);
    }

    // 定义：将子数组 nums[lo..hi] 进行排序
    private static void sort(int[] nums, int lo, int hi) {
        if (lo == hi) {
            // 单个元素不用排序
            return;
        }
        // 这样写是为了防止溢出，效果等同于 (hi + lo) / 2
        int mid = lo + (hi - lo) / 2;
        // 先对左半部分数组 nums[lo..mid] 排序
        sort(nums, lo, mid);
        // 再对右半部分数组 nums[mid+1..hi] 排序
        sort(nums, mid + 1, hi);
        // 将两部分有序数组合并成一个有序数组
        merge(nums, lo, mid, hi);
    }

    // 将 nums[lo..mid] 和 nums[mid+1..hi] 这两个有序数组合并成一个有序数组
    private static void merge(int[] nums, int lo, int mid, int hi) {
        // 先把 nums[lo..hi] 复制到辅助数组中
        // 以便合并后的结果能够直接存入 nums
        for (int i = lo; i <= hi; i++) {
            temp[i] = nums[i];
        }

        // 数组双指针技巧，合并两个有序数组
        int i = lo, j = mid + 1;
        for (int p = lo; p <= hi; p++) {
            if (i == mid + 1) {
                // 左半边数组已全部被合并
                nums[p] = temp[j++];
            } else if (j == hi + 1) {
                // 右半边数组已全部被合并
                nums[p] = temp[i++];
            } else if (temp[i] > temp[j]) {
                nums[p] = temp[j++];
            } else {
                nums[p] = temp[i++];
            }
        }
    }
}