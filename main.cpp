#include <iostream>
#include "algorithm.h"
#include "utility.h"
#include "list.h"

int main() {

   //int array[] = {2, 7, 4, 4, 1, 3, 8, 7, 10, 3};

   //algorithm::sort::merge_sort(array);
   //algorithm::sort::print_array(array);
   //std::cout << std::endl;
//   std::cout << algorithm::utility::uint2string(33) << std::endl;
//
//   algorithm::utility::uint32 value = 33;
//   std::cout << algorithm::utility::uint2string(33) << std::endl;
//
//   algorithm::utility::setbits2c(5, 3, 4, value);
//   std::cout << algorithm::utility::uint2string(value) << std::endl;

    algorithm::list<int> list;
    list.append(6);
    list.append(7);
    list.append(8);

    list.push(4);
    list.push(3);
    list.print();

    list.pop();

    list.print();

   return 0;
}