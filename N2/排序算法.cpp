#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) 
    {
        // BubbleSort(nums);
        // SelectSort(nums);
        QuickSort(nums, 0, nums.size()-1);
        return nums;
    }
private:
    //1、冒泡排序
    void BubbleSort(vector<int>& nums)
    {
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            bool swap_flag = false;  
            for(int j=0; j<n-i-1; j++)
            {
                if(nums[j] > nums[j+1])
                {
                    swap(nums[j+1], nums[j]);
                    swap_flag = true;
                }
                    
            }
            if(!swap_flag)
                break;
        }
    }
    //2、选择排序
    void SelectSort(vector<int>& nums)
    {
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            int minIndex = i;
            for(int j=i+1; j<n; j++)    // 找到最小值下标
            {
                if(nums[j] < nums[minIndex])
                    minIndex = j;
            }
            swap(nums[minIndex], nums[i]);
        }
    }
    //3、快速排序
    void QuickSort(vector<int>& nums, int low, int high)
    {
        /**
        1、挑选基准值：从数列中挑出一个元素，称为“基准”（pivot）；
        2、分割（partition）：重新排序数列，所有比基准值小的元素摆放在基准前面，
        所有比基准值大的元素摆在基准后面（与基准值相等的数可以到任何一边）。在这个分割结束之后，对基准值的排序就已经完成；
        3、递归排序子序列：递归地将小于基准值元素的子序列和大于基准值元素的子序列排序。
        */

        if(low >= high)             // 递归结束
            return;  
        
        int pivot = nums[low];  // 选择最左侧的元素作为分割点
        int left = low, right = high;   // 

        while(left < right)
        {
            while(left<right && nums[right] >= pivot)   
                    right--;            // 找到右边第一个小于pivot的元素
            nums[left] = nums[right];   // 并将其移动到left处                 
            while(left<right && nums[left] <= pivot)    
                left++;                 // 找到左边第一个大于pivot的元素
            nums[right] = nums[left];   // 并将其移动到right处                   
        }
        nums[left] = pivot;             // pivot放置到中间left=right处                     
        int pivotIndex = left;

        QuickSort(nums, low, pivotIndex-1);   // 递归对mid两侧元素进行排序               
        QuickSort(nums, pivotIndex+1, high);
    }
    //4、插入排序
    //5、希尔排序
    //6、堆排序
    //7、归并排序

};

int main()
{
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(10);
    nums.push_back(3);
    nums.push_back(5);
    nums.push_back(1);

    Solution().sortArray(nums);
    for(int num : nums)
        cout << num << "   ";
    cout << endl;
}
