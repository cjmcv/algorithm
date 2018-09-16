/*!
* \Problem     LeetCode 14. Longest Common Prefix
* \Difficulty  Easy.
* \Brief       Write a function to find the longest common prefix string amongst an array of strings.
*           If there is no common prefix, return an empty string "".
*
* \Example
*          Input: ["flower","flow","flight"]
*          Output: "fl"
*
*          Input: ["dog","racecar","car"]
*          Output: ""
*          Explanation: There is no common prefix among the input strings.
*/

#include <iostream>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
  if (strs.size() <= 0)
    return "";
  if (strs.size() == 1)
    return strs[0];

  int min_idx = -1;
  int min_len = INT_MAX;
  // Find the shortest of all strings.
  for (int i = 0; i<strs.size(); i++) {
    if (min_len > strs[i].length()) {
      min_len = strs[i].length();
      min_idx = i;
    }
  }
  if (min_len == 0)
    return "";

  string prefix = strs[min_idx];
  for (int i = 0; i<min_len; i++) {
    // Search all strings.
    for (int j = 0; j<strs.size(); j++) {
      if (min_idx == j) // Ignore itself.
        continue;
      if (i == strs[j].length() || prefix.c_str()[i] != strs[j].c_str()[i])
        return prefix.substr(0, i);
    }
  }
  return prefix;
}

int main() {

  vector<string> inputs;
  inputs.push_back("flower");
  inputs.push_back("flow");
  inputs.push_back("flight");

  printf("output = %s\n", longestCommonPrefix(inputs).c_str());
}
