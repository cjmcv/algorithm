/*!
* \Problem     LeetCode 17: Letter Combinations of a Phone Number.
* \Difficulty  Medium.
* \Brief       Given a string containing digits from 2-9 inclusive, 
*          return all possible letter combinations that the number 
*          could represent. A mapping of digit to letters (just 
*          like on the telephone buttons) is given below. Note that
*          1 does not map to any letters.
* \Example   
*          Input: "23"
*          Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*/

#include <iostream>
#include <vector>

using namespace std;

vector<string> letterCombinations(string digits) {
  vector<string> result;
  if (digits.empty()) return result;

  vector<string> mapping = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
  result.push_back("");

  const char *c_digits = digits.c_str();
  for (int i = 0; i < digits.size(); i++) {
    if (mapping[c_digits[i] - '0'].empty()) continue;
    
    vector<string> temp;
    const char *c_map = mapping[c_digits[i] - '0'].c_str();

    // Each to the next number will update the previous strings, 
    // superimposing the old strings according to all characters 
    // in the mapping table corresponding to the current number.
    for (int si = 0; si < result.size(); si++) {
      for (int ci = 0; ci < mapping[c_digits[i] - '0'].length(); ci++) {
        temp.push_back(result[si] + c_map[ci]);
      }
    }

    result = temp;
  }

  return result;
}

int main() {
  string input = "23";

  vector<string> result = letterCombinations(input);

  for (int i = 0; i < result.size(); i++) {
    printf("%s, ", result[i].c_str());
  }
}
