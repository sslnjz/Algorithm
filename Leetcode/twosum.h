#ifndef TWOSUM_H
#define TWOSUM_H

#include <vector>
#include <unordered_map>

namespace leetcode::easy::twosum
{
	class Solution
	{
	public:
		// @solution:             Brute Force
		// @brief:                The brute force approach is simple. Loop through each element x and find if there is another value 
		//                        that equals to target - x.
		// @Complexity Analysis:
		//                        # Time complexity : O(n^2). For each element, we try to find its complement by looping through the
		//                          rest of array which takes O(n) time. Therefore, the time complexity is O(n^2).
		//                        # Space complexity: O(1).
		static std::vector<int> two_sum_brute_force(std::vector<int>& nums, int target) 
		{
			for (int i = 0; i < nums.size(); ++i)
			{
				for (int j = 1; j < nums.size(); ++j)
				{
					if (nums[j] = target - nums[i])
					{
						return std::vector<int>({i, j});
					}
				}
			}
         return {};
		}

		//@solution:              Two Pass Hash
		//@brief:                 To improve our run time complexity, we need a more efficient way to check if the complement exists in
		//                        the array. If the complement exists, we need to look up its index. What is the best way to maintain a 
		//                        mapping of each element in the array to its index? A hash table.
		//                        We reduce the look up time from O(n) to O(1) by trading space for speed. A hash table is built exactly
		//                        for this purpose, it supports fast look up in near constant time. I say "near" because if a collision
		//                        occurred, a look up could degenerate to O(n)O(n) time. But look up in hash table should be amortized 
		//                        O(1) time as long as the hash function was chosen carefully.
		//                        A simple implementation uses two iterations. In the first iteration, we add each element's value and 
		//                        its index to the table. Then, in the second iteration we check if each element's complement (target - 
		//                        nums[i]) exists in the table. Beware that the complement must not be nums[i] itse lf!
		//@Complexity Analysis:
		//                        # Time complexity : O(n). We traverse the list containing nn elements exactly twice. Since the hash 
		//                          table reduces the look up time to O(1), the time complexity is O(n).
		//                        # Space complexity : O(n). The extra space required depends on the number of items stored in the hash 
		//                          table, which stores exactly n elements.
		static std::vector<int> two_sum_two_pass_hash(std::vector<int>& nums, int target)
		{
			std::unordered_map<int, int> h;
			for (int i = 0; i < nums.size(); ++i)
			{
				h[nums[i]] = i;
			}

			for (int i = 0; i < nums.size(); ++i)
			{
				if (h.find(target - nums[i]) != h.end())
				{
					return std::vector<int>({ i, h[target - nums[i]] });
				}
			}

			return std::vector<int>({ 0, 0 });
		}

		//@solution:              One Pass Hash
		//@brief:                 It turns out we can do it in one-pass. While we iterate and inserting elements into the table, we also look
		//                        back to check if current element's complement already exists in the table. If it exists, we have found a 
		//                        solution and return immediately.                                 
		//@Complexity Analysis:
		//                        # Time complexity : O(n). We traverse the list containing nn elements only once. Each look up in the table 
		//                          costs only O(1) time.
		//                        # Space complexity : O(n). The extra space required depends on the number of items stored in the hash table, 
		//                          which stores at most nn elements.                   
		static std::vector<int> two_sum_one_pass_hash(std::vector<int>& nums, int target)
		{
			std::unordered_map<int, int> h;
			for (int i = 0; i < nums.size(); ++i)
			{
				if (h.find(target - nums[i]) != h.end())
				{
					return std::vector<int>({ h[target - nums[i]], i});
				}

				h[nums[i]] = i;
			}

			return std::vector<int>({ 0, 0 });
		}

	};

}

#endif // !TWOSUM_H
