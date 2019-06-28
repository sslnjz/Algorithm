//
// Created by 宋斌斌 on 2019-06-28.
//

#ifndef ALGORITHM_ALGORITHM_H
#define ALGORITHM_ALGORITHM_H

#include <vector>

namespace algorithm
{
    namespace sort {

        /*
         * @ Title       : 冒泡排序
         * @ Rational    : 从序列的一端开始往另一端冒泡, 依次比较相邻的两个数的大小
         * @ Complexity  : 时间复杂度 O(N²)， 空间复杂度O(1)
         * @ Description : 维护一个已排好序的序列:[last,𝑁)(N是数组大小),每次冒泡会记录最大的那个泡泡的位置作为last直到last == 1时,
         *                 说明整个序列已经排好。因为冒泡排序中每次冒泡都相当于选最大值放到序列结尾，所以[last,𝑁)不仅是有序的，而且
         *                 位置是正确的。 所以last == 1时,[1,𝑁)已经获得了正确的位置, 那么元素0的位置自然就确定了。
        */
        template <class T>
        static void BubbleSort(T array[], size_t&& size)
        {
            int last = size; //记录最大泡泡的位置
            while(last > 1)
            {
                int end = 0;
                for (int j = 0; j < last - 1; ++j)
                {
                    if(array[j] > array[j + 1])
                    {
                        T temp = array[j];
                        array[j] = array[j + 1];
                        array[j + 1] = temp;

                        end = j + 1;
                    }
                }
                last = end;
            }
        }

        /*
         * @ Title       : 选择排序
         * @ Rational    : 首先，找到数组中最小的元素，取出来，将它和数组的第一个元素交换位置，第二步，在剩下的元素中继续寻找最小的元素，
         *                 取出来，和数组的第二个元素交换位置，如此循环，直到整个数组排序完成。
         * @ Complexity  :
         * @ Description :
         *
         *
         *
         */
        template <class T>
        static void sort(T array[], size_t&& size)
        {
            
        }
    }
}

#endif //ALGORITHM_ALGORITHM_H
