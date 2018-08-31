/*!
* \Problem     LeetCode 1: Two Sum.
* \Difficulty  Easy.
* \Brief       Given an array of integers, return indices of the 
*          two numbers such that they add up to a specific target.
*          You may assume that each input would have exactly one 
*          solution, and you may not use the same element twice.
* \Example   
*          Input: nums = [2, 7, 11, 15], target = 9,
*          Output: return [0, 1]. Because nums[0] + nums[1] = 2 + 7 = 9,
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
	vector<int> result;
	for (int i = 0; i<nums.size(); i++) {
		for (int j = 1; j<nums.size(); j++) {
			if (i == j)
				continue;
			if (target == nums[i] + nums[j]) {
				result.push_back(i);
				result.push_back(j);
				return result;
			}
		}
	}
  return result;
}

int main() {
	int input[4] = {2, 7, 11, 15};
  vector<int> input_vec(input, input + 4);

  vector<int> result = twoSum(input_vec, 9);

  for (int i = 0; i < result.size(); i++) {
    printf("%d, ", result[i]);
  }
}
