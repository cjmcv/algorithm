/*!
* \Problem     LeetCode 26: Remove Duplicates from Sorted Array
* \Difficulty  Easy.
* \Brief       Given a sorted array nums, remove the duplicates 
*          in-place such that each element appear only once and 
*          return the new length. Do not allocate extra space for 
*          another array, you must do this by modifying the input
*          array in-place with O(1) extra memory.
* \Example   
*          Given nums = [0,0,1,1,1,2,2,3,3,4].
*          Return length = 5, [0,1,2,3,4]
*/

#include <iostream>
#include <vector>

using namespace std;


int removeDuplicates(vector<int>& nums) {
  if (nums.size() <= 1) {
    return nums.size();
  }

  // Two pointers.
  int i=0, j=1;
  while (j < nums.size()) {
    if (i == j - 1) {
      if (nums[i] != nums[j]) {
        i++;
      }
    }
    else {
      if (nums[i] != nums[j]) {
        i++;
        nums[i] = nums[j];
      }
    }
    j++;
  }

  int interval = j - i - 1;
  while (interval--)
    nums.pop_back();

  return nums.size();
}

int main() {

  vector<int> nums;
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(1);
  //nums.push_back(2);
  //nums.push_back(2);
  //nums.push_back(3);
  //nums.push_back(3);
  //nums.push_back(3);
  //nums.push_back(6);
  //nums.push_back(6);

  int len = removeDuplicates(nums);
  printf("len = %d.\n", len);

  for (int i = 0; i < nums.size(); i++) {
    std::cout << nums[i] << ", ";
  }

}
