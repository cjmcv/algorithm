/*!
* \Problem     LeetCode 3 Longest Substring Without Repeating Characters
* \Difficulty  Medium.
* \Brief       Given a string, find the length of the longest substring
*          without repeating characters.
* \Example 
*          Input: "abcabcbb"
*          Output: 3 
*          Explanation: The answer is "abc", which the length is 3.
*
*          Input: "bbbbb"
*          Output: 1
*          Explanation: The answer is "b", with the length of 1.
*
*          Input: "pwwkew"
*          Output: 3
*          Explanation: The answer is "wke", with the length of 3. 
*            Note that the answer must be a substring, "pwke" is a 
*            subsequence and not a substring.
*/

#include <iostream>
#include <vector>

using namespace std;

int lengthOfLongestSubstring(string s) {

  int result_len = 0;
  char *container = new char[s.length()];
  // 
  for (int idx = 0; idx < s.length(); idx++) {
    int cid = 0;
    container[cid] = s[idx];

    for (int i = idx + 1; i < s.length(); i++) {
      bool flag = false;
      for (int c = 0; c < cid + 1; c++) {
        if (container[c] == s[i]) {
          flag = true;
          break;
        }
      }
      if (!flag) {
        cid++;
        container[cid] = s[i];
      }
      else
        break;
    }
    if (result_len < cid + 1) {
      result_len = cid + 1;
    }
  }
  delete[] container;
  return result_len;
}

int main() {
  string input = "abcabcbb";
  int ret = lengthOfLongestSubstring(input);
  printf("result: %d\n", ret);
}
