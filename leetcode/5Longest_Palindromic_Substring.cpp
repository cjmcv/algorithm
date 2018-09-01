/*!
* \Problem     LeetCode 5. Longest Palindromic Substring
* \Difficulty  Medium.
* \Brief       Given a string s, find the longest palindromic substring
*          in s. You may assume that the maximum length of s is 1000.
* \Example 
*          Input: "babad"
*          Output: "bab"
*          Note: "aba" is also a valid answer.
*
*          Input: "cbbd"
*          Output: "bb"
*/

#include <iostream>
#include <vector>

using namespace std;

string longestPalindrome(string s) {
  // Sliding window.
  // For each window size.
  for (int wi = s.length(); wi>0; wi--) {
    // For each sliding position.
    for (int hi = 0; hi < s.length() - wi + 1; hi++) {

      bool flag_sub = true;
      // Check the elements in a window.
      for (int i = hi, j = hi + wi - 1, c = 0;
        c < wi / 2;
        i++, j--, c++) {
        if (s[i] != s[j]) {
          flag_sub = false;
          break;
        }
      }
      if (flag_sub) {
        char *result = new char[wi + 1];
        for (int i = 0; i < wi; i++) {
          result[i] = s[i + hi];
        }
        result[wi] = '\0';
        string result_str = result;
        delete result;
        return result_str;
      }
    }
  }

  string result = "";
  return result;
}

int main() {
  while (1) {
    string input = "babad";
    string result = longestPalindrome(input);
    printf("result: %s\n", result.c_str());
  }

}
