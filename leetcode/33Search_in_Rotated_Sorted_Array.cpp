/*!
* \Problem     LeetCode 33: Search in Rotated Sorted Array
* \Difficulty  Medium.
* \Brief       Suppose an array sorted in ascending order is 
*          rotated at some pivot unknown to you beforehand.
*          (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
*              You are given a target value to search. If found 
*          in the array return its index, otherwise return -1.
*              You may assume no duplicate exists in the array.
*              Your algorithm's runtime complexity must be in  
*          the order of O(log n).
* \Example   
*          Input: nums = [4,5,6,7,0,1,2], target = 0
*          Output: 4
*          Input: nums = [4,5,6,7,0,1,2], target = 3
*          Output: -1
*/

#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>& nums, int target) {
  if (nums.size() == 0)
    return -1;

  int left = 0;
  int right = nums.size() - 1;

  while (left < right) {
    int mid = (left + right) / 2;
    if (nums[mid] == target)
      return mid;

    if (nums[left] <= nums[mid]) {
      // pivot is in the right side.
      if (nums[mid] > target && nums[left] <= target)
        right = mid - 1;
      else
        left = mid + 1;
    }
    else {
      // pivot is in the left side.
      if (nums[mid] < target && nums[right] >= target)
        left = mid + 1;
      else
        right = mid - 1;
    }
  }
  if (nums[left] == target)
    return left;
  else
    return -1;
}

int main() {

  int num_arr[] = { 5,1,2 };
  vector<int> nums(num_arr, num_arr+3);

  int idx = search(nums, 2);
  printf("idx = %d.\n", idx);
  return 0;
}
