/*!
* \Problem     LeetCode 7. Reverse Integer
* \Difficulty  Easy.
* \Brief       Given a 32-bit signed integer, reverse digits of an integer.
* \Example 
*          Input: 123
*          Output: 321
*
*          Input: -123
*          Output: -321
*
*          Input: 120
*          Output: 21
*/

#include <iostream>
#include <vector>

using namespace std;

int reverse(int x) {

  int result = 0;
  while (x) {
    int t = x % 10;
    if ((result > INT_MAX / 10) || (result == INT_MAX / 10 && t > 7)) return 0;
    if ((result < INT_MIN / 10) || (result == INT_MIN / 10 && t < -8)) return 0;
    result = result * 10 + t;
    x /= 10;
  }

  return result;
}

int main() {

  int input = -123;
  int output = reverse(input);
  printf("%d -> %d\n", input, output);

  input = 90123;
  output = reverse(input);
  printf("%d -> %d\n", input, output);
}
