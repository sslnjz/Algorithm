#include <iostream>
#include "algorithm.h"


int main() {

    float array[] = {3.01, 2.08, 1, 6, 8, 4, 7, 10, 5, 9, 15, 33, 1088, 244, 98, 77, 66};


//    {
//        int last = 10;
//        while(last > 1)
//        {
//            int end = 0;
//            for (int i = 0; i < last - 1; ++i) {
//                if(array[i] > array[i+1])
//                {
//                    std::swap(array[i], array[i+1]);
//                    end = i + 1;
//                }
//            }
//
//            last = end;
//        }
//    }

//    {
//        for (int i = 0; i < 10; ++i) {
//            for (int j = i+1; j < 10; ++j) {
//                if(array[i] > array[j])
//                {
//                    std::swap(array[i], array[j]);
//                }
//            }
//        }
//    }


//    {
//        int last = 10;
//        while(last > 1 )
//        {
//            int end = 0;
//            for (int i = 0; i < last - 1; ++i)
//            {
//                if(array[i] > array[i+1])
//                {
//                    std::swap(array[i], array[i+1]);
//                    end = i + 1;
//                }
//            }
//
//            last = end;
//        }
//    }

//    {
//        for (int i = 0; i < 10; ++i) {
//            for (int j = i + 1; j < 10; ++j) {
//                if(array[i] > array[j])
//                {
//                    std::swap(array[i], array[j]);
//                }
//            }
//        }
//    }



//    {
//        for (int i = 0; i < 10; ++i) {
//            int min = i;
//            for (int j = i + 1; j < 10; ++j) {
//                if(array[i] > array[j])
//                    min = j;
//            }
//
//            if(min != i)
//                std::swap(array[i], array[min]);
//        }
//    }


//    {
//        int temp = 0;
//        int j = 0;
//        for (int i = 0; i < 10; ++i) {
//            temp = array[i];
//
//            for ( j = i; j > 0 && array[j - 1] > temp ; --j) {
//                array[j] = array[j - 1];
//            }
//            array[j] = temp;
//        }
//    }

//    {
//        int step = 1;
//        while( step < 10 / 3 )
//        {
//            step = step * 3 + 1;
//        }
//
//        while(step >= 1){
//            for (int i = step; i < 10; ++i) {
//                for (int j = i; j >= step && array[j] < array[j - step]; j -= step) {
//                    std::swap(array[j], array[j - step]);
//                }
//            }
//            step = step / 3;
//        }

//    }

    algorithm::sort::print_array(array);

    algorithm::sort::merge_sort(array);

    algorithm::sort::print_array(array);

    int32_t x = 8;

    std::string s = std::bitset< std::numeric_limits<int32_t>::digits >(x).to_string();

    std::cout << s << std::endl;

    return 0;
}