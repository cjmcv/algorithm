/*!
* \Problem     LeetCode 34: Find First and Last Position of Element 
*          in Sorted Array.
* \Difficulty  Medium.
* \Brief       Given an array of integers nums sorted in 
*          ascending order, find the starting and ending 
*          position of a given target value.
*              Your algorithm's runtime complexity must 
*          be in the order of O(log n).
*              If the target is not found in the array, 
*          return [-1, -1].
* \Example   
*          Input:  nums = [5,7,7,8,8,10], target = 8
*          Output: [3,4]
*          Input:  nums = [5,7,7,8,8,10], target = 6
*          Output: [-1,-1]
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
  
  vector<int> result;
  // For the case that the array is empty.
  if (nums.size() == 0) {
    result.push_back(-1);
    result.push_back(-1);
    return result;
  }

  // Binary search.
  int left = 0;
  int right = nums.size()-1;
  int mid = (left + right) / 2;

  int base_idx = -1;
  while (left < right) {
    mid = (left + right) / 2;
    if (target == nums[mid]) {
      base_idx = mid;
      break;
    }

    if (target > nums[mid])
      left = mid + 1;
    else
      right = mid - 1;
  }

  if (base_idx == -1) {
    if (nums[left] == target)
      base_idx = left;
    else {
      result.push_back(-1);
      result.push_back(-1);
      return result;
    }
  }

  // Spread out. (n) 
  //   Or you can use Binary search again to find 
  // the First and Last Position. log(n)
  int li = base_idx;
  int ri = base_idx;
  while (li >= 0 && nums[li] == nums[base_idx])
    li--;
  while (ri < nums.size() && nums[ri] == nums[base_idx])
    ri++;

  result.push_back(++li);
  result.push_back(--ri);

  return result;
}

int main() {

  int num_arr[] = { 0 };
  vector<int> nums(num_arr, num_arr);

  vector<int> idxs = searchRange(nums, 0);
  printf("idx = (%d, %d).\n", idxs[0], idxs[1]);
  return 0;
}
