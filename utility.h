//
// Created by ssln on 2019-12-02.
//

#ifndef UTILITY_H
#define UTILITY_H

#include <string>

namespace algorithm::utility
{
   typedef int int32;
   typedef unsigned int uint32;

   typedef long long int64;
   typedef unsigned long long uint64;


   static std::string uint2string(const uint32 value)
   {
      static const char zero = '0';
      static const char one = '1';
      static const char* avoid_logic[2] = { &zero, &one };
      char retval[40] = {0};
      int i = 31, j = 0;

      for (; i >= 0; )
      {
         retval[j] = *(avoid_logic[(value & (1 << i)) >> i]); // no comparisons, very fast
         --i;
         ++j;
         retval[j] = *(avoid_logic[(value & (1 << i)) >> i]);
         --i;
         ++j;
         retval[j] = *(avoid_logic[(value & (1 << i)) >> i]);
         --i;
         ++j;
         retval[j] = *(avoid_logic[(value & (1 << i)) >> i]);
         --i;
         ++j;
         retval[j] = ' ';
         ++j;
      }
      retval[j - 1] = 0;
      return retval;
   }

   static bool getbitsuint(const uint32 startbit, const uint32 numbits, const uint32 src, uint32& value)
   {
      uint32 base = (startbit + numbits - 1);
      if (startbit < 1 || numbits < 1 || base>32) return false;

      const uint64& one = 1;
      const uint64& a = (one << base);
      const uint64& b = (one << (startbit - 1));
      const uint32& mask = static_cast<uint32>(a - b);

      value = ((src & mask) >> (startbit - 1));

      return true;
   }

   static bool setbits2c(const uint32 startbit, const uint32 numbits, const int64 scaledValue, uint32& src)
   {
      uint32 base = (startbit + numbits - 1);

      // error if specified bit field is invalid
      if (startbit < 1 || numbits < 1 || base > 32) return false;

      const uint64& one = 1;
      const uint64& a = (one << (numbits - 1));

      // error if scaled value cannot fit in bits
      const uint64& probe = (one << numbits);
      if (scaledValue >= probe) return false;

      uint32 tmp = src;

      // mask: numBits bits starting at startBit are set
      const uint64& b = (one << base);
      const uint64& c = (one << (startbit - 1));
      const uint32& mask = static_cast<uint32>(b - c);

      // Clear specified bits in word
      tmp &= ~mask;

      // move scaled value to start at bit startBit and set all bits
      // outside of bit field to zero. Then add bit field to word
      tmp |= (scaledValue << (startbit - 1) & mask);

      src = tmp;

      return true;
   }

}

#endif //UTILITY_H