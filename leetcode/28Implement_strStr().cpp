/*!
* \Problem     LeetCode 28: Implement strStr()
* \Difficulty  Easy.
* \Brief       Return the index of the first occurrence of 
*　　　　　needle in haystack, or -1 if needle is not part
*          of haystack.
* \Example   
*          Input: haystack = "hello", needle = "ll"
*          Output: 2
*          Input: haystack = "aaaaa", needle = "bba"
*          Output: -1
*/

#include <iostream>
#include <vector>

using namespace std;


int strStr(string haystack, string needle) {

  if (needle.length() == 0)
    return 0;

  const char *haystack_cstr = haystack.c_str();
  const char *needle_cstr = needle.c_str();

  for (int i = 0; i < haystack.length(); i++) {
    if (haystack_cstr[i] == needle_cstr[0]) {
      bool flag = true;
      for (int j = 1; j < needle.length(); j++) {
        if (haystack_cstr[i + j] != needle_cstr[j]) {
          flag = false;
          break;
        }
      }
      if (flag)
        return i;
    }
  }
  return -1;
}

int main() {

  string haystack = "132";
  string needle = "";

  int idx = strStr(haystack, needle);
  printf("idx = %d.\n", idx);
  return 0;
}
