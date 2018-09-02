/*!
* \Problem     LeetCode 11. Container With Most Water
* \Difficulty  Medium.
* \Brief       Given n non-negative integers a1, a2, ..., an ,
*          where each represents a point at coordinate (i, ai). 
*          n vertical lines are drawn such that the two endpoints 
*          of line i is at (i, ai) and (i, 0). Find two lines, 
*          which together with x-axis forms a container, such that
*          the container contains the most water.
*          Note: You may not slant the container and n is at least 2.
* \Example 
*          Input: [1,8,6,2,5,4,8,3,7]
*          Output: 49
*          Explaination: Select the indexs one and eight, then the shorter one is 7,
*               and the length between one and nine is 7 too. So the output = 7 x 7.
*/

#include <iostream>
#include <vector>

using namespace std;

int maxArea(vector<int>& height) {
  int max_global = 0;
  for (int i = 0; i<height.size() - 1; i++) {
    int max_sub = 0;
    for (int j = i + 1; j<height.size(); j++) {
      int sum = 0;
      int shorter = (height[j] > height[i]) ? height[i] : height[j];

      sum = shorter * (j - i);

      if (max_sub < sum)
        max_sub = sum;
    }
    if (max_global < max_sub)
      max_global = max_sub;
  }

  return max_global;
}

int main() {

  int container[9] = { 1,8,6,2,5,4,8,3,7 };
  vector<int> input(container, container+9);

  int output = maxArea(input);
  printf("output = %d\n", output);
}
