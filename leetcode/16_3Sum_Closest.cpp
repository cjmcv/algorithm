/*!
* \Problem     LeetCode 16. 3Sum Closest
* \Difficulty  Medium.
* \Brief       Given an array nums of n integers and an integer target, find three 
*          integers in nums such that the sum is closest to target. Return the sum of 
*          the three integers. You may assume that each input would have exactly one 
*          solution.
*
* \Example
*          Given array nums = [-1, 2, 1, -4], and target = 1.
*          The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
  int closest = 0;
  if (nums.size() < 3) {
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
      sum += nums[i];
    return sum;
  }

  closest = nums[0] + nums[1] + nums[2];
  std::sort(nums.begin(), nums.end());
  
  // i ->                                             <Outer  loop>
  //    left_idx(i+1) ->         <- right_idx(size-1)  <Inner loop>
  // 0        1       2 3 4 5 6 7 8      9            (sorted array)
  for (int i = 0; i < nums.size(); i++) {
    int left_idx = i + 1;
    int right_idx = nums.size() - 1;
    while (left_idx < right_idx) {
      int sum = nums[i] + nums[left_idx] + nums[right_idx];
      if (abs(sum - target) < abs(closest - target)) {
        closest = sum;
      }
      if (sum > target)
        right_idx--;
      else if (sum < target)
        left_idx++;
      else
        return sum;
    }
  }
  return closest;
}

int main() {

  int arr[4] = { -1, 2, 1, -4 };
  vector<int> inputs(arr, arr+4);
  printf("output = %d\n", threeSumClosest(inputs, 1));
}
