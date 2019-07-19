//
// Created by ssln on 2019-06-28.
//

#ifndef ALGORITHM_ALGORITHM_H
#define ALGORITHM_ALGORITHM_H

#include <vector>
#include <functional>

#define ARRAY_SIZE(array) ( sizeof(array) / sizeof(array[0]) )

namespace algorithm::sort {

    template<class T>
    [[deprecated("Only used for debug, may deleted at next version")]]
    void print_array(T &array) {
        for (int i = 0; i < ARRAY_SIZE(array); ++i) {
            std::cout << array[i] <<  ((i == ARRAY_SIZE(array) - 1) ? "\n" : ",");
        }
    }

    /*
     * @ Title       : 冒泡排序
     * @ Rational    : 从序列的一端开始往另一端冒泡, 依次比较相邻的两个数的大小
     * @ Complexity  : 时间复杂度 O(N²)， 空间复杂度O(1)
     *                 最好的时间复杂度为O(N), 最大比较次数 n(n-1)/2, 最大交换次数 3n(n-1)/2.
     * @ Description : 维护一个已排好序的序列:[last,𝑁)(N是数组大小),每次冒泡会记录最大的那个泡泡的位置作为last直到last == 1时,
     *                 说明整个序列已经排好。因为冒泡排序中每次冒泡都相当于选最大值放到序列结尾，所以[last,𝑁)不仅是有序的，而且
     *                 位置是正确的。 所以last == 1时,[1,𝑁)已经获得了正确的位置, 那么元素0的位置自然就确定了。
     * @ Stability   : 冒泡排序就是把小的元素往前调或者把大的元素往后调。比较是相邻的两个元素比较，交换也发生在这两个元素之间。所以，
     *                 如果两个元素相等，是不会再交换的；如果两个相等的元素没有相邻，那么即使通过前面的两两交换把两个相邻起来，这时
     *                 候也不会交换，所以相同元素的前后顺序并没有改变，所以冒泡排序是一种稳定排序算法
    */
    template <class T>
    static void bubble_sort(T& array)
    {
        size_t size = ARRAY_SIZE(array);
        int last = size; //记录最大泡泡的位置
        while(last > 1)
        {
            int end = 0;
            for (int i = 0; i < last - 1; ++i)
            {
                if(array[i] > array[i + 1])
                {
                    std::swap(array[i], array[i + 1]);
                    end = i + 1;
                }
            }
            last = end;
        }
    }

    /*
     * @ Title       : 选择排序
     * @ Rational    : 首先，找到数组中最小的元素，取出来，将它和数组的第一个元素交换位置，第二步，在剩下的元素中继续寻找最小的元素，
     *                 取出来，和数组的第二个元素交换位置，如此循环，直到整个数组排序完成。
     * @ Complexity  : 时间复杂度 O(N²)， 空间复杂度O(1)
     *                 选择排序的交换操作介于0和（n - 1）次之间。选择排序的比较操作为 n(n - 1)/2 次之间。选择排序的赋值操作介于
     *                 0 和 3(n - 1）次之间
     * @ Description : 对比数组中前一个元素跟后一个元素的大小，如果后面的元素比前面的元素小则用一个变量k来记住他的位置，接着第二次
     *                 比较，前面“后一个元素”现变成了“前一个元素”，继续跟他的“后一个元素”进行比较如果后面的元素比他要小则用变量k记
     *                 住它在数组中的位置(下标)，等到循环结束的时候，我们应该找到了最小的那个数的下标了，然后进行判断，如果这个元素
     *                 的下标不是第一个元素的下标，就让第一个元素跟他交换一下值，这样就找到整个数组中最小的数了。然后找到数组中第二
     *                 小的数，让他跟数组中第二个元素交换一下值，以此类推
     * @ Stability   : 选择排序是给每个位置选择当前元素最小的，比如给第一个位置选择最小的，在剩余元素里面给第二个元素选择第二小的，
     *                 依次类推，直到第n-1个元素，第n个元素不用选择了，因为只剩下它一个最大的元素了。那么，在一趟选择，如果一个元
     *                 素比当前元素小，而该小的元素又出现在一个和当前元素相等的元素后面，那么交换后稳定性就被破坏了。比较拗口，举个
     *                 例子，序列5 8 5 2 9，我们知道第一遍选择第1个元素5会和2交换，那么原序列中两个5的相对前后顺序就被破坏了，所
     *                 以选择排序是一个不稳定的排序算法。
     */
    template <class T>
    static void selection_sort(T& array)
    {
        size_t size = ARRAY_SIZE(array);
        for (int i = 0; i < size - 1; ++i)
        {
            int min = i;
            for (int j = i + 1; j < size; ++j) {
                if(array[min] > array[j]){
                    min = j;
                }
            }
            if( min != i){ //避免不必要的交换
                std::swap(array[i], array[min]);
            }

        }
    }


    /*
     * @ Title       : 插入排序
     * @ Rational    : 将无序数列的第一个元素与有序数列的元素从后往前逐个进行比较，找出插入位置，将该元素插入到有序数列的合适位置中。
     * @ Complexity  : 时间复杂度 O(N²)， 空间复杂度O(1)
     * @ Description : 每次处理就是将无序数列的第一个元素与有序数列的元素从后往前逐个进行比较，找出插入位置，将该元素插入到有序数列
     *                 的合适位置中。假设在一个无序的数组中，要将该数组中的数按插入排序的方法从小到大排序。假设a[]={3,5,2,1,4};
     *                 插入排序的思想就是比大小，满足条件交换位置，一开始会像冒泡排序一样，但会比冒泡多一步就是交换后（a[i]=a[i+1]）
     *                 原位置（a[i]）会继续和前面的数比较满足条件交换，直到a[i+1]前面的数组是有序的。比如在第二次比较后数组变成
     *                 a[]={2,3,5,1,4};
     * @ Stability   : 插入排序是在一个已经有序的小序列的基础上，一次插入一个元素。当然，刚开始这个有序的小序列只有1个元素，就是第
     *                 一个元素。比较是从有序序列的末尾开始，也就是想要插入的元素和已经有序的最大者开始比起，如果比它大则直接插入在
     *                 其后面，否则一直往前找直到找到它该插入的位置。如果碰见一个和插入元素相等的，那么插入元素把想插入的元素放在相
     *                 等元素的后面。所以，相等元素的前后顺序没有改变，从原无序序列出去的顺序就是排好序后的顺序，所以插入排序是稳定的。
     */
    template <class T>
    static void insert_sort(T& array)
    {
        size_t size = ARRAY_SIZE(array);
        T temp = NULL;
        int j = 0;
        for (int i = 1; i < size; ++i) {
            temp = array[i];
            for (j = i; j > 0 && array[j-1]>temp; --j) {
                array[j] = array[j - 1];
            }
            array[j] = temp;
        }
    }

    /*
     * @ Title       : 希尔排序
     * @ Rational    : 希尔排序基于插入排序的以下两点性质进行改进：
     *                   1.插入排序在对几乎已经排好序的数据操作时，效率高，即可以达到线性排序的效率
     *                   2.插入排序一般来说是低效的，因为插入排序每次只能将数据移动一位
     * @ Complexity  : 时间复杂度依赖于步长的选择, 一般位于：O(nlog²n) ~ O(n^3/2) ~ O(n²)
     * @ Description : 希尔排序，也称递减增量排序算法，是插入排序的一种更高效的改进版本
     * @ Stability   : 由于多次插入排序，我们知道一次插入排序是稳定的，不会改变相同元 素的相对顺序，但在不同的插入排序过程中，相同
     *                 的元素可能在各自的插入排序中移动，最后其稳定性就会被打乱
     */
    template <class T>
    static void shell_sort(T& array)
    {
        size_t size = ARRAY_SIZE(array);
        size_t _step = 1;
        while(_step < size / 3)
            _step = _step * 3 + 1; //步长的选取最优解无定论，一般选择在 1/2 到 1/3 附近

        while(_step >= 1)
        {
            for (int i = _step; i < size; ++i) {
                for (int j = i; j >= _step && array[j] < array[j - _step] ; j -= _step) {
                    std::swap(array[j], array[j - _step]);
                }
            }
            _step = _step / 3;
        }
    }

    /*
     * @ Title       : 快速排序
     * @ Rational    : 快速排序使用分治法策略来把一个序列分为较小和较大的2个子序列，然后递归地排序两个子序列
     * @ Complexity  : 快速排序的时间复杂度是 O(nlogn)，极端情况下会退化成 O(n²), 空间复杂度 O(logn)
     * @ Description : 快排算法步骤为：
     *                   1. 挑选基准值：从数列中挑出一个元素，称为“基准”。
     *                   2. 重新排序数列，所有比基准值小的元素摆放在基准前面，所有比基准值大的元素摆在基准后面（与基准值相等的数可
     *                      以到任何一边）。在这个分割结束之后，对基准值的排序就已经完成
     *                   3. 递归排序子序列：递归地将小于基准值元素的子序列和大于基准值元素的子序列排序。递归到最底部的判断条件是数
     *                      列的大小是零或一，此时该数列显然已经有序。
     * @ Stability   : 在对基准元素交换时，会打乱数组的稳定性，所以快速排序为不稳定的排序算法
     */
    template <class T>
    static void quick_sort(T& array)
    {
        size_t size = ARRAY_SIZE(array);
        //lambda 递归调用
        std::function<void (T&, int&&, int&&)> quick_sort_recursive;
        quick_sort_recursive = [&](T& _array, int&& _start, int&& _end) ->void
        {
            if(_start >= _end) return;

            auto mid = _array[_end]; //选取基准元素
            int left = _start, right = _end - 1;
            while(left < right)
            {
                while(_array[left] < mid && left < right) //试图在左侧找到一个比基准元更大的元素
                    ++left;
                while(_array[right] >= mid && left < right) //试图在右侧找到一个比基准元更小的元素
                    --right;
                std::swap(_array[left], _array[right]); //交换元素
            }

            //当前left以前的元素都小于基准元素，left以后的都大于基准元素，如果left位置的值大于基准，则将基准交换至left位置。
            if (_array[left] >= _array[_end])
                std::swap(_array[left], _array[_end]);
            else
                ++left;
            //这里_start和_end在被使用之后不会再使用，所以使用std::move使其转换成右值，避免不必要的拷贝，增加内存消耗
            quick_sort_recursive(_array, std::move(_start), left - 1);
            quick_sort_recursive(_array, left + 1, std::move(_end));
        };

        quick_sort_recursive( array, 0, size - 1 );
    }


    /*
     * @ Title       : 堆排序
     * @ Rational    : 堆排序是指利用堆数据结构所设计的一种排序算法。堆是一个近似完全二叉树的结构，并同时满足堆积的性质：即子节点的
     *                 键值或索引总是小于（或者大于）它的父节点
     * @ Complexity  : 时间复杂度O(nlogn), 空间复杂度O(1)
     * @ Description : 在堆的数据结构中，堆中的最大值总是位于根节点（在优先队列中使用堆的话堆中的最小值位于根节点）。堆中定义以下几种操作：
     *                   1. 最大堆调整（Max Heapify）：将堆的末端子节点作调整，使得子节点永远小于父节点
     *                   2. 创建最大堆（Build Max Heap）：将堆中的所有数据重新排序
     *                   3. 堆排序（HeapSort）：移除位在第一个数据的根节点，并做最大堆调整的递归运算
     * @ Stability   : 在一个长为n的序列，堆排序的过程是从第n/2开始和其子节点共3个值选择最大(大顶堆)或者最小(小顶堆),这3个元素之间
     *                 选择当然不会破坏稳定性。但当为n/2-1,n/2-2, …1这些个父节点选择元素时，就会破坏稳定性。有可能第n/2个的父节点
     *                 交换把后面一个元素交换过去了，而第n/2-1个父节点把后面一个相同的元素没 有交换，那么这2个相同的元素之间的稳定
     *                 性被破坏
     */
    template <class T>
    static void heap_sort(T& array)
    {
        size_t size = ARRAY_SIZE(array);

        std::function<void (T&, int&&, int&&)> heapify;
        heapify = [](T& array, int&& _start, int&& _end) ->void {
            int _dad = _start;
            int _son =_dad * 2 + 1;
            while(_son <= _end)
            {
                if(_son + 1 <= _end && array[_son] < array[_son + 1])
                    ++_son;

                if(array[_dad] > array[_son])
                    return;
                else
                {
                    std::swap(array[_dad], array[_son]);
                    _dad = _son;
                    _son = _dad * 2 + 1;
                }

            }
        };

        for (int i = size / 2 - 1; i >= 0; --i)
            heapify(array, i, size - 1);

        for (int i = size - 1; i > 0; --i)
        {
            std::swap(array[0], array[i]);
            heapify(array, 0, i - 1);
        }
    }

    /*
     * @ Title       : 归并排序
     * @ Rational    : 采用分治法：
     *                   分割：递归地把当前序列平均分割成两半。
     *                   集成：在保持元素顺序的同时将上一步得到的子序列集成到一起（归并）
     * @ Complexity  : 时间复杂度O(n log n)
     * @ Description : 1. 将序列每相邻两个数字进行归并操作，形成 ceil(n/2)个序列，排序后每个序列包含两/一个元素
     *                 2. 若此时序列数不是1个则将上述序列再次归并，形成 ceil(n/4)个序列，每个序列包含四/三个元素
     *                 3. 重复步骤2，直到所有元素排序完毕，即序列数为1
     * @ Stability   : 合并过程中我们可以保证如果两个当前元素相等时，我们把处在前面的序列的元素保存在结 果序列的前面，这样就保证了稳定性；
     */

    template <class T>
    static void merge_sort(T& array){

        const size_t size = ARRAY_SIZE(array);

        std::function<void (T&, T&, int, int)> merge_sort_recursive;
        merge_sort_recursive = [&](T& array, T& reg, int start, int end){
            if(start >= end) return;

            int len = end - start;
            int mid = (len >> 1) + start;
            int start1 = start, end1 = mid;
            int start2 = mid + 1, end2 = end;
            merge_sort_recursive(array, reg, start1, end1);
            merge_sort_recursive(array, reg, start2, end2);

            int t = start;
            while(start1 <= end1 && start2 <= end2)
                reg[t++] = array[start1] < array[start2] ? array[start1++] : array[start2++];
            while (start1 <= end1)
                reg[t++] = array[start1++];
            while(start2 <= end2)
                reg[t++] = array[start2++];

            for (t = start; t <= end; ++t) {
                array[t] = reg[t];
            }
        };

        T reg[size];
        merge_sort_recursive(array, (T&) reg, 0, size - 1);
    }
}

#endif //ALGORITHM_ALGORITHM_H
