/*!
* \Problem     LeetCode 20. Valid Parentheses.
* \Difficulty  Easy.
* \Brief       Given a string containing just the characters '(', ')', 
*          '{', '}', '[' and ']', determine if the input string is valid.
*              An input string is valid if:
*          1. Open brackets must be closed by the same type of brackets.
*          2. Open brackets must be closed in the correct order.
*          Note that an empty string is also considered valid.
* \Example   
*          Input: "()"
*          Output: true
*          Input: "()[]{}"
*          Output: true
*          Input: "(]"
*          Output: false
*          Input: "([)]"
*          Output: false
*          Input: "{[]}"
*          Output: true
*/

#include <iostream>
#include <vector>

using namespace std;

bool isValid(string s) {
  // Check the number first.
  if (s.length() % 2 != 0)
    return false;

  const char *c_str = s.c_str();
  // Use a stack for matching. Last in first out.
  vector<char> left_sign;
  for (int i = 0; i<s.length(); i++) {
    if (c_str[i] == '(' || c_str[i] == '{' || c_str[i] == '[')
      left_sign.push_back(c_str[i]);
    else {
      if (left_sign.size() == 0)
        return false;

      char left = left_sign[left_sign.size() - 1];
      char right = c_str[i];
      if ((left == '(' && right == ')') ||
        (left == '[' && right == ']') ||
        (left == '{' && right == '}')) {
        left_sign.pop_back();
      }
      else
        return false;
    }
  }
  if (left_sign.size() != 0)
    return false;
  return true;
}

int main() {
  string input = "([)]";//{[]}
  printf("Output: %d.\n", isValid(input));
}
